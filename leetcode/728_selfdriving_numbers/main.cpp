class Solution {
public:
	bool is_selfdriving(int num){
		int cpy = num;
		while(cpy){
			int rem = cpy % 10;
			if(!rem || (num % rem)){
				return false;
			}
			cpy /= 10;
		}
		return true;
	}

    vector<int> selfDividingNumbers(int left, int right) {
    	vector<int> result;
    	for(int num = left; num <= right; ++num){
    		if(is_selfdriving(num)){
    			result.push_back(num);
    		}
    	}
    	return result;
    }
};