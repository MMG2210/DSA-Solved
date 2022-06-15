class Solution {
public:
    static bool compare(string& s1, string& s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n=words.size();
        unordered_map<string,int> dp;
        
        int res=0;
        for(string &w:words){
            for(int i=0;i<w.size();i++){
                string temp = w.substr(0,i) + w.substr(i+1);
                dp[w] = max(dp[w], dp.find(temp)==dp.end()? 1:dp[temp]+1);
            }
            res=max(res,dp[w]);
        }
        return res;
    }
};