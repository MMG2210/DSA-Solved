// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        bool check(int chk, int n){
            int temp = chk, count = 0, f = 5;
            while(f<=temp){
                count+=temp/f;
                f*=5;
            }
            return count>=n;
        }
        int findNum(int n)
        {
        //complete the function here
            if(n==1)return 5;
            int l=0,r=5*n;
            while(l<r){
                int mid = l + (r-l)/2;
                if(check(mid,n)){
                    r=mid;
                }
                else l=mid+1;
            }
            return l;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends