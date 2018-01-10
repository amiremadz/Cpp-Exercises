class Solution {
public:
    bool judgeCircle(string moves) {
    	int x = 0;
    	int y = 0;
    	for(char s : moves){
    		switch(s){
    			case 'L':
    				--x;
                    break;
    			case 'R':
    				++x;
                    break;
    			case 'U':
    				++y;
                    break;
    			case 'D':
    				--y;
                    break;
    			default:
    				cout << "invalid move: " << s << endl;
    		}
    	}
    	if(x || y){
    		return false;
    	}
    	return true;
    }
};