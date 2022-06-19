class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string word) {
        auto it = A.begin();
        sort(it,A.end());
        vector<vector<string>> res;
        string cur="";
        
        for(char& c:word){
            cur+=c;
            vector<string> suggest;
            it = lower_bound(it,A.end(),cur);
            for(int i=0;i<3 && (it+i)!=A.end();i++){
                string& s = *(it+i);
                if(s.find(cur))break;
                suggest.push_back(s);
            }
            res.push_back(suggest);
        }
        
        return res;
    }
};