class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0;
        multiset<string> mp;
        for(auto& i:words){
            string cur = i;
            swap(cur[0],cur[1]);
            if(mp.find(cur)!=mp.end()){
                res+=4;
                mp.erase(mp.find(cur));
            }
            else mp.insert(i);
        }
        for(auto& s:mp){
            if(s[0]==s[1]){
                res+=2;
                break;
            }
        }
        return res;
    }
};