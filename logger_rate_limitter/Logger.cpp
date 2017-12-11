#include "Logger.hpp"

bool Logger::shouldPrintMessage(int timestamp, std::string message){

	const int min_elapsedtime = 10;

	if(!m_log.count(message)){
		m_log[message] = timestamp;
		return true;
	}

	int last_timestamp = m_log[message];
	int elapsed_time = timestamp - last_timestamp;

	if(elapsed_time < min_elapsedtime){
		return false;
	}

	m_log[message] = timestamp;

	return true;
}