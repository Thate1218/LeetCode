class Solution {
public:
	string hand(string s, bool oe){
		string res;
		int size = s.size();
		if (oe){
			for (int i = size - 1; i >= 1; i--){
				res += s[i];
			}
			res += s;
			return res;
		}
		else{
			for (int i = size - 1; i >= 0; i--){
				res += s[i];
			}
			res += s;
			return res;
		}
	}
	string longestPalindrome(string s) {
		string  res;
		int maxlength = 0, ptag = 0;
		while (s[ptag] != '\0'){
			string odd = "", even = "";
			int oddlength = 1;
			int pleft = ptag - 1;
			int pright = ptag + 1;
			odd += s[ptag];
			while (pleft >= 0 && s[pright] != '\0' && s[pleft] == s[pright]){
				odd += s[pright];
				pleft--;
				pright++;
				oddlength += 2;
			}
			int evenlength = 0;
			pleft = ptag, pright = ptag + 1;
			while (pleft >= 0 && s[pright] != '\0' && s[pleft] == s[pright]){
				even += s[pleft];
				pleft--;
				pright++;
				evenlength += 2;
			}
			if (oddlength > evenlength){
				if (maxlength < oddlength){
					maxlength = oddlength;
					res = odd;
				}
			}
			else{
				if (maxlength < evenlength){
					maxlength = evenlength;
					res = even;
				}
			}
			ptag++;
		}
		return hand(res, maxlength % 2 );
	}
};