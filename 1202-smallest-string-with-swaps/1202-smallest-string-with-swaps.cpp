class Solution {
public:
    int findParent(int a,vector<int> &parent)
{
    if(a == parent[a]) return a;
    
    return parent[a] = findParent(parent[a],parent);
}

string smallestStringWithSwaps(string str, vector<vector<int>>& pairs) {
    
    int n = str.size();
    vector<int> parent(n,0);
    
    for(int i = 0;i<n;i++){
        parent[i] = i;
    }
    
    for(auto x: pairs){
        int u = x[0];
        int v = x[1];
        
        int p1 = findParent(u,parent);
        int p2 = findParent(v,parent);
        
        if(p1!=p2)
            parent[p1] = p2;
    }
    
    vector<vector<int>> v(n);
    for(int i = 0;i<n;i++){
        int u = findParent(i,parent);
        
        v[u].push_back(i);
    }
  
    for(auto x: v){
        string ss;int j = 0;
        
        for(auto y : x){
            ss += str[y];
        }
        
        sort(ss.begin(),ss.end());
        
        for(auto y: x){
            str[y] = ss[j++];
        }
        
    }
    
    return str;

}

};