class Solution {
public:
    int alice=0, bob=0;
    bool solve(vector<int>& piles, int ind){
        if(ind==0)return alice>bob;
        
        if(ind%2){
            alice+=piles[ind];
        }
        else{
            bob+=piles[ind];
        }
        return solve(piles,ind-1);
    }
    
    
    bool stoneGame(vector<int>& piles) {
        sort(begin(piles),end(piles));
        return solve(piles,piles.size()-1);
    }
};