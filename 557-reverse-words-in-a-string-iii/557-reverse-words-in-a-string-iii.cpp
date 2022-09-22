class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i=0,j=0;j<=n;j++){
            if(j==n || s[j]==' '){
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
            }
        }
        return s;
    }
};