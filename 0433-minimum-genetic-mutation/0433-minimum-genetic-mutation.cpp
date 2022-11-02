#define F first
#define S second
class Solution {
public:
    unordered_set<string> val;
    int bfs(string& start, string& end){
        int lvl=-1;
        queue<string> q;//Queue of (string and its level)
        q.push(start);
        vector<char> nxt;
        nxt.push_back('A');nxt.push_back('C');nxt.push_back('G');nxt.push_back('T');
        while(!q.empty()){
            lvl++;
            int sz = q.size();
            while(sz--){
                auto node = q.front();q.pop();
                if(node == end)return lvl;
                for(int i=0;i<node.length();i++){
                    char c = node[i];
                    for(char& a:nxt){
                        if(c==a)continue;
                        node[i] = a;
                        if(val.count(node))q.push(node);
                        node[i]=c;
                    }
                }
            }
        }
        return -1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        val = unordered_set<string>(bank.begin(),bank.end());
        if(!val.count(end))return -1;
        return bfs(start, end);
    }
};