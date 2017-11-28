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

template<typename T, typename U>
bool same(){
    return false;
}

// does not work: partial specialization
/*
template<typename T>
bool same<T, T>(){
    return true;
}
*/

int main(){
    
    cout << isSameClass<int, int>() << endl;
    cout << isSameClass<int, float>() << endl;
    cout << same<int, float>() << endl;
    cout << same<float, float>() << endl;

    return 0;
}
