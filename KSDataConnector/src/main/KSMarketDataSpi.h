#ifndef CTP_KS_MARKET_DATA_SPI_H
#define CTP_KS_MARKET_DATA_SPI_H

#include "common.h"
#include "KSMarketDataAPI/KSMarketDataAPI.h"
#include "KSMarketDataConf.h"
#include "KSMarketDataOp.h"
#include "IDGenerator.h"
#include "event.h"

namespace ctp {

using namespace KingstarAPI;

class KSMarketDataSpi: public CThostFtdcMdSpi
{
public:
	KSMarketDataSpi(KSMarketDataConf *ksMdConf, CThostFtdcMdApi *ctpApi, IDGenerator *reqidSeed, event_handle sync);
	~KSMarketDataSpi();
public:
	void OnFrontConnected();
	void OnFrontDisconnected(int nReason);
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
			CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout,
			CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
			CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
			CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
private:
	KSMarketDataConf *_ksMdConf;
	CThostFtdcMdApi *_ctpApi;
	IDGenerator *_reqidSeed;
	event_handle _sync;
	KSMarketDataOp *_dataOp;
};

}

#endif
