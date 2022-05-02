class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd,even,res;
        for(int& n:nums){
            if(n%2)odd.push_back(n);
            else even.push_back(n);
        }
        for(int& e:even)res.push_back(e);
        for(int& o:odd)res.push_back(o);
        
        return res;
    }
};