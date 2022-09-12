class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int N=t.size(),res=0;
        sort(t.begin(),t.end());
        int i=0,j=N-1;
        while(i<=j){
            if(t[i]<=p){
                res++;
                p-=t[i++];
            }
            else if(res>0 && i<j){
                res--;
                p+=t[j--];
            }
            else break;
        }
        return res;
    }
};