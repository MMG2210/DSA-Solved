class Solution {
public:
    vector<vector<int>> dp;
    int memo(string& s1, string& s2, int i, int j){
        if(i<0)return 0;
        if(j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j] = 1+memo(s1,s2,i-1,j-1);
        else{
            return dp[i][j] = max(memo(s1,s2,i-1,j),memo(s1,s2,i,j-1));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return memo(text1,text2,text1.size()-1,text2.size()-1);
    }
};