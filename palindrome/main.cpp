/*Given a string, determine if a permutation of the string 
 * could form a palindrome.
 * For example,
 *   "code" -> False, "aab" -> True, "carerac" -> True.
 */

#include <iostream>
#include <string>

using namespace std;

class Palindrome{
    public:
        bool canPermutePalindrome1(string s) {
            int size = s.size();
            int hash[128]{0};

            for(char ch : s){
               ++hash[(int)ch];
            }

            bool odd = false;

            for(int num :  hash){
                if(size % 2){
                    if(num % 2){
                        if(odd){
                            return false;
                        }
                        else{
                            odd = true;
                        }
                    }
                }
                else{
                    if(num % 2){
                        return false;
                    }
                }
            }
            return true;
        }

        bool canPermutePalindrome2(string s) {
            int odd_count = 0;
            int hash[128]{0};

            for(char ch : s){
                ++hash[(int)ch];
                if(hash[(int)ch] % 2){
                    ++odd_count;
                }
                else{
                    --odd_count;
                }
            }
            return (odd_count <= 1);
        }
};


int main(){
    string s1 = "code";
    string s2 = "aab";
    string s3 = "carerac";

    Palindrome pal;

    cout << pal.canPermutePalindrome1(s1) << endl;
    cout << pal.canPermutePalindrome1(s2) << endl;
    cout << pal.canPermutePalindrome1(s3) << endl;
    
    cout << pal.canPermutePalindrome2(s1) << endl;
    cout << pal.canPermutePalindrome2(s2) << endl;
    cout << pal.canPermutePalindrome2(s3) << endl;
  
    return 0;
}


