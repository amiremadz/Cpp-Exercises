/*
 * Test.h
 *
 *  Created on: Aug 30, 2017
 *      Author: aemadzadeh
 */

#ifndef TEST_H_
#define TEST_H_


template<typename T>
class Test{
public:
	Test(T obj){
		mObj = obj;
	}
public:
	void print(){
		std::cout << mObj << std::endl;
	}
private:
	T mObj;
};

// Explicit specialization
template<>
void Test<double>::print(){
	std::cout << std::scientific << mObj << std::endl;
}


#endif /* TEST_H_ */
