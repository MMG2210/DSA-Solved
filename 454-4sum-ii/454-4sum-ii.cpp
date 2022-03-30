class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res=0;
        int n = nums1.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tempSum = nums1[i]+nums2[j];
                if(m.find(tempSum)==m.end()){
                    m[tempSum] = 1;
                }
                else m[tempSum]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tempSum = nums3[i]+nums4[j];
                tempSum*=-1;
                if(m.find(tempSum)!=m.end())res+=m[tempSum];
            }
        }
        return res;
    }
};