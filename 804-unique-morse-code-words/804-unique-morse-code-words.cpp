class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> used;
        for(string& s:words){
            string temp="";
            for(char& c:s){
                temp+=morse[c-'a'];
            }
            used.insert(temp);
        }
        return used.size();
    }
};