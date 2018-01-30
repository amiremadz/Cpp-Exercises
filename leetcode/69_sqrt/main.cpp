/*
69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.
*/

#include <iostream>
#include <cmath> // fabs

using namespace std;

class Solution {
    private:
        int bin_search(int x){
            // to avoid mid = 0
            if(x < 2){
                return x; 
            }

            int left = 0;
            int right = x; 

            while(left <= right){
                int mid = (left + right) / 2;

                if(mid == x / mid){
                    return mid;
                }

                if(mid > x / mid){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            return right;
        }

        int lin_search(int x) {
            if(x < 1){
                return 0;
            }
            int n = 1;

            //while((long)n * n <= x){
            while(n <= x / n){
                ++n;
            }
            return n-1;
        }

    public:
        int mySqrt(int x){
            return bin_search(x);
            //return lin_search(x);
        }

        float mySqrt(float x){
            float left = 0;
            float right = x;
            
            float tol = 1e-3;

            while(left < right){
                float mid = (left + right)/2;
                
                if(fabs(mid - x / mid) < tol){
                    return mid;
                }

                if(mid * mid > x){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            return -1;
        }
};


int main(){
	int x = 2147395600;
	Solution sol;

	cout << sol.mySqrt(1) << endl;
	cout << sol.mySqrt(3) << endl;
	cout << sol.mySqrt(4) << endl;
	cout << sol.mySqrt(1100) << endl;
	cout << sol.mySqrt(22) << endl;
	cout << sol.mySqrt(x) << endl;
    cout << endl;
	cout << sol.mySqrt((float)4.0) << endl;
	cout << sol.mySqrt((float)1100.0) << endl;
	cout << sol.mySqrt((float)22.5) << endl;
	cout << sol.mySqrt((float)x) << endl;
	
    return 0;
}
