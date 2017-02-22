/**
*使用map记录已遍历过的串，当遇到相同字符时，从上一个此字符位置的下一位重新开始
*在这个过程中，使用max记录最长长度
*
**/
class Solution { 
public:
	int lengthOfLongestSubstring(string s) {
		int max = 1, size = s.size();
		if(!size)
		    return 0;
		map<char, int> f;
		for (int i = 0; i < size;){
			if (f.find(s[i]) == f.end()){
				f[s[i]] = i;
				i++;
				max = f.size() > max ? f.size() : max;
			}
			else{
				map<char, int>::iterator iter = f.find(s[i]);
				int m = iter->second + 1;
				f[s[i]] = i;
				max = f.size() > max ? f.size() : max;	
				i = m;
				f = map<char, int>();
			}
		}
		return max;
	}
};