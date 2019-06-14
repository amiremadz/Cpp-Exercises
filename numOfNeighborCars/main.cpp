#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    
    int num_of_experiments = 100000;
    int num_of_cars = 25;
    
    int sum{0};
    
    for (int num = 1; num <= num_of_experiments; ++num) {
         std::vector<double> cars;
        for (int idx = 1; idx <= num_of_cars; ++idx)
        {
            cars.push_back(dis(gen));
        }
        
        std::sort(cars.begin(), cars.end());
        
        std::vector<int> neighbors_idx{1};
        
        for (int idx = 1; idx <= num_of_cars - 2; ++idx)
        {
            if (cars[idx] - cars[idx - 1] < cars[idx + 1] - cars[idx])
            {
                neighbors_idx.push_back(idx - 1);
            }
            else
            {
                neighbors_idx.push_back(idx + 1);
            }
        }
        
        neighbors_idx.push_back(num_of_cars - 2);
        
        int count{0}; 
        for (int i = 0; i < num_of_cars; ++i)
        {
            if (neighbors_idx[neighbors_idx[i]] == i)
            {
                ++count;
            }
        }
        
        sum += count;
    }
    
    std::cout << "Expected cardinality of neighbor set: " << static_cast<double>(sum) / num_of_experiments << std::endl;
    
    std::getchar();
	return 0;
}
