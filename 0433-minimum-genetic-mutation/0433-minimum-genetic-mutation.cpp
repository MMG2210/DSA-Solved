#define F first
#define S second
class Solution {
public:
    unordered_set<string> val;
    int bfs(string& start, string& end){
        queue<pair<string,int>> q;//Queue of (string and its level)
        q.push({start,0});
        vector<char> nxt;
        nxt.push_back('A');nxt.push_back('C');nxt.push_back('G');nxt.push_back('T');
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();q.pop();
                if(node.F == end)return node.S;
                for(int i=0;i<node.F.length();i++){
                    char c = node.F[i];
                    for(char& a:nxt){
                        if(c==a)continue;
                        node.F[i] = a;
                        if(val.count(node.F))q.push({node.F,node.S+1});
                        node.F[i]=c;
                    }
                }
            }
        }
        return 1e9;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        val = unordered_set<string>(bank.begin(),bank.end());
        if(!val.count(end))return -1;
        int res = bfs(start, end);
        return res==1e9?-1:res;
    }
};