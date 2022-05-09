class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},ans;
        if(digits=="")return ans;
        string temp="";
        rec(letters,0,digits,ans,temp);
        return ans;
    }
    void rec(vector<string>& letter, int i,string digits, vector<string>& ans, string temp){
        if(i == size(digits)){ans.push_back(temp);return;}
        else{
        for(auto it : letter[digits[i]-'2'])
            rec(letter, i+1, digits, ans, temp+it);}
    }
};