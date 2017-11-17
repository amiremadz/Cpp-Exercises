#include <iostream>

using namespace std;

//  populate B where B[i] is the product of all A[j] where j != i
void func(int * A, int *B, int N){
    int prod = 1;
    // multiply numbers before B[i]
    for(int i = 0; i < N; ++i){
        B[i] = prod;
        prod *= A[i];
    }

    prod = 1;

    // multiply numbers after B[i]
    for(int i = N-1; i >= 0; i--){
        B[i] *= prod;
        prod *= A[i];
    }
}

void print(int *arr, int N){
    for(int i = 0; i < N; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int main(){
    const int N = 6;
    int A[N] = {1, 2, 3, 4, 5, 6};
    int B[N];

    func(A, B, N);
    print(A, N);
    print(B, N);

    return 0;
}
