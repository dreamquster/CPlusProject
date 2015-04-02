#include "gtest/gtest.h"
#include "common.h"
#include "KSMarketDataOp.h"
using namespace log4cplus::helpers;
using namespace ctp;
namespace ctp {
	extern Logger logger;
	extern Logger dataLogger;
}

class KSMySQLOpTest:public ::testing::Test {
    protected:
        KSMySQLOpTest() {
            LogLog::getLogLog()->setInternalDebugging(true);
            PropertyConfigurator::doConfigure("log4cplus.properties");
            logger = Logger::getRoot();
            dataLogger = Logger::getInstance("data");
            KSMarketDataConf conf("ksmd.properties");
            _ksmarketdata_op = new KSMarketDataOp(&conf);
        }

        virtual ~KSMySQLOpTest() {

        }

        virtual void SetUp() {

        }

        virtual void TearDown() {

        }

        KSMarketDataOp* _ksmarketdata_op;
};

TEST_F(KSMySQLOpTest, insert) {
    MarketData marketData;
    strcpy(marketData.TradingDay, "2015-3-25");
    strcpy(marketData.InstrumentID, "IF3405");
    strcpy(marketData.ExchangeID, "testID");
    strcpy(marketData.ExchangeInstID, "renren");
    marketData.LastPrice = 75.5;
    marketData.PreSettlementPrice = 56.3;
    marketData.PreClosePrice = 60.7;
    marketData.PreOpenInterest = 33.3;
    marketData.OpenPrice = 88.8;
    marketData.HighestPrice = 112.3;
    marketData.LowerLimitPrice = 0.14;
    marketData.Volume = 1000;
    marketData.Turnover = 5.6;
    marketData.OpenInterest = 11.2;
    marketData.ClosePrice = 33.2;
    marketData.SettlementPrice = 35.7;
    marketData.UpperLimitPrice = 150.0;
    marketData.LowerLimitPrice = 0.0;
    marketData.PreDelta = 0.43;
    marketData.CurrDelta = 1.32;
    strcpy(marketData.UpdateTime,"2015-3-27");
    marketData.UpdateMillisec = 1237632;
    strcpy(marketData.ActionDay, "2015-3-26");

    _ksmarketdata_op->insert(&marketData);

}
