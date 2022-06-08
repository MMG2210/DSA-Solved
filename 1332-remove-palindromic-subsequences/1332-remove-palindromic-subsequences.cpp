class Solution {
public:
    bool isPalin(string &s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(isPalin(s,0,s.size()-1))return 1;
        else return 2;
    }
};