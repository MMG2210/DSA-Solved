class Solution {
public:
    int countTexts(string s) {
        int a[10]={0,0,3,3,3,3,3,4,3,4};
        
        int n=s.size();
        
        int mod=1e9+7;
        
        vector<int> dp(n+1,0);
        
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            int c = s[i]-'0';
            for(int j=0;i+j<n && j<a[c] && s[i] == s[i+j]; j++){
                dp[i+j+1]+=dp[i];
                dp[i+j+1]%=mod;
            }
        }
        
        return dp[n];
    }
};