class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(t.begin(),t.end());
        // sort(s.begin(),s.end());
        // return s==t;
        unordered_map<char,int> freq;
        for(char&c:t)freq[c]++;
        for(char& c:s){
            freq[c]--;
            if(freq[c]==0)freq.erase(c);
        }
        return freq.empty();
    }
};