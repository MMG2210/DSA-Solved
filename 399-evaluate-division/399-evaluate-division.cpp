class Solution {
public:
    double dfs(unordered_map<string,unordered_map<string,double>>& graph, string s1, string s2, unordered_set<string> vis){
        if(graph[s1].find(s2)!=graph[s1].end()){
            return graph[s1][s2];
        }
        for(auto it : graph[s1]){
            if(vis.find(it.first)==vis.end()){
                vis.insert(it.first);
                double dist = dfs(graph,it.first,s2,vis);
                    if(dist) {
                        graph[s1][s2] = it.second * dist;
                        return graph[s1][s2];
                    }
            }
        }
        return 0.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = (double)1/values[i];
        }//Created an adj list with edge weights as the quotient
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            unordered_set<string> vis;
            double val = dfs(graph, queries[i][0], queries[i][1], vis);
            if(!val)
                res.push_back(double(-1.0));
            else 
                res.push_back(val);
        }
        return res;
    }
};