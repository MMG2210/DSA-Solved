class Solution {
public:
    vector<int> getCounts(string& w){
        vector<int> res(26,0);
        for(char& c:w)res[c-'a']++;
        return res;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> cntr(26,0),temp(26,0);
        int i;
        for(string& w:words2){
            temp=getCounts(w);
            for(i=0;i<26;i++)cntr[i]=max(cntr[i],temp[i]);
        }
        for(string& w:words1){
            temp=getCounts(w);
            for(i=0;i<26;i++)if(cntr[i]>temp[i])break;
            if(i==26)res.push_back(w);
        }
        return res;
    }
};