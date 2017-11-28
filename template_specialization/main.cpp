#include <iostream>
using namespace std;

// check if classes are same
template<typename T, typename U>
class sameClass{
	enum { Is = false } ;
};

template<typename T>
class sameClass<T, T>{
	enum { Is = true };
};

// check if P is derived from C
template<typename P, typename C>
class isDerived{
private:
	class No  { };
	class Yes { No no[3]; };
	
	Yes test(C*);
	No 	test(...);
public:
	enum{ Is = ( sizeof(Yes) == sizeof( test(static_cast<P*>(0)) ) ) };
};

// check if T has:
// class T{
//		T* Clone() const {
//
//		}
// }
template <typename T>
class HasClone{
private:
	void constraints(){
		T* (T::*test)() const = &T::Clone;
		test(); // suppress warnings
	}
public:
	HasClone(){
		void (*p)() = constraints; 
	}
};

template<typename T>
class C : HasClone<T>{

};

// Fibonacci
template<int n>
class Fib{
public:
	static int compute(){
		return n * Fib<n-1>::compute();
	}
};

template<>
class Fib<0>{
public:
	static int compute(){
		return 1;
	}
};


int main(){
	cout << Fib<5>::compute() << endl;

	return 0;
}