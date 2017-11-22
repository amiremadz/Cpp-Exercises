#include <iostream>

using namespace std;

template <typename T, typename U>
struct isSame{
    enum {Is = false };
    //static const bool Is = false;
};

template <typename T>
struct isSame<T, T>{
    enum { Is = true };        
    //static const bool Is = true;
};

template <class A, class B>
bool isSameClass(){
    return isSame<A, B>::Is;
}



int main(){
    
    cout << isSameClass<int, int>() << endl;
    cout << isSameClass<int, float>() << endl;


    return 0;
}
