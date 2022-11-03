class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0,mid=0;
        unordered_map<string,int> mp;
        for(auto& w:words)mp[w]++;
        for(auto& x:words){
            string w = x;
            swap(w[0],w[1]);
            if(w!=x and mp[w]>0 and mp[x]>0){
                res+=4;
                mp[x]--;
                mp[w]--;
            }
            else if(w==x and mp[x]>1){
                res+=4;
                mp[x]-=2;
            }
            else if(w==x and mid==0 and mp[x]>0){
                mp[x]--;
                res+=2;
                mid=1;
            }
        }
        return res;
    }
};