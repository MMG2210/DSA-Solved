#define pii pair<int,int>
#define F first
#define S second
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), L=0, R=n-k,mid;
        while(L<R){
            mid = (L+R)>>1;
            if(arr[mid] == arr[mid+k]){
                if(arr[mid]<x)L=mid+1;
                else R=mid;
            }
            else if(x-arr[mid]<=arr[mid+k]-x)R=mid;
            else L=mid+1;
        }
        return vector<int>(arr.begin()+L,arr.begin()+L+k);
    }
};