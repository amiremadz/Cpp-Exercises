#include <iostream>
using namespace std;

class Base {
private:	
    virtual void method() {std::cout << "from Base" << std::endl;}
public:
    virtual ~Base() { cout << "base destructor" << endl; }
    void baseMethod() { method(); }
};

class A : public Base {
    void method() { std::cout << "from A" << std::endl; }
public:
    ~A() { cout << "A destructor" << endl; }
};

int main(void) {
    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}