// class NumArray {
// public:
//     vector<int> fn,nums;
//     int n;
//     void init(int i, int val){
//         i++;
//         while(i<n){
//             fn[i]+=val;
//             i+=(i & (-i));
//         }
//     }
//     NumArray(vector<int>& nums) {
//         n=nums.size()+1;
//         this->nums=nums;
//         fn.resize(n,0);
//         for(int i=0;i<nums.size();i++){
//             init(i,nums[i]);
//         }
//     }
    
//     void update(int i, int val) {
//         int diff=val-nums[i];
//         nums[i]=val;
//         init(i,diff);
//     }
    
//     int sum(int i){
//         i++;
//         int res=0;
//         while(i>0){
//             res+=fn[i];
//             i-=(i & (-i));
//         }
//         return res;
//     }
    
//     int sumRange(int left, int right) {
//         return sum(right)-sum(left-1);
//     }
// }; Done using Fenwick/Binary Indexed Tree, O(NlogN) to build tree and O(logN) for each query

class NumArray {
public:
    int n;
    vector<int> st;
    NumArray(vector<int>& nums) {
        n=nums.size();
        st.resize(4*n,0);
        buildST(nums);
    }
    
    void buildST(vector<int>& v){
        build(0,n-1,0,v);
    }
    
    void build(int start, int end, int node, vector<int>& v){
        if(start==end){
            st[node]=v[start];
            return;
        }
        int mid = start + (end-start)/2;
        //Build Left subtree
        build(start,mid,2*node+1,v);
        //Build Right subtree
        build(mid+1,end,2*node+2,v);
        
        st[node] = st[2*node+1] + st[2*node+2];
    }
    
    void update(int index, int val) {
        return update(0,n-1,0,index,val);
    }
    
    void update(int start, int end, int i, int& ind, int& val){
        if(start==end){
            st[i]=val;
            return;
        }
        int mid = start + (end-start)/2;
        if(ind<=mid){
            update(start,mid,2*i+1,ind,val);
        }
        else{
            update(mid+1,end,2*i+2,ind,val);
        }
        st[i] = st[2*i+1] + st[2*i+2];
    }
    
    int sumRange(int l, int r) {
        return query(0,n-1,0,l,r);
    }
    
    int query(int start, int end, int i, int& l, int& r){
        //Non-overlapping condition
        if(start>r || end<l)return 0;
        //Full overlapping
        if(start>=l && end<=r)return st[i];
        int mid = start + (end-start)/2;
        return query(start,mid,2*i+1,l,r) + query(mid+1,end,2*i+2,l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */