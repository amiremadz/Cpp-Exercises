#include <iostream>
#include <vector>
#include <cfloat>
#include <utility>

using namespace std;

typedef pair<float, float> point_f;

class Closest {
    private:
        vector<point_f> m_points;
        int m_k{0};
        vector<float> m_dists;

    public:
        Closest(vector<point_f> points, int k) : m_points(points), m_k(k) { }

    private:
        void calc_dist();

    public:
        vector<point_f> find_closests();
};

void Closest::calc_dist(){
    for(auto point : m_points){
        float x = point.first;
        float y = point.second;
        float d =  x * x + y * y;
        m_dists.push_back(d);
    }
}

vector<point_f> Closest::find_closests(){
    calc_dist();
    vector<point_f> result;

    for(int idx_k = 0; idx_k < m_k; ++idx_k){
        float min_val = FLT_MAX;
        int min_idx = -1;

        int idx = 0;
        for(auto dist : m_dists){
            if(dist < min_val){
                min_val = dist;
                min_idx = idx; 
                ++idx;
            }
        }

        result.push_back(m_points[min_idx]);
        m_points.erase(m_points.begin() + min_idx);
        m_dists.erase(m_dists.begin() + min_idx);
    }    

    return result;
}


int main(){
    point_f p1(1, 1);
    point_f p2(.2, .2);
    point_f p3(2, 2);
    point_f p4(4, 4);

    vector<point_f> points = {p1, p2, p3, p4};
    int k = 2;
    
    vector<point_f> result;

    Closest close_points(points, k);

    result = close_points.find_closests();

    for(auto point : result){
        cout << point.first << ", " << point.second << flush;
        cout << endl;
    }

    return 0;
}

