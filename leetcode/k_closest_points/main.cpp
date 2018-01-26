#include <iostream>
#include <vector>
#include <cfloat>  // for FLT_MAX
#include <utility> // for pair
#include <queue>

using namespace std;

typedef pair<float, float> Point_f;
typedef pair<int, float> Dist_t;

class Closest {
    private:
        vector<Point_f> m_points;
        int            m_k{0};
        vector<float>  m_dists;
        vector<Dist_t> m_idx_dists;

    public:
        Closest(vector<Point_f> points, int k) : m_points(points), m_k(k) { calc_dist(); }

    private:
        void calc_dist();

    public:
        vector<Point_f> find_closests_naive();
        vector<Point_f> find_closests_heap();
    
    public:
        vector<Point_f> get_points() {
            return m_points;
        }
   
    private:
        class DistComparator{
            public:
                bool operator() (const  Dist_t &dist_1, const Dist_t &dist_2) const{
                    return (dist_1.second <= dist_2.second);
                }
        };
};

void Closest::calc_dist(){
    int idx = 0;
    for(auto point : m_points){
        float x = point.first;
        float y = point.second;
        float d =  x * x + y * y;
        m_dists.push_back(d);
        m_idx_dists.push_back(make_pair(idx, d));
        ++idx;
    }
}

vector<Point_f> Closest::find_closests_naive(){
    vector<Point_f> result;

    for(int idx_k = 0; idx_k < m_k; ++idx_k){
        float min_val = FLT_MAX;
        int min_idx = -1;

        int idx = 0;
        for(auto dist : m_dists){
            if(dist <= min_val){
                min_val = dist;
                min_idx = idx; 
            }
            ++idx;
        }

        result.push_back(m_points[min_idx]);

        m_points.erase(m_points.begin() + min_idx);
        m_dists.erase(m_dists.begin() + min_idx);
    }    

    return result;
}

/*
 * use a max heap: put the first k element in it.
 * comapre the rest with its top.
 * if element is smaller than top, pop top, and then push.
 */
vector<Point_f> Closest::find_closests_heap(){
    vector<Point_f> result;
    priority_queue<Dist_t, vector<Dist_t>, DistComparator> pq;

    for(int idx = 0; idx < m_k; ++idx){
        pq.push(m_idx_dists[idx]);
    }

    for(int idx = m_k; idx < (int)m_idx_dists.size(); ++idx){
        if(m_idx_dists[idx].second <= pq.top().second){
            pq.pop();
            pq.push(m_idx_dists[idx]);
        }
    }

    while(!pq.empty()){
        int idx_top = pq.top().first;
        result.push_back(m_points[idx_top]);
        pq.pop();
    }

    return result;
}

int main(){
    vector<Point_f> result_naive;
    vector<Point_f> result_heap;
    int k = 2;
    
    Point_f p1(1, 1);
    Point_f p2(.2, .2);
    Point_f p3(2, 2);
    Point_f p4(.4, .4);

    vector<Point_f> points = {p1, p2, p3, p4};
    Closest close_points(points, k);

    result_heap = close_points.find_closests_heap();
    cout << "Heap algo: " << endl;
    for(auto point : result_heap){
        cout << point.first << ", " << point.second << flush;
        cout << endl;
    }

/*    
    cout << "----" << endl;
    vector<Point_f> check = close_points.get_points();
    for(auto point : check){
        cout << point.first << " " << point.second << endl;
    }
    cout << "----" << endl;
*/
   
    result_naive = close_points.find_closests_naive();
    cout << "Naive algo: " << endl;
    for(auto point : result_naive){
        cout << point.first << ", " << point.second << flush;
        cout << endl;
    }

    return 0;
}

