class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(int& n:nums){
            if(n>0)s.insert(n);
        }
        for(int i=1;i<1e9;i++){
            if(s.find(i)==s.end())return i;
        }
        return -1;
    }
};