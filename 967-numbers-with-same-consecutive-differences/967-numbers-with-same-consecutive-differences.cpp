class Solution {
public:
    set<int> st;
    
    void recur(int n, int k, int t){
        if(n==0){
            st.insert(t);
            return;
        }
        int b = t%10;
        t*=10;
        int nxt = k+b;
        if(k+b<10){
            t+=nxt;
            recur(n-1,k,t);
            t/=10;
            t*=10;
        }
        nxt = b-k;
        if(nxt>=0){
            t+=nxt;
            recur(n-1,k,t);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i=1;i<=9;i++){
            recur(n-1,k,i);
        }
        for(auto it:st)res.push_back(it);
        return res;
    }
};