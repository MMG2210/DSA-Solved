class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<nums.size(); i++){
            if(pq.size()<k)pq.push(nums[i]);
            else{
                int cur = pq.top(); pq.pop();
                cur=max(cur,nums[i]);
                pq.push(cur);
            }
        }
        
        return pq.top();
    }
};