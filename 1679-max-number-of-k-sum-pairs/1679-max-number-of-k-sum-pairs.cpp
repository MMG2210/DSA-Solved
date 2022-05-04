class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> hash; //value,occurence
        int res=0;
        
        for(int& n:nums){
            int complement = k-n;
            if(hash[complement]>0){res++;hash[complement]--;}
            else hash[n]++;
        }
        
        return res;
    }
};