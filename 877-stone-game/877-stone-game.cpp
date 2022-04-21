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
        int res=1;
        //return solve(piles,piles.size()-1);
        /*for(int ind=piles.size()-1;ind>-1;ind--){
            if(ind%2)res+=piles[ind];
            else res-=piles[ind];
        }*/
        return res>0;
    }
};