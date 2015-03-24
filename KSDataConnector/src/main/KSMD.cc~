#include <cstdio>

#include "KSMarketDataApi.h"
#include "KSMarketDataConf.h"
#include "event.h"

#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <csignal>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace ctp;
namespace ctp {
	extern Logger logger;
	extern Logger dataLogger;
}

static event_handle bar;

void signal_handler(int sig)
{
	LOG4CPLUS_INFO(logger, "Receive exit signal " << sig);
	event_set(bar);
}

int main()
{
	// sig handle
	bar = event_create(true, false);
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	// init loggers
	LogLog::getLogLog()->setInternalDebugging(true);
	PropertyConfigurator::doConfigure("log4cplus.properties");
	logger = Logger::getRoot();
	dataLogger = Logger::getInstance("data");
	
	LOG4CPLUS_INFO(logger, "Start application");	
	LOG4CPLUS_INFO(logger, "Loading KSMarketDataConf");	
	// load ctp conf
	KSMarketDataConf *conf = new KSMarketDataConf("ksmd.properties");
	// print ctp confs
	LOG4CPLUS_INFO(logger, "CtpFrontAddress=" << conf->frontAddr);
	LOG4CPLUS_INFO(logger, "CtpBrokerID=" << conf->brokerID);
	LOG4CPLUS_INFO(logger, "CtpUserID=" << conf->userID);
	LOG4CPLUS_INFO(logger, "CtpPassword=" << conf->password);
	string strInstr;
	for (int i=0; i<conf->instruments.size(); i++)
	{
		if (i > 0)
			strInstr += ",";
		strInstr += conf->instruments[i];
	}	
	LOG4CPLUS_INFO(logger, "CtpInstruments=" << strInstr);
	// print db confs
	LOG4CPLUS_INFO(logger, "DbAddress=" << conf->dbAddr);
	LOG4CPLUS_INFO(logger, "DbUserID=" << conf->dbUserID);
	LOG4CPLUS_INFO(logger, "DbPassword=" << conf->dbPassword);
	LOG4CPLUS_INFO(logger, "DbSchema=" << conf->dbSchema);
	LOG4CPLUS_INFO(logger, "DbTable=" << conf->dbTable);
	
	KSMarketDataApi *ksMdApi = new KSMarketDataApi(conf);
	
	//cout << "print enter to start" << endl;
	//getchar();
	ksMdApi->Init();
	event_wait(bar);
	//cout << "print enter to quit" << endl;
	//getchar();
	ksMdApi->Release();
	
	
	delete ksMdApi;
	delete conf;
	
	LOG4CPLUS_INFO(logger, "Exit application");
	return 0;
}

