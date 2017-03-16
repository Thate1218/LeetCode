class Solution {
	public:
		int myAtoi(string str) {
			if (str.empty()) 
				return 0;
			int i = 0, base = 0, sign = 1, s = str.size();
			while (i < s && str[i] == ' ') 
				++i;
			if (str[i] == '+' || str[i] == '-'){
				sign = (str[i++] == '+') ? 1 : -1;
			}
			while (i < s && str[i] >= '0' && str[i] <= '9'){
				if (base > INT_MAX / 10 || (base == INT_MAX / 10) && str[i] - '0' > 7){
					return (sign == 1) ? INT_MAX : INT_MIN;
				}
				base = 10 * base + (str[i++]-'0');
			}
			return base * sign;
		}
};