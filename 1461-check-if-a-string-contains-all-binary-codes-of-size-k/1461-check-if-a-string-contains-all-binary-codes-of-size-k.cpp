class Solution {
public:
    int binExpo(int a, int b){
        int res=1,mod=1e9+7;
        long long A=a;
        while(b){
            if(b&1)res*=A;
            res%=mod;
            A*=A;
            A%=mod;
            b>>=1;
        }
        return res;
    }
    
    bool hasAllCodes(string s, int k) {
        if(k>s.size())return 0;
        unordered_set<string> st;
        for(int i=0;i<s.size()-k+1;i++){
            st.insert(s.substr(i,k));
        }
        
        //return st.size()==pow(2,k);
        return st.size()==(1<<k);
    }
};