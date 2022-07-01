bool comp(vector<int>& a, vector<int>& b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res=0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        for(int i=0;i<boxTypes.size();i++){
            //cout<<boxTypes[i][0]<<' '<<boxTypes[i][1]<<"\n";
            if(truckSize>0){
                res+=min(truckSize,boxTypes[i][0])*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
                //cout<<res<<"\n";
            }
        }
        return res;
    }
};