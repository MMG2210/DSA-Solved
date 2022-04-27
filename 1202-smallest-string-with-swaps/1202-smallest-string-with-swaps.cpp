class Solution {
public:
    int findPar(int i, vector<int>& par){
        if(par[i]==i)return i;
        else return par[i]=findPar(par[i],par);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> par(s.size());
        for(int i=0;i<s.size();i++)par[i]=i;
        
        for(auto& p:pairs){
            int u=p[0],v=p[1];
            int uPar=findPar(u,par);
            int vPar=findPar(v,par);
            if(vPar!=uPar){
                par[uPar]=vPar;
            }
        }
        
        vector<vector<int>> group(s.size());
        
        for(int i=0;i<s.size();i++){
            int parent=findPar(i,par);
            group[parent].push_back(i);
        }
        
        string res=s;
        
        for(auto& g:group){
            string temp="";
            int j=0;
            
            for(auto& val:g){
                temp+=s[val];
            }
            
            sort(temp.begin(),temp.end());
            
            for(auto& val:g){
                res[val]=temp[j++];
            }
            
        }
        
        return res;
    }
};