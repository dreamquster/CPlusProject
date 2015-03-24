#ifndef CTP_KS_MARKET_DATA_API_H
#define CTP_KS_MARKET_DATA_API_H

#include "common.h"
#include "KSMarketDataConf.h"
#include "KSMarketDataSpi.h"
#include "IDGenerator.h"
#include "event.h"

namespace ctp {

using namespace std;
using namespace KingstarAPI;
using namespace ctp;

class KSMarketDataApi
{
public:
	KSMarketDataApi(KSMarketDataConf *conf);
	~KSMarketDataApi();
	void Init();
	void Release();
private:
	KSMarketDataConf *_ksMdConf;
	CThostFtdcMdApi *_ctpApi;
	KSMarketDataSpi *_ksMdSpi;
	IDGenerator *_reqidSeed;
	event_handle _sync;
	int _state;
};

}

#endif
