class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res=1;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord)==dict.end())return res-1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                string word = q.front();q.pop();
                dict.erase(word);
                if(word==endWord)return res;
                for(int j=0;j<word.size();j++){
                    char c = word[j];
                    for(int k=0;k<26;k++){
                        word[j]=k+'a';
                        if(dict.find(word)!=dict.end())q.push(word);
                    }
                    word[j]=c;
                }
            }
            res++;
        }
        return 0;
    }
};