class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count=0;
        unordered_set<int> vis;
        queue<int> q;
        q.push(0);
        vis.insert(0);
        count++;
        while(!q.empty()){
            int temp = q.front();q.pop();
            for(int& i:rooms[temp]){
                if(vis.find(i)==vis.end()){
                    count++;
                    vis.insert(i);
                    q.push(i);
                }
            }
        }
        return count==rooms.size();
    }
};