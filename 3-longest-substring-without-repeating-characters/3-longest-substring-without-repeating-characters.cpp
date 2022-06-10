class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0,r=0,l=0,n=s.size();
        vector<int> hash(256,-1);
        //unordered_map<string,int> hash;
        while(r<n)
        {
            if(hash[s[r]]!=-1)l=max(l,hash[s[r]]+1);
            hash[s[r]]=r;
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};