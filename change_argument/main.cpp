#include <iostream>

void func1(int x){
    std::cout << "In func1: ";
    ++x;
    std::cout << x << std::endl;
}

void func2(const int x){
    std::cout << "In func2: ";
    // compiler error
    //++x;
    std::cout << x << std::endl;
}

void func3(int x){
    std::cout << "In func3: ";
    int *ptr = &x;
    *ptr = 5;
    std::cout << x << std::endl;
}

void func4(const int x){
    std::cout << "In func4: ";
    // compiler error
    //int *ptr = &x;
    //*ptr = 5;
    std::cout << x << std::endl;
}

int main(){
    int x = 1;
    func1(x);
    std::cout << "func1: " << x << std::endl;

    func2(x);
    std::cout << "func2: " << x << std::endl;

    func3(x);
    std::cout << "func3: " << x << std::endl;

    func4(x);
    std::cout << "func4: " << x << std::endl;

    return 0;
}
