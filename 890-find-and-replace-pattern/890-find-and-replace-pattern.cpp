class Solution {
public:
    // vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    //     vector<string> res;
    //     int patLen=pattern.size();
    //     unordered_set<char> uniqueChars(pattern.begin(),pattern.end());
    //     for(string& w:words){
    //         if(w.size()!=patLen)continue;
    //         bool valid=true;
    //         unordered_set<char> checkUnique(w.begin(),w.end());
    //         if(checkUnique.size()!=uniqueChars.size())continue;
    //         unordered_map<char,char> map;
    //         for(int i=0;i<patLen;i++){
    //             if(map.find(pattern[i])==map.end()){
    //                 map[pattern[i]]=w[i];
    //             }
    //             else if(map[pattern[i]]!=w[i])valid=false;
    //         }
    //         if(valid)res.push_back(w);
    //     }
    //     return res;
    // }
    
    string normalise(string w){
        unordered_map<char,int> map;
        string res="";
        for(char& c:w)if(!map.count(c))map[c]=map.size();
        for(int i=0;i<w.size();i++){
            w[i]='a'+map[w[i]];
        }
        return w;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string p){
        vector<string> res;
        p=normalise(p);
        for(string& w:words)if(normalise(w)==p)res.push_back(w);
        return res;
    }
};