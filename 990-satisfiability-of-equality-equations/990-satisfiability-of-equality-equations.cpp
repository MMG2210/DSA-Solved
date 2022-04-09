class Solution {
private:
    int uf[26];
public:
    int find(int x){
        if(uf[x]==x)return x;
        else return x=find(uf[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++){
            uf[i]=i;
        }
        for(string& e: equations){
            if(e[1]=='=')uf[find(e[0]-'a')]=find(e[3]-'a');
        }
        for(string& e: equations){
            if(e[1]=='!' && find(e[0]-'a')==find(e[3]-'a'))return false;
        }
        return true;
    }
};