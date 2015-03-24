#include "gtest/gtest.h"
#include "KSMarketDataOp.h"
using namespace ctp;
class KSMySQLOpTest:public ::testing::Test {
    protected:
        KSMySQLOpTest() {
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

}
