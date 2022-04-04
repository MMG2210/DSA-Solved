/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void findEmployee(vector<Employee*> employees, int id, queue<Employee*>& q){
        for(auto& i:employees){
            if(i->id==id){q.push(i);break;}
        }
        return;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int res=0;
        queue<Employee*> q;
        unordered_set<int> vis;
        for(auto& i:employees){
            if(i->id==id){q.push(i);vis.insert(i->id);break;}
        }
        while(!q.empty()){
            Employee* t = q.front();q.pop();
            vis.insert(t->id);
            res+=t->importance;
            for(auto& i:t->subordinates){
                if(vis.find(i)==vis.end()){
                    vis.insert(i);
                    findEmployee(employees,i,q);
                }
            }
        }
        return res;
    }
};