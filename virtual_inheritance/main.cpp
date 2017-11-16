#include <iostream>

class D {
public:
    void foo() {
        std::cout << "Foooooo" << std::endl;
    }
};


class C:  virtual public D {
};

class B:  virtual public D {
};

class A: public B, public C {
};

int main(int argc, const char * argv[]) {
    A a;
    // if virtual is not used, we get 2 copies of D in A. The foo 
    // becomes ambiguous.
    a.foo(); 
}