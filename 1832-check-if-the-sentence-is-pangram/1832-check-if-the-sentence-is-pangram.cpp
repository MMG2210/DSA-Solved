class Solution {
public:
    bool checkIfPangram(string& sentence) {
        int st[26]={0};
        for(char& c:sentence)st[c-'a']++;
        for(int i=0;i<26;i++){
            if(!st[i])return false;
        }
        return true;
    }
};