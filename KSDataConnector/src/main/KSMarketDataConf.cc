#include "KSMarketDataConf.h"
#include <iostream>
#include <fstream>
#include <cstring>

namespace ctp
{
	
inline void split(const string str, const string delimiter, vector<string>& tokens)
{
	char *token = NULL;
	char *buffer = NULL;
	token = strtok_r(const_cast<char*>(str.c_str()), delimiter.c_str(), &buffer);
	if (token != NULL)
	{
		tokens.push_back(string(token));
	}
	while (token = strtok_r(NULL, delimiter.c_str(), &buffer))
	{
		tokens.push_back(string(token));
	}
}

inline bool iscomment(const string& str)
{
	return !str.empty() && str[0] == '#';
}

KSMarketDataConf::KSMarketDataConf(const char *confPath)
{
	using namespace std;
	
	ifstream fin(confPath);
	if (!fin) {
		cout << "Configuration file [" << confPath << "] is missing!" << endl;
		return;
	}
			
	string line;
	vector<string> tokens;
	while (fin >> line) {
		//cout << line << endl;
		if (!iscomment(line) && !line.empty()) 
		{
			split(line, "=", tokens);
			if (tokens.size() == 2)
			{
				if (tokens[0] == "front_address" && frontAddr.empty())
					frontAddr = tokens[1];
				else if (tokens[0] == "broker_id" && brokerID.empty())
					brokerID = tokens[1];
				else if (tokens[0] == "user_id" && userID.empty())
					userID = tokens[1];
				else if (tokens[0] == "password" && password.empty())
					password = tokens[1];
				else if (tokens[0] == "instruments" && instruments.empty())
					split(tokens[1], ",", instruments);
				else if (tokens[0] == "db_address" && dbAddr.empty())
					dbAddr = tokens[1];
				else if (tokens[0] == "db_user_id" && dbUserID.empty())
					dbUserID = tokens[1];
				else if (tokens[0] == "db_password" && dbPassword.empty())
					dbPassword = tokens[1];
				else if (tokens[0] == "db_schema" && dbSchema.empty())
					dbSchema = tokens[1];
				else if (tokens[0] == "db_table" && dbTable.empty())
					dbTable = tokens[1];				
			}
		}
		tokens.clear();
	}
	fin.close();
}

}

/*
int main()
{
	using namespace ctp;
	KSMarketDataConf conf("conf.props1");
	cout << conf.frontAddr << endl;
	cout << conf.brokerID << endl;
	cout << conf.userID << endl;
	cout << conf.password << endl;
	for (int i=0; i<conf.instruments.size(); i++)
	{
		cout << conf.instruments[i] << " ";
	}
	cout << endl;
}
*/

