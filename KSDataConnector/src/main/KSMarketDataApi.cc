#include "KSMarketDataApi.h"
#include <log4cplus/loggingmacros.h>

namespace ctp {

using namespace log4cplus;
extern Logger logger;

KSMarketDataApi::KSMarketDataApi(KSMarketDataConf *ksMdConf): 
		_ksMdConf(ksMdConf), _state(0)
{
	_reqidSeed = new IDGenerator();
	_sync = event_create(true, false);
}

KSMarketDataApi::~KSMarketDataApi()
{
	if (_state == 1) {
		this->Release();
	}
	delete _reqidSeed;
}

void KSMarketDataApi::Init()
{
	if (_state != 0)
		return;
	
	_ctpApi = CThostFtdcMdApi::CreateFtdcMdApi();
	_ksMdSpi = new KSMarketDataSpi(_ksMdConf, _ctpApi, _reqidSeed, _sync);
	_ctpApi->RegisterSpi(_ksMdSpi);
	_ctpApi->RegisterFront(const_cast<char*>(_ksMdConf->frontAddr.c_str()));

	LOG4CPLUS_INFO(logger, "Init: waiting for connect and login");	
	_ctpApi->Init();
	event_wait(_sync);
	LOG4CPLUS_INFO(logger, "Service is ready");	
	
	_state = 1;
	event_reset(_sync);
}

void KSMarketDataApi::Release()
{
	// logout
	CThostFtdcUserLogoutField UserLogout;
    bzero(&UserLogout, sizeof(UserLogout));
	strcpy(UserLogout.BrokerID, _ksMdConf->brokerID.c_str());
	strcpy(UserLogout.UserID, _ksMdConf->userID.c_str());
	
	LOG4CPLUS_INFO(logger, "Release: waiting for logout");	
    _ctpApi->ReqUserLogout(&UserLogout, _reqidSeed->NextID());
	event_wait(_sync);
	LOG4CPLUS_INFO(logger, "Service is exiting");	
    // waiting for quit event
    //WaitForSingleObject(pSpi[i]->m_hEvent, 3000/*INFINITE*/);
	//event_timedwait(_monitor, 3000/*INFINITE*/); 
	_ctpApi->Release();
	_state = 0;	
}

}