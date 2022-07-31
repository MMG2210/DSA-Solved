class NumArray {
public:
    vector<int> fn,nums;
    int n;
    void init(int i, int val){
        i++;
        while(i<n){
            fn[i]+=val;
            i+=(i & (-i));
        }
    }
    NumArray(vector<int>& nums) {
        n=nums.size()+1;
        this->nums=nums;
        fn.resize(n,0);
        for(int i=0;i<nums.size();i++){
            init(i,nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff=val-nums[i];
        nums[i]=val;
        init(i,diff);
    }
    
    int sum(int i){
        i++;
        int res=0;
        while(i>0){
            res+=fn[i];
            i-=(i & (-i));
        }
        return res;
    }
    
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */