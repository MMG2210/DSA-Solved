class Solution {
public:
    /*int totalFruit(vector<int>& fruits) {
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
    }*/
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> taken;
        int n=fruits.size(),i,j;
        for(i=0,j=0;j<n;j++){
            taken[fruits[j]]++;
            if(taken.size()>2){
                if(--taken[fruits[i]]==0)taken.erase(fruits[i]);
                i++;
            }
        }
        return j-i;
    }
};