class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*int i=0,n=nums.size();
        if(k>n)k=k%n;
        stack<int> s;
        int j=n-1;
        while(i<k)
        {
            s.push(nums[j]);
            j--;
            i++;
        }
        vector<int> t;
        while(!s.empty()){
            t.push_back(s.top());
            s.pop();
        }
        for(int it=0;it<n-k;it++)
            t.push_back(nums[it]);
        for(int it=0;it<n;it++)
            nums[it]=t[it]; // TC O(N) , SC O(N)*/
        k %=nums.size();
        reverse(nums.begin(), nums.end());//4 3 2 1 5 6 7 rev first n-k elements
        reverse(nums.begin(), nums.begin()+k); // 4 3 2 1 7 6 5 rev remaining elements
        reverse(nums.begin()+k, nums.end()); // 5 6 7 1 2 3 4 rev the entire array and it is the   required soln
        //TC O(N) SC O(1)
    }
};