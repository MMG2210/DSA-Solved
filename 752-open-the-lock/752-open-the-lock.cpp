class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(),deadends.end()),vis;
        if(deads.find("0000")!=deads.end())return -1;
        if(target=="0000")return 0;
        queue<string> q;
        q.push("0000");
        vis.insert("0000");
        int n,minTurns=0;
        while(!q.empty()){
            minTurns++;
            n = q.size();
            for(int i=0;i<n;i++){
                string cur = q.front();q.pop();
                for(int j=0;j<4;j++){
                    for(string& it : turns(cur,j)){
                        if(vis.find(it)==vis.end() && deads.find(it)==deads.end()){
                            if(it == target)return minTurns;
                            else{q.push(it),vis.insert(it);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
    vector<string> turns(string s, int pos){
        vector<string>res(2,s);
        res[0][pos] = '0' + ((res[0][pos] - '0') + 1)%10;
        res[1][pos] = '0' + ((res[1][pos]-'0')+10-1)%10;
        return res;
    }
};