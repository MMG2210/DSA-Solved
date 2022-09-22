class Solution {
public:
    string reverseWords(string s) {
        string temp = "", res="";
        for(char& c:s){
            if(c!=' ')temp.push_back(c);
            else{
                reverse(temp.begin(),temp.end());
                res.append(temp);
                res.push_back(' ');
                temp="";
            }
        }
        reverse(temp.begin(),temp.end());
        res.append(temp);
        return res;
    }
};