class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0,res=n+1,k=n/4;
        
        for(char& c:s)mp[c]++;
        
        for(;j<n;j++){
            mp[s[j]]--;
            while(i<n && mp['Q']<=k && mp['W']<=k && mp['E']<=k && mp['R']<=k)//valid substring
            {
                res=min(res,j-i+1);
                mp[s[i]]++;
                i++;
            }
        }
        
        return res;
    }
};