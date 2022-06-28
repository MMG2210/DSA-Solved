class Solution {
public:
    int minDeletions(string s) {
        int res=0;
        vector<int> v(1e5+10, 0),alp(26,0);
        for(char& c:s)alp[c-'a']++;
        sort(alp.begin(),alp.end());
        for(int i=0; i<26; i++){
            if(alp[i] && !v[alp[i]]){
                v[alp[i]]=1;
            }else if(v[alp[i]]){
                int curr = alp[i];
                while(curr>0 && v[curr])curr--;
                if(curr)v[curr]=1;
                res+=alp[i]-curr;
            }
        }
        return res;
    }
};