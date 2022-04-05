class Solution {
    private:
    unordered_map<string, set<string>> graph;
    unordered_map<string, string> emailToName;
    unordered_map<string, bool> visited;
    
public:
    void dfs(string email, set<string> &emailSet){
        if(visited[email])
            return;
        visited[email] = true;
        emailSet.insert(email);
        for(string adj : graph[email]){
            dfs(adj, emailSet);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // solving through graph.
        // build adjacency list
        for(vector<string> &account : accounts){
            string name = account[0];
            string firstemail = account[1];
            visited[firstemail] = false;
            emailToName[firstemail] = name;
            for(int i=2;i<size(account);i++){
                visited[account[i]] = false;
                emailToName[account[i]] = name;
                
                graph[account[i]].insert(firstemail);
                graph[firstemail].insert(account[i]);
            }
        }
        
        vector<vector<string>> ans;
        // for each account => dfs
        for(int i=0;i<size(accounts);i++){
            // for each email
            for(int j=1;j<size(accounts[i]);j++){
                if(visited[accounts[i][j]] == false){
                    set<string> emailSet; // collect all associated unique emails
                    dfs(accounts[i][j], emailSet);
                    vector<string> tmp(emailSet.begin(), emailSet.end());
                    tmp.insert(tmp.begin(), emailToName[accounts[i][j]]);
                    ans.emplace_back(tmp);
                }
            }
        }
        
        return ans;
    }
};