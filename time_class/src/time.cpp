/*
 * Time.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: aemadzadeh
 */

#include "time.h"

namespace mytime {


ostream &operator<<(ostream &out, const Time &time){
	out << "H: " << time.mHour << " M: " << time.mMinute;
	return out;
}

Time Time::operator++(){
	mMinute++;
	if(mMinute >= 60){
		mMinute -= 60;
		mHour++;
		if(mHour >= 24){
			mHour -= 24;
		}
	}
	return 	Time(mHour, mMinute);
}

Time Time::operator++(int){
	Time tmp(mHour, mMinute);
	mMinute++;
	if(mMinute >= 60){
		mMinute -= 60;
		mHour++;
		if(mHour >= 24){
			mHour -= 24;
		}
	}
	return tmp;
}


} /* namespace mytime */
