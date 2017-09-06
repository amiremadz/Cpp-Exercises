/*
 * Time.h
 *
 *  Created on: Sep 6, 2017
 *      Author: aemadzadeh
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>

using namespace std;

namespace mytime {

class Time{
private:
	int mHour;
	int mMinute;
public:
	Time(): mHour(0), mMinute(0) {}
	Time(int hour, int minute): mHour(hour), mMinute(minute) {}
	Time(const Time &other) { *this = other;	}
public:
	// display
	friend ostream &operator<<(ostream &out, const Time &time);

	// prefix ++
	Time operator++();

	// postfix ++
	Time operator++(int);

public:
	int hour() { return mHour; }
	int minute() { return mMinute; }
};


} /* namespace mytime */

#endif /* TIME_H_ */
