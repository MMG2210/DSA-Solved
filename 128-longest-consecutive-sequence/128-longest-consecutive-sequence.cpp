class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(int num:nums)
            hash.insert(num);
        int maxStreak=0;
        for(int num:nums)
        {
            if(!hash.count(num-1))
            {
                int currNum=num;
                int currStreak=1;
                while(hash.count(currNum+1))
                {
                    currStreak+=1;
                    currNum+=1;
                }
                maxStreak=max(maxStreak,currStreak);
            }
        }
        return maxStreak;
    }
};