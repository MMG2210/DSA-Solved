class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i=0,n=nums.size();
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
            nums[it]=t[it];
    }
};