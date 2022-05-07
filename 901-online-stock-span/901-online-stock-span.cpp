class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i=0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price)st.pop();
        if(st.empty()){
            st.push({price,i});
            int j=i;
            i++;
            return j-(-1);
        }
        
        else{
            auto res=st.top();
            int j=i;
            st.push({price,i++});
            return j-res.second;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */