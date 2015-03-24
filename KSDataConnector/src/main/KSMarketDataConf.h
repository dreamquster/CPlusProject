#ifndef CTP_KS_MARKET_DATA_CONF_H
#define CTP_KS_MARKET_DATA_CONF_H

#include <string>
#include <vector>

using namespace std;

namespace ctp 
{
class KSMarketDataConf
{

public:
	string frontAddr;
	string brokerID;
	string userID;
	string password;
	vector<string> instruments;
	
	string dbAddr;
	string dbUserID;
	string dbPassword;
	string dbSchema;
	string dbTable;
public:
	KSMarketDataConf(const char *confPath);
};
}

#endif