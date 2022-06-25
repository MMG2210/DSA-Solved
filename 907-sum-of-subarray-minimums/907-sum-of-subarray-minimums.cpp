class Solution {
public:
    long long sum=0;
    int mod = 1e9+7;
    
    void solve(vector<int>& arr, int i, int curMin=INT_MAX){
        if(i==arr.size())return;
        curMin = min(curMin, arr[i]);
        sum=(sum%mod + curMin%mod)%mod;
        solve(arr,i+1,curMin);
    }
    
    int sumSubarrayMins(vector<int>& a) {
        stack<pair<int,int>> st_p, st_n;
        int n=a.size();
        vector<int> ple(a.size()), nle(a.size());
        for(int i=0;i<a.size();i++)ple[i]=i+1;
        for(int i=0;i<a.size();i++)nle[i]=a.size()-i;
        
        for(int i=0;i<a.size();i++){
            while(!st_p.empty() && st_p.top().first>a[i])st_p.pop();
            ple[i] = st_p.empty()?i+1:i-st_p.top().second;
            st_p.push({a[i],i});
            
            while(!st_n.empty() && st_n.top().first>a[i]){
                auto x = st_n.top(); st_n.pop();
                nle[x.second]=i-x.second;
            }
            st_n.push({a[i],i});
        }
        
        long long int res=0;
        for(int i=0;i<a.size();i++){
            res = (res%mod + (1ll*a[i]*ple[i]*nle[i])%mod)%mod;
        }
        
        return (int)res%mod;
    }
};