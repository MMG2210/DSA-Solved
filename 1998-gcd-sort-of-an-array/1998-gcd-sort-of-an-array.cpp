class UFDS{
    vector<int> par;
public:
    UFDS(int n){
        par.resize(n);
        for(int i=0;i<n;i++)par[i]=i;
    }
    int find(int x){
        if(par[x]==x)return x;
        else return par[x] = find(par[x]);
    }
    void Union(int x, int y){
        int px = find(x), py=find(y);
        if(px!=py)par[px]=py;
    }
};

class Solution {
public:
    vector<int> spf;
    
    void sieve(int n){
        spf.resize(n);
        for(int i=2;i<n;i++)spf[i]=i;
        spf[0]=spf[1]=0;
        for(int i=2;i*i<n;i++){
            if(spf[i]!=i)continue;
            for(int j=i*i;j<n;j+=i){
                if(spf[j]>i)spf[j]=i;
            }
        }
    }
    
    vector<int> getPrimeFactors(int n){
        vector<int> factors;
        while(n>1){
            factors.push_back(spf[n]);
            n/=spf[n];
        }
        return factors;
    }
    
    bool gcdSort(vector<int>& nums) {
        int maxn = *max_element(nums.begin(),nums.end());
        sieve(maxn+1);
        UFDS uf(maxn+1);
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        
        for(int &x : nums){
            for(int &f:getPrimeFactors(x)){
                uf.Union(x,f);
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(uf.find(nums[i])!=uf.find(sorted[i]))return false;
        }
        
        return true;
    }
};