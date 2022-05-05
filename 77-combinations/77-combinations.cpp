class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        
        recur(1,n,k,res,vector<int>());
        
        return res;
    }
    
    void recur(int num, int n, int k, vector<vector<int>>& res, vector<int> temp){
        
        if(k==0){
            res.push_back(temp);
            return;
        }
        
        for(int i=num;i<=n;i++){
            temp.push_back(i);
            recur(i+1,n,k-1,res,temp);
            temp.pop_back();
        }
        
        return;
    }
};