/**
*ʹ��map��¼�ѱ������Ĵ�����������ͬ�ַ�ʱ������һ�����ַ�λ�õ���һλ���¿�ʼ
*����������У�ʹ��max��¼�����
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