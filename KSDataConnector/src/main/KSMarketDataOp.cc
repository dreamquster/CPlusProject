#include "KSMarketDataOp.h"

#include <log4cplus/loggingmacros.h>
#include <cppconn/resultset.h>

namespace ctp
{

using namespace std;
using namespace log4cplus;

extern Logger logger;

const sql::SQLString sqlGetLastInsertID = "SELECT LAST_INSERT_ID()";

inline unsigned long get_last_insert_id(sql::Statement *stmt)
{
	sql::ResultSet *res = stmt->executeQuery(sqlGetLastInsertID);
	if (res->next())  
        return res->getUInt64(1); 
	return 0;
}

KSMarketDataOp::KSMarketDataOp(KSMarketDataConf *conf): _conf(conf)
{
	try {
		/* Create a connection */
		_driver = get_driver_instance();
		_conn = _driver->connect(conf->dbAddr, conf->dbUserID, conf->dbPassword);
		/* Connect to the MySQL test database */
		_conn->setSchema(conf->dbSchema);
		_stmt = _conn->createStatement();
		// cout << sqlInsertMarketData << endl;
		sql::SQLString pstmtSQL = "INSERT INTO " + conf->dbTable + " (trading_day, instrument_id, exchange_id, exchange_inst_id, "
		"last_price, pre_settlement_price, pre_close_price, pre_open_interest, open_price, highest_price, lowest_price, "
		"volume, turnover, open_interest, close_price, settlement_price, upper_limit_price, lower_limit_price, "
		"pre_delta, curr_delta, update_time, update_millisec, action_day, create_time) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, now())";
		_pstmt = _conn->prepareStatement(pstmtSQL);
	} catch (sql::SQLException &e) {
		LOG4CPLUS_ERROR(logger, "Error: SQLException in " << __FILE__ << "(" << __FUNCTION__ << ") on line " << __LINE__ << ", "
				<< e.what() << " (MySQL error code: " << e.getErrorCode() << ", SQLState: " << e.getSQLState() << " )");	
		throw e;
	}
}


KSMarketDataOp::~KSMarketDataOp()
{
	delete _stmt;
	delete _pstmt;
	delete _conn;
}

unsigned long KSMarketDataOp::insert(MarketData *pData)
{
	_pstmt->clearParameters();
	_pstmt->setString(1, pData->TradingDay);
	_pstmt->setString(2, pData->InstrumentID);
	_pstmt->setString(3, pData->ExchangeID);
	_pstmt->setString(4, pData->ExchangeInstID);
	_pstmt->setDouble(5, pData->LastPrice);
	_pstmt->setDouble(6, pData->PreSettlementPrice);
	_pstmt->setDouble(7, pData->PreClosePrice);
	_pstmt->setDouble(8, pData->PreOpenInterest);
	_pstmt->setDouble(9, pData->OpenPrice);
	_pstmt->setDouble(10, pData->HighestPrice);
	_pstmt->setDouble(11, pData->LowestPrice);
	_pstmt->setInt(12, pData->Volume);
	_pstmt->setDouble(13, pData->Turnover);
	_pstmt->setDouble(14, pData->OpenInterest);
	_pstmt->setDouble(15, pData->ClosePrice);
	_pstmt->setDouble(16, pData->SettlementPrice);
	_pstmt->setDouble(17, pData->UpperLimitPrice);
	_pstmt->setDouble(18, pData->LowerLimitPrice);
	_pstmt->setDouble(19, pData->PreDelta);
	_pstmt->setDouble(20, pData->CurrDelta);	
	_pstmt->setString(21, pData->UpdateTime);
	_pstmt->setInt(22, pData->UpdateMillisec);
	_pstmt->setString(23, pData->ActionDay);

	try {
		int result = _pstmt->executeUpdate();
		unsigned long newid = 0;
		if (result > 0) {
			newid = get_last_insert_id(_stmt);
		}
		return newid;
		
	} catch (sql::SQLException &e) {
		LOG4CPLUS_ERROR(logger, "Error: SQLException in " << __FILE__ << "(" << __FUNCTION__ << ") on line " << __LINE__ << ", "
				<< e.what() << " (MySQL error code: " << e.getErrorCode() << ", SQLState: " << e.getSQLState() << " )");
	}
	return 0;
}

}