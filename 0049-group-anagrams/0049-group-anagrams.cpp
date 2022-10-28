class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        for(string& s:strs){
            string t = s;
            sort(t.begin(),t.end());
            m[t].push_back(s);
        }
        for(auto& [k,vs]:m){
            res.push_back(vs);
        }
        return res;
    }
};