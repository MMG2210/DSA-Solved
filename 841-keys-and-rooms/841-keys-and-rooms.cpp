class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> vis;
        queue<int> q;
        q.push(0);
        vis.insert(0);
        while(!q.empty()){
            int temp = q.front();q.pop();
            for(int& i:rooms[temp]){
                if(vis.find(i)==vis.end()){
                    vis.insert(i);
                    q.push(i);
                }
            }
        }
        return vis.size()==rooms.size();
    }
};