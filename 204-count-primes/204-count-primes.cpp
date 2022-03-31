class Solution {
public:
    int countPrimes(int n) {
    int count=0;
    vector<bool> isPrime(n,true);
    for(int i=2;i*i<n;i++){
        if(!isPrime[i])continue;
        for(int j=i*i;j<n;j+=i)isPrime[j]=false;
    }
    for(int i=2;i<n;i++){
        if(isPrime[i])count++;
    }
    return count;
    }
};