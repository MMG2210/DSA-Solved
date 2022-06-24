class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(begin(target), end(target));
        auto sum = accumulate(begin(target), end(target), (long long) 0);
        
        while(sum>1 && pq.top()>sum/2){
            int cur = pq.top(); pq.pop();
            sum-=cur;
            if(sum<=1)return sum;
            pq.push(cur%sum);
            sum+=cur%sum;
        }
        
        return sum == target.size();
    }
};