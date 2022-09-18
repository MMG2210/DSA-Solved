class Solution {
public:
    int trap(vector<int>& h) {
        int res=0;
        int i=0,j=h.size()-1,leftmax=0,rightmax=0;
        while(i<j){
            if(h[i]<h[j]){
                h[i]>=leftmax?leftmax=h[i]:res+=leftmax-h[i];
                i++;
            }
            else{
                h[j]>=rightmax?rightmax=h[j]:res+=rightmax-h[j];
                j--;
            }
        }
        return res;
    }
};