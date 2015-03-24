#ifndef CTP_KS_MARKET_DATA_OP_H
#define CTP_KS_MARKET_DATA_OP_H

#include "KSMarketDataAPI/KSMarketDataAPI.h"
#include "KSMarketDataConf.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>




namespace ctp
{

using namespace KingstarAPI;
typedef CThostFtdcDepthMarketDataField MarketData;

class KSMarketDataOp
{
public:
	KSMarketDataOp(KSMarketDataConf *conf);
	~KSMarketDataOp();
	unsigned long insert(MarketData *pData);

private:
	KSMarketDataConf *_conf;
	sql::Driver *_driver;
	sql::Connection *_conn;
	sql::Statement *_stmt;
	sql::PreparedStatement *_pstmt;
};

}

#endif
