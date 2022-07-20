class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res=0,sz=s.size();
        vector<vector<int>> alp(26);
        for(int i=0;i<sz;i++){
            alp[s[i]-'a'].push_back(i);
        }
        for(auto& w:words){
            int x=-1;
            bool found=true;
            for(char& c:w){
                auto it=upper_bound(alp[c-'a'].begin(),alp[c-'a'].end(),x);
                if(it==alp[c-'a'].end())found=false;
                else x=*it;
                if(!found)break;
            }
            if(found)res++;
        }
        return res;
    }
};