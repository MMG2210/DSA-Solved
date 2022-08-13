class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> m,temp;
        int len=words[0].size(), N=words.size();
        for(auto& w:words){
            m[w]++;
        }
        vector<int> res;
        for(int i=0;i<s.size()-N*len+1;i++){
            for(int j=i;j<i+N*len;j+=len){
                temp[s.substr(j,len)]++;
            }
            bool flag=true;
            for(auto &it: m){
                if(temp[it.first]!=it.second){
                    flag=false;
                    break;
                }
            }
            if(flag)res.push_back(i);
            temp.clear();
        }
        return res;
    }
};