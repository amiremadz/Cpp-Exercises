#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <unordered_map>

class Logger{
private:
	std::unordered_map<std::string, int> m_log;	
public:
	Logger() {	}
public:
	bool shouldPrintMessage(int timestamp, std::string message);
};

#endif