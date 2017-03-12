class Solution {
public:
	int reverse(int x) {
		if (x > 0){
			return re(x);
		}
		else
			return re((-1)*x)*(-1);
	}
	int re(int i){
		long long res = 0;
		int m = i % 10;
		while (i - m != 0){
			res *= 10;
			res += m;
			i = (i - m) / 10;
			m = i % 10;
		}
		res *= 10;
		res += i;
		 if (res > INT_MAX || res < INT_MIN)
			return 0;
		return res;
	}
};