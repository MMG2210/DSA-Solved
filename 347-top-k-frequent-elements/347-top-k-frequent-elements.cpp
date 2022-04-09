class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mpp;
        priority_queue<pair<int,int>> pq;
        for(auto it : nums)
            mpp[it]++;
        for(auto i = mpp.begin() ; i!=mpp.end(); i++)
        {
            pq.push(make_pair(i->second,i->first));
        }
        for(int i = 0; i<k;i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};