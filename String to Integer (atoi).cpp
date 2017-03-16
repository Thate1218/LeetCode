class Solution {
	public:
		int myAtoi(string str) {
			int i = 0, size = str.length(), flag = 1, pos = 0, result = 0;
			if (!size)
				return 0;
			while (true){
				if (!isNum(str[i]) && str[i] != '\0'){   //不是数字并且不是最后，判断是否为符号且符号是否重复出现
					if (str[i] == '-' && !pos){
						flag = 0;
						pos = -1;
					}
					else if (str[i] =='+'&&!pos){
						flag = 0;
						pos = 1;
					}
					else if (str[i] == '-' && pos || str[i] == '+' && pos){
						return 0;
					}
					else if (!flag){
						break;
					}
					else if (!isSpace(str[i]))
						return 0;
					i++;
				}
				else{
					flag = 0;
					result = judge(result,chartoint(str[i]),pos);
					if (result < 0)
						return INT_MIN;
					i++;
				}
				if (str[i] == '\0')
					break;
			}
			if (pos == 0){
				pos = 1;
			}
			return pos*result;
		}
		int chartoint(char c){
			int i = c - 48;
			return i;
		}
		bool isNum(char c){
			if ((c >= '0' && c <= '9'))
				return true;
			return false;
		}
		bool isSpace(char c){
			if (c == ' '){
				return true;
			}
			return false;
		}
		int judge(int i, int j,int pos){
			if (i != 10 * i / 10 && pos!=-1){
				return INT_MAX;
			}
			if (i != 10 * i / 10 && pos == -1){
				return -1;
			}
			if (10 * i > INT_MAX - j && pos != -1){
				return INT_MAX;
			}
			else if (10 * i > INT_MAX - j && pos == -1){
				return -1;
			}
			return 10 * i + j;
		}
};