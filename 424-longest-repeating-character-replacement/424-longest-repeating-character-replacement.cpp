class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0,i=0,j=0,n=s.size(),repChar=0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            repChar=max(repChar,mp[s[j]]);
            
            if(j-i+1-repChar>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            
            res=max(res,j-i+1);
            j++;
        }
        
        return res;
    }
};