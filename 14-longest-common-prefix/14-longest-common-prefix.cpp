class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res=strs[0];
        for(int i=1;i<strs.size();i++){
            string temp="";
            for(int j=0;j<min(strs[i].length(),res.length());j++){
                if(strs[i][j]!=res[j])break;
                temp.push_back(strs[i][j]);
            }
            res=temp;
        }
        return res;
    }
};