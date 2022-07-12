class Solution {
public:
    bool dfs(vector<int>& m, vector<int>& s, int i, int& target){
        if(i==m.size()){
            return s[0]==s[1] && s[1]==s[2] && s[2]==s[3];
        }
        for(int j=0;j<4;j++){
            if(s[j]+m[i]>target)continue;
            s[j]+=m[i];
            if(dfs(m,s,i+1,target))return true;
            s[j]-=m[i];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()==0)return 0;
        int sum=accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4)return false;
        vector<int> s(4,0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        sum/=4;
        return dfs(matchsticks, s, 0, sum);
    }
};