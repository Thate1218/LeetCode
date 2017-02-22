/**
*使用数组充当Hash表来记录字符元素的出现，某字符元素的ASCII码在表中对应的位置
*存储的是这个元素的后一个位置（可能的重新统计开始位置）
*第一次遇到字符s[i]或者新出现的s[i]不是第一次出现，但s[i]之前出现过，并且已经被排除在外了，这些时候要更新max
*其他情况是s[i]出现过且在当前检测范围内，这时应将左边界调整到这个s[i]的右侧一位，也就是m[s[i]]的值
**/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int m[256] = {0}, max = 0, left = 0;
		for(int i = 0; i < s.size(); i++){
		    if(m[s[i]] == 0 || m[s[i]] < left){ 
		        max = max > (i - left + 1) ? max : (i - left + 1);
		    }else{
		        left = m[s[i]];
		    }
		    m[s[i]] = i + 1;
		}
		return max;
	}
};