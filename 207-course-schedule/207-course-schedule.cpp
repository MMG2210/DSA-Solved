class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count=0;
        vector<int> inDegree(numCourses,0);
        queue<int> q;
        vector<vector<int>> graph(numCourses,vector<int>());
        for(auto pre:prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for(int i = 0; i<inDegree.size(); i++)
            if(!inDegree[i])q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto it : graph[node]){
                inDegree[it]--;
                if(!inDegree[it])q.push(it);}
        }
        return count==numCourses;
    }
};