#include <iostream>

using namespace std;

class B {
    protected:    
        float x{0};
};

class A : public B {
    public:
        float get() { return x; };
};

//check if D is derived from B
template<typename D, typename B>
class IsDerivedFromHelper{
    private:
        class No  { };
        class Yes { No no[3]; }; // make sure sizeof(Yes) neq sizeof(No)

        static Yes Test(B*);     // if D* can be converted to B*, this one is selected
        static No  Test(...);
    public:
        // method 1
        //static const bool value = ( sizeof(Yes) == sizeof(Test(static_cast<D*>(0))) );
        
        // method 2
        // 0: nullptr
        enum { value = ( sizeof(Yes) == sizeof(Test(static_cast<D*>(0))) ) };
};

// check if C is derived from P
template<class C, class P>
bool IsDerivedFrom(){
    return IsDerivedFromHelper<C, P>::value;
}

int main(){
    cout << IsDerivedFrom<B, A>() << endl;
    cout << IsDerivedFrom<A, B>() << endl;
    cout << IsDerivedFrom<int, A>() << endl;

    return 0;
}
