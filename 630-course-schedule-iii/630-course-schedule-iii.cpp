bool comp(vector<int> &a, vector<int>& b){
        if(a[1]==b[1])return a[0]<b[0];
        else return a[1]<b[1];
    }
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        int now=0;
        priority_queue<int> pq;
        for(auto& v:courses){
            pq.push(v[0]);
            now+=v[0];
            if(now>v[1]){
                now-=pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};