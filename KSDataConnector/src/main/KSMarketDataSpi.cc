#include "KSMarketDataSpi.h"
#include<iomanip>
#include <log4cplus/loggingmacros.h>

namespace ctp {

using namespace std;
using namespace KingstarAPI;
using namespace log4cplus;

extern Logger logger;
extern Logger dataLogger;

const int CHTEXT_BUF_SIZE = 100;

KSMarketDataSpi::KSMarketDataSpi(KSMarketDataConf *ksMdConf, CThostFtdcMdApi *ctpApi, IDGenerator *reqidSeed, event_handle sync):
		_ksMdConf(ksMdConf), _ctpApi(ctpApi), _reqidSeed(reqidSeed), _sync(sync)
{
	_dataOp = new KSMarketDataOp(ksMdConf);
}

KSMarketDataSpi::~KSMarketDataSpi() {
	delete _dataOp;
}

// After making a succeed connection with the CTP server,
// the client should send the login request to the CTP server.
void KSMarketDataSpi::OnFrontConnected()
{
	LOG4CPLUS_INFO(logger, "OnFrontConnected:");

	CThostFtdcReqUserLoginField reqUserLogin;
	bzero(&reqUserLogin, sizeof(reqUserLogin));
	strcpy(reqUserLogin.BrokerID, _ksMdConf->brokerID.c_str());
	strcpy(reqUserLogin.UserID, _ksMdConf->userID.c_str());
	strcpy(reqUserLogin.Password, _ksMdConf->password.c_str());

	// send the login request
	int reqID = _reqidSeed->NextID();
	LOG4CPLUS_INFO(logger, "DoReqUserLogin: reqID=" << reqID);
	_ctpApi->ReqUserLogin(&reqUserLogin, reqID);

}

// When the connection between client and the CTP server disconnected,
// the follwing function will be called.
void KSMarketDataSpi::OnFrontDisconnected(int nReason)
{
	// In this case, API will reconnect, the client application can ignore this.
	LOG4CPLUS_INFO(logger, "OnFrontDisconnected: nReason=" << nReason);
}

// After receiving the login request from the client,
// the CTP server will send the following response to notify the client whether the login success or not.
void KSMarketDataSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	LOG4CPLUS_INFO(logger, "OnRspUserLogin: reqID=" << nRequestID << ", isLast=" << bIsLast);

	char chTextBuf[CHTEXT_BUF_SIZE] = {0}; // 中文符串
	if (pRspInfo->ErrorID != 0) {
		LOG4CPLUS_ERROR(logger, "RspInfo: " << pRspInfo->ErrorID << "|"
                        << boost::locale::conv::to_utf<char>(string(pRspInfo->ErrorMsg), "GBK"));
		return;
	}
	// bzero(chTextBuf, CHTEXT_BUF_SIZE);
    string strSystemName = boost::locale::conv::to_utf<char>(string(pRspUserLogin->SystemName), "GBK");
	LOG4CPLUS_INFO(logger, "RspUserLogin: " << pRspUserLogin->TradingDay << "|" << pRspUserLogin->LoginTime << "|"
			<< pRspUserLogin->BrokerID  << "|" << pRspUserLogin->UserID << "|" <<  strSystemName << "|"
			<< pRspUserLogin->FrontID << "|" << pRspUserLogin->SessionID << "|" << pRspUserLogin->MaxOrderRef << "|"
			<< pRspUserLogin->SHFETime << "|" << pRspUserLogin->DCETime << "|" << pRspUserLogin->CZCETime << "|"
			<< pRspUserLogin->FFEXTime << "|" << pRspUserLogin->INETime);


	// get trading day
	//printf("当前交易日=%s\n", _ctpApi->GetTradingDay());

	// 行情订阅列表
	size_t instrCount = _ksMdConf->instruments.size();
	char **ppInstrIDs = new char * [instrCount];
	for (int i = 0; i < instrCount; i++) {
		ppInstrIDs[i] = new char[_ksMdConf->instruments[i].length() + 1];
		strcpy (ppInstrIDs[i], _ksMdConf->instruments[i].c_str());
	}

	// 	订阅
	LOG4CPLUS_INFO(logger, "DoSubscribeMarketData");
	_ctpApi->SubscribeMarketData(ppInstrIDs, instrCount);
	// 释放内存
	for (int i = 0; i < instrCount; i++) {
		delete[] ppInstrIDs[i];
	}
	delete[] ppInstrIDs;
}

// logout return
void KSMarketDataSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	LOG4CPLUS_INFO(logger, "OnRspUserLogout: reqID=" << nRequestID << ", isLast=" << bIsLast);
	char chTextBuf[CHTEXT_BUF_SIZE] = {0}; // 中文符串
	if (pRspInfo->ErrorID != 0) {
		LOG4CPLUS_ERROR(logger, "RspInfo: " << pRspInfo->ErrorID << "|"
                        << boost::locale::conv::to_utf<char>(string(pRspInfo->ErrorMsg), "GBK"));
		// return;
	}
	event_set(_sync);	// 释放退出锁
}

///RspSubMarketData return
void KSMarketDataSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	LOG4CPLUS_INFO(logger, "OnRspSubMarketData: reqID=" << nRequestID << ", isLast=" << bIsLast);
	char chTextBuf[CHTEXT_BUF_SIZE] = {0}; // 中文符串
	if (pRspInfo->ErrorID != 0) {
		LOG4CPLUS_ERROR(logger, "RspInfo: " << pRspInfo->ErrorID << "|"
                << boost::locale::conv::to_utf<char>(string(pRspInfo->ErrorMsg),"GBK"));
		// return;
	}
	LOG4CPLUS_INFO(logger, "SpecificInstrument: " << pSpecificInstrument->InstrumentID);
	event_set(_sync); // 释放启动锁
}

///OnRspUnSubMarketData return
void KSMarketDataSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	LOG4CPLUS_INFO(logger, "OnRspUnSubMarketData: reqID=" << nRequestID << ", isLast=" << bIsLast);
	char chTextBuf[CHTEXT_BUF_SIZE] = {0}; // 中文符串
	if (pRspInfo->ErrorID != 0) {
		LOG4CPLUS_ERROR(logger, "RspInfo: " << pRspInfo->ErrorID << "|"
                << boost::locale::conv::to_utf<char>(string(pRspInfo->ErrorMsg), "GBK"));
		// return;
	}
	LOG4CPLUS_INFO(logger, "SpecificInstrument: " << pSpecificInstrument->InstrumentID);
}

///OnRtnDepthMarketData
void KSMarketDataSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	pDepthMarketData->SettlementPrice = 0;
	LOG4CPLUS_DEBUG(logger, "OnRtnDepthMarketData:" << pDepthMarketData->TradingDay << "|" << pDepthMarketData->InstrumentID << "|"
			<< pDepthMarketData->ExchangeID << "|" << pDepthMarketData->ExchangeInstID << "|"
			<< fixed << setprecision(4)
			<< pDepthMarketData->LastPrice << "|" << pDepthMarketData->PreSettlementPrice << "|" << pDepthMarketData->PreClosePrice << "|"
			<< pDepthMarketData->PreOpenInterest << "|" << pDepthMarketData->OpenPrice << "|" << pDepthMarketData->HighestPrice << "|"
			<< pDepthMarketData->LowestPrice << "|" << pDepthMarketData->Volume << "|" << pDepthMarketData->Turnover << "|"
			<< pDepthMarketData->OpenInterest << "|" << pDepthMarketData->ClosePrice << "|" << pDepthMarketData->SettlementPrice << "|"
			<< pDepthMarketData->UpperLimitPrice << "|" << pDepthMarketData->LowerLimitPrice << "|" << pDepthMarketData->PreDelta << "|"
			<< pDepthMarketData->CurrDelta << "|" << pDepthMarketData->UpdateTime << "|" << pDepthMarketData->UpdateMillisec << "|"
			<< pDepthMarketData->ActionDay);

	unsigned long dbID = _dataOp->insert(pDepthMarketData);
	LOG4CPLUS_INFO(dataLogger, dbID << "|" << pDepthMarketData->TradingDay << "|" << pDepthMarketData->InstrumentID << "|"
		<< pDepthMarketData->ExchangeID << "|" << pDepthMarketData->ExchangeInstID << "|"
		<< fixed << setprecision(4)
		<< pDepthMarketData->LastPrice << "|" << pDepthMarketData->PreSettlementPrice << "|" << pDepthMarketData->PreClosePrice << "|"
		<< pDepthMarketData->PreOpenInterest << "|" << pDepthMarketData->OpenPrice << "|" << pDepthMarketData->HighestPrice << "|"
		<< pDepthMarketData->LowestPrice << "|" << pDepthMarketData->Volume << "|" << pDepthMarketData->Turnover << "|"
		<< pDepthMarketData->OpenInterest << "|" << pDepthMarketData->ClosePrice << "|" << pDepthMarketData->SettlementPrice << "|"
		<< pDepthMarketData->UpperLimitPrice << "|" << pDepthMarketData->LowerLimitPrice << "|" << pDepthMarketData->PreDelta << "|"
		<< pDepthMarketData->CurrDelta << "|" << pDepthMarketData->UpdateTime << "|" << pDepthMarketData->UpdateMillisec << "|"
		<< pDepthMarketData->ActionDay);

}

}//ns
