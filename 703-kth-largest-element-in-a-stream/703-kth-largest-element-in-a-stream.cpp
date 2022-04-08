class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int pq_size;
    KthLargest(int k, vector<int>& nums) {
        pq_size=k;
        for(int &n:nums){
            if(pq.size()<pq_size)pq.push(n);
            else{
                if(pq.top()<n){
                    pq.pop();
                    pq.push(n);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<pq_size)pq.push(val);
        else if(pq.top()<val){pq.pop();pq.push(val);}
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */