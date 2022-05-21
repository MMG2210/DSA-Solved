class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> freq(3,0);
        
        int res=0,i=0,j=0;
        
        for(;j<n;j++){
            freq[s[j]-'a']++;
            while(freq[0] && freq[1] && freq[2]){
                freq[s[i++]-'a']--;
            }
            res+=i;
        }
        
        return res;
    }
};