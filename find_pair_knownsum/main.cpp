#include <iostream>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> mypair;

class Search{
    static bool func(const mypair &l, const mypair &r) { return (l.first < r.first); }
    static const int MAX = 10000;
    private:
        vector<mypair> m_vec;
        int  m_sum{0};
    public:
        Search(int sum, initializer_list<int> list) : m_sum(sum) {
            int idx = 0;
            for(int item : list){
                m_vec.push_back(make_pair(item, idx));
                ++idx;
            }
        }
    public:
        void print() const {
            cout << "sum: " << m_sum << endl;
            cout << "vector: " << flush;
            for(auto item : m_vec){
                cout << item.first << " " << flush;
            }
            cout << endl;
        }
    public:
        mypair find_sort(){
            int l = 0;
            int r = (int)m_vec.size()-1;
            
            sort(m_vec.begin(), m_vec.end(), Search::func);    
            
            while(l < r){
                if((m_vec[l].first + m_vec[r].first) > m_sum){
                    --r;
                }
                else if ((m_vec[l].first + m_vec[r].first) < m_sum){
                    l++;
                }
                else{
                    break;
                }
            }
            return make_pair(m_vec[l].second, m_vec[r].second);
        }

        mypair find_hash(){
            int idx1 = -1;
            int idx2 = -1;
            vector<mypair> hashmap(MAX, make_pair(0, -1)); 
            for(int i = 0; i < m_vec.size(); ++i){
                int idx_pair =  m_sum - m_vec[i].first;
                if( hashmap[ idx_pair ].first){
                    idx1 = m_vec[i].second;
                    idx2 = hashmap[ idx_pair ].second; 
                }
                else{
                    hashmap[m_vec[i].first].first = 1;
                    hashmap[m_vec[i].first].second = m_vec[i].second;
                }
            }
            return make_pair(idx1, idx2);
        }
};

int main(){
    int sum = 27;
    pair<int, int> result;

    Search my_search(sum, {2, 22, 7, 23, 11, 5, 15});
    my_search.print();

    result = my_search.find_hash();
    cout << "Using hash: " << result.first << ", " << result.second << endl;

    result = my_search.find_sort();
    cout << "Using sort: " << result.first << ", " << result.second << endl;    
    my_search.print();

    return 0;
}

