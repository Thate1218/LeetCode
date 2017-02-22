/**
*ʹ������䵱Hash������¼�ַ�Ԫ�صĳ��֣�ĳ�ַ�Ԫ�ص�ASCII���ڱ��ж�Ӧ��λ��
*�洢�������Ԫ�صĺ�һ��λ�ã����ܵ�����ͳ�ƿ�ʼλ�ã�
*��һ�������ַ�s[i]�����³��ֵ�s[i]���ǵ�һ�γ��֣���s[i]֮ǰ���ֹ��������Ѿ����ų������ˣ���Щʱ��Ҫ����max
*���������s[i]���ֹ����ڵ�ǰ��ⷶΧ�ڣ���ʱӦ����߽���������s[i]���Ҳ�һλ��Ҳ����m[s[i]]��ֵ
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