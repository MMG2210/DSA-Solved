class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq, nextElement;
        for(int& it : nums)freq[it]++;
        for(int it : nums){
                if(freq[it]<=0)continue;
            
                if(nextElement[it]){
                    nextElement[it]--;
                    nextElement[it+1]++;
                    freq[it]--;
                }
                else if(freq[it+1] && freq[it+2]){
                    freq[it]--;
                    freq[it+1]--;
                    freq[it+2]--;
                    nextElement[it+3]++;
                }
                else return false;
        }
        return true;
    }
};