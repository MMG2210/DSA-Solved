class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n=s.size(),i=0,j;
        for(j=0;j<n;j++){
            if((k-=abs(s[j]-t[j]))<0){
                k+=abs(s[i]-t[i]);
                i++;
            }
        }
        
        return j-i;
    }
};