#include <iostream>
#include <vector>
#include <cfloat>
#include <utility>

using namespace std;

typedef pair<float, float> Point_f;

class Closest {
    private:
        vector<Point_f> m_points;
        int m_k{0};
        vector<float> m_dists;

    public:
        Closest(vector<Point_f> points, int k) : m_points(points), m_k(k) { }

    private:
        void calc_dist();

    public:
        vector<Point_f> find_closests_naive();
};

void Closest::calc_dist(){
    for(auto point : m_points){
        float x = point.first;
        float y = point.second;
        float d =  x * x + y * y;
        m_dists.push_back(d);
    }
}

vector<Point_f> Closest::find_closests_naive(){
    calc_dist();
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

int main(){
    vector<Point_f> result;
    int k = 2;
    
    Point_f p1(1, 1);
    Point_f p2(.2, .2);
    Point_f p3(2, 2);
    Point_f p4(.4, .4);

    vector<Point_f> points = {p1, p2, p3, p4};

    Closest close_points(points, k);
    result = close_points.find_closests_naive();

    for(auto point : result){
        cout << point.first << ", " << point.second << flush;
        cout << endl;
    }

    return 0;
}

