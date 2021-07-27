void KMP(string text,string pattern){
	int m = text.size(),n = pattern.size();
	vector<int>lps(n);
	int i = 0,int j = 0;
	while(i<text.size() && j<n){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
					
		}
		if(j == n ) cout<<i-j<<endl , return;
	}
}

void longestprefixsuffix(vector<int>&lps,string s){
	int n = s.size();
	lps[0] = 0;
	int i=0,j=0;
        while(i<n){
		if(s[i] == s[j]){
			lps[i] = j;
			j++;
			i++;
		}
		else {
			if(j!=0) j = lps[j-1];
			else {
				
				lps[i] = 0;
				i++;
			}
		}
	}

}
