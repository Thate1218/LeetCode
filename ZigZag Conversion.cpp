class Solution {
public:
	string convert(string s, int numRows) {
		char ans[1000][1000];
		int i = 0, j = 0, cur = 0, size = s.length();
		string res = "";
		for (; i < 1000; i++){
			memset(ans[i], '0', 1000);
		}
		while (cur < size){
			if (j % 2 == 0){    //偶数列时由最上往最下走
				i = 0;
				while (cur < size && i < numRows){
					ans[i][j] = s[cur];
					cur++;
					i++;
				}
			}
			else{
				i = numRows - 2;
				while (cur < size && i > 0){
					ans[i][j] = s[cur];
					cur++;
					i--;
				}
			}
			j++;
		}
		cur = 0;
		for (i = 0; i < numRows; i++)
			for (j = 0; j < 1000; j++){
				if (ans[i][j] != ' '&& ans[i][j] != '0')
					res += ans[i][j];
			}
		return res;
	}
	int getCol(int j, int numRows){
		int i = 0, tag = 0;
		while (j > 0){
			if (j - (numRows - 2) >= 0){
				j = j - (numRows - 2);
				i += 2;
				continue;
			}
			else
				j = j - numRows;
			i++;
		}
		return i;
	}
};