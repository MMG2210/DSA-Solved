class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cur=0,res=0,lastFruit=-1,secondLastFruit=-1,lastFruitCount=0;
        
        for(int& f:fruits){
            if(f==lastFruit || f==secondLastFruit){
                cur++;
            }
            else{
                cur=lastFruitCount+1;
            }
            if(f==lastFruit){
                lastFruitCount++;
            }
            else{
                lastFruitCount=1;
            }
            if(f!=lastFruit){
                secondLastFruit=lastFruit;
                lastFruit=f;
            }
            res=max(cur,res);
        }
        return res;
    }
};