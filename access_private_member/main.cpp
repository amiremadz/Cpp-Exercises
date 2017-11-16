#include <iostream>

// Note: If it turns out that the alignment of the external library is mismatched
// to your code, you can resolve this using #pragma pack.

class Something {
public:
    Something() {
        topSecretValue = 42;
    }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

class SomethingReplica {
public:
    int getTopSecretValue() { return topSecretValue; }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

int main(){
    Something a;
    SomethingReplica* b = reinterpret_cast<SomethingReplica*>(&a);
    std::cout << b->getTopSecretValue() << std::endl;

    return 0;
}
