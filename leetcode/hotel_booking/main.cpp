/*
You are given a set of check-in and check-out times as an array. 
How will you calculate the  minimum number of rooms required to accommodate all the guests.
*/
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> interval_t;

class Hotel{
    private:
        vector<interval_t> m_intervals;
    public:
        Hotel(vector<interval_t> intervals) : m_intervals(intervals) { }
    public:
        int min_rooms() { return method1(); };
    private:
        int method1();
};

int Hotel::method1(){
    int num_times = 0;
    for(auto item : m_intervals){
        if(item.second > num_times){
            num_times = item.second;
        }        
    }

    vector<int> counts(num_times + 1, 0);
    int result = 0;

    for(auto interval : m_intervals){
        for(int idx = interval.first; idx <= interval.second; ++idx){
            ++counts[idx];
        }
    }

    for(int cnt : counts){
        if(cnt > result){
            result = cnt;
        }
    }

    return result;
}

int main(){
    interval_t guest0(1, 3);
    interval_t guest1(2, 5);
    interval_t guest2(2, 7);
    interval_t guest3(6, 8);
    
    vector<interval_t> intervals = {guest0, guest1, guest2, guest3};
    Hotel myhotel(intervals);

    cout << myhotel.min_rooms() << endl;

	return 0;
}
