class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0;
        for(int i=23;i>=0;i--){
            int cnt=0;
            for(int&c:candidates){
                if((c>>i)&1)cnt++;
            }
            res=max(res,cnt);
        }
        return res;
    }
};