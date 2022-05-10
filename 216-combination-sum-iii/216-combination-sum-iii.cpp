class Solution {
public:
    vector<vector<int>> res;
    
    void recur(int k, int n, vector<int> temp, int i){
        if(k==temp.size() && n==0){
            res.push_back(temp);
            return;
        }
        
        if(temp.size()>k || n<0)return;
        
        for(int nxt=i;i<=9;i++){
            temp.push_back(i);
            recur(k,n-i,temp,i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        recur(k,n,vector<int>(),1);
        return res;
    }
};