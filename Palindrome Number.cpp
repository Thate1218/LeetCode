class Solution {
public:
	bool isPalindrome(int x) {
	    if(x < 0)
	        return false;
		int weis = weishu(x);
		int i = 1, j = weis;
		if (weis % 2 != 0){
			while (i != j){
				if (numati(x, i) != numati(x, j))
					return false;
			i++;
			j--;
			}
		}
		else{
			while (i+1 != j){
				if (numati(x, i) != numati(x, j))
					return false;
				i++;
				j--;
			}
			if (numati(x, i) != numati(x, j)){
				return false;
			}
		}
		return true;
	}
	int weishu(int i){
		int s = 1;
		while (i - i % 10 != 0){
			i = (i - i % 10) / 10;
			s++;
		}
		return s;
	}
	int numati(int x, int i){
		int res = 0;
		while (i--){
			res = x % 10;
			x = (x - res) / 10;
		}
		return res;
	}
};