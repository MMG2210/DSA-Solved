// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define F first
#define S second
bool comp(pair<int,int> a, pair<int,int> b){
        return a.S > b.S;
    }
class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        int sum=0;
        vector<pair<int,int>> pC;
        for(int i=0;i<N;i++){
            pC.push_back({A[i],B[i]});
        }
        sort(pC.begin(),pC.end(),comp);
        for(int i=0;i<N && T>0;i++){
            if(T<pC[i].F){
                sum+=T*pC[i].S;
                T=0;
            }
            else{
                T-=pC[i].F;
                sum+=(pC[i].F*pC[i].S);
            }
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends