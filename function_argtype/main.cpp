#include <iostream>

// Method 1
void foo(int a, int b){
	std::cout << a << " " << b << std::endl;
}

template<typename T1, typename T2>
void foo(T1 a, T2 b) = delete;


// Method 2
template<typename T, typename U>
void func(T a, U b);

template<>
void func(int a, int b){
	std::cout << a << " " << b << std::endl;
}


int main(){

	int a = 1, b = 2;
	float c = 1.5, d = 4.2;
	long long e = 6, f = 7;

	foo(a, b);

	// this results in error: use of deleted function ‘void foo(T1, T2) [with T1 = float; T2 = float]
	// (c, d);

	// error: use of deleted function ‘void foo(T1, T2) [with T1 = long long int; T2 = long long int]
	// foo(e, f);

	func(a, b);

	// undefined reference to `void func<float, float>(float, float)
	//func(c, d);

	// 	undefined reference to `void func<float, float>(float, float)
	//func(e, f);

    return 0;
}
