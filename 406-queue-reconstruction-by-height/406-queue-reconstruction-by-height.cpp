bool comp(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0])return a[0]>b[0];
    else return a[1]<b[1];
}


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        vector<vector<int>> res;
        for(int i=0;i<people.size();i++){
            int idx = people[i][1];
            res.insert(res.begin()+idx, people[i]);
        }
        return res;
    }
};