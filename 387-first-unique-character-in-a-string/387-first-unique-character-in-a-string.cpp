class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;//char,pos
        int i=-1;
        for(auto& c:s){
            i++;
            if(!m.count(c)){
                m[c].first=i;
                
            }
            m[c].second+=1;
        }
        int res=INT_MAX;
        for(auto& it:m){
            if(it.second.second==1){
                res=min(it.second.first,res);
            }
        }
        return res==INT_MAX?-1:res;
    }
};