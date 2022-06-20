class TrieNode{
public:
    unordered_map<char,TrieNode*> edge;
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode;
        vector<pair<TrieNode*,int>> possibilities;
        for(auto& w :unordered_set<string>(words.begin(),words.end())){
            TrieNode* cur = root;
            for(int i=w.size()-1;i>=0;i--){
                if(cur->edge.count(w[i])==0)cur->edge[w[i]]=new TrieNode;
                cur=cur->edge[w[i]];
            }
            possibilities.push_back({cur,w.size()});
        }
        
        int res=0;
        for(auto& p:possibilities){
            if(p.first->edge.empty())res+=(p.second+1);
        }
        return res;
    }
};