class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int patLen=pattern.size();
        unordered_set<char> uniqueChars(pattern.begin(),pattern.end());
        for(string& w:words){
            if(w.size()!=patLen)continue;
            bool valid=true;
            unordered_set<char> checkUnique(w.begin(),w.end());
            if(checkUnique.size()!=uniqueChars.size())continue;
            unordered_map<char,char> map;
            for(int i=0;i<patLen;i++){
                if(map.find(pattern[i])==map.end()){
                    map[pattern[i]]=w[i];
                }
                else if(map[pattern[i]]!=w[i])valid=false;
            }
            if(valid)res.push_back(w);
        }
        return res;
    }
};