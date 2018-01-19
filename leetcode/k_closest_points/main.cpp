class Closest {
    private:
     int m_k{0};
     vector<pair<int, float>> m_dists;
     vector<pair<float, float>> m_points;
    
    public:
        Closest(vector<float, float> points, int k) : m_points(points), m_k(k) {
            m_points = points;
            m_k = k;
        }
        
    private:
        void calc_dist();
    
    public:
        vector<pair<float, float>> find_closests();
    
};

void Closest::calc_dist(){
    int idx = 0;
    for(auto point : m_points){
        float x = point.first;
        float y = point.second;
        float d =  x * x + y * y;
        m_dists.push_back(make_pair(idx, d));
        ++idx;
    }
}

vector<pair<float, float>> find_closests(){
    calc_dist();
    vector<pair<float, float>> result(m_k, -1);
    
    for(int idx_k = 0; idx_k < m_k; ++idx_k){
        float minval = FLOAT_MAX;
        int min_idx = -1;
    
        for(auto dist : m_dists){
            if(dist.second < minval){
                minval = dist.seond;
                min_idx = dist.first;
            }
        }
        
        result.push_back(m_points[min_idx]);
        m_points.remove(min_idx);
        m_dists.remove(min_idx);
    }    
    
    return result;
}