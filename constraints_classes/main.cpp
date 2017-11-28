#include <iostream>
#include <cassert>

using namespace std;

// Example 4-2(d): Alternative way of requiring
// // exactly T* T::Clone() const
// //
// // T must provide T* T::Clone() const

// HasClone requires that T must provide
// T* T::Clone() const
template<typename T>
class C{
    public:
        bool validateRequirements() const{
            T* (T::*test)() const = &T::Clone;    
            test;
            return true;
        }

    public:
        ~C() {
            assert(validateRequirements());
        }
};

template <typename T>
class HasClone{
    public:
        static void constraints(){
            T* (T::*test)() const = &T::Clone;
            test;  // suppress warnings about unused variables
        }
    public:
        HasClone(){
            void (*p)() = constraints;
        }     
};


class T{
    private:
        int n{1};
    public:
        T* Clone() const {
            return new T(*this);
        }
};

class F{};

class G{
    private:
        int n{1};
    public:
        G* Clone() {
            return new G(*this);
        }
};


template <typename T>
class D : HasClone<T>{
};

int main(){
    D<T> d1;
    //D<G> d2;
    //C<T> test1;
    //C<G> test2;

    return 0;
}
