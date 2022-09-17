class Solution {
public:
    bool isPalindrome(string &str, int l, int h){ // O(m) => 300
        while(l<=h){
            if(str[l] != str[h])
                return false;
            l++, h--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> frw_mp, rev_mp;

        for(int i=0; i<words.size(); i++){ // O(n*m) => 5000*300 = 1500000
            reverse(words[i].begin(), words[i].end()); // O(m) => 300
            rev_mp[words[i]] = i;  // Storing idx of each word after reversing the word
            
            reverse(words[i].begin(), words[i].end()); // O(m) => 300
            frw_mp[words[i]] = i;  // Storing idx of each word w/o reverse
        }

        set<vector<int>> ans_st;
        if(frw_mp.find("") != frw_mp.end()){// O(1)  // If there exist empty string in list of words
            int idx = frw_mp[""];
            for(int i=0; i<words.size(); i++){ // O(n*m) => 5000*300 = 1500000
                if(idx == i) continue;
                if(isPalindrome(words[i], 0, words[i].length()-1)){ // O(m) => 300 // Count it for palindromic strings both forward & reverse manner which are themselves palindrome 
                    ans_st.insert({i, idx});
                    ans_st.insert({idx, i});
                }
            }  
        }

        for(int i=0; i<words.size(); i++){ // O(n)*O(m*(m-k)) => 5000 * 300 * 300
            string str = "";

            for(int j=0; j<words[i].size(); j++){ // O(m*(m-k)) => 300 * 300 // Traversing each word char-by-char in forward manner
                str += words[i][j];

                // If reverse of str exist in the reverse_words map && reverse_words's idx not same as i && word after jth idx(traversed till now AND added to str) to the end is itself a palindrome string
                if(rev_mp.find(str) != rev_mp.end() && rev_mp[str] != i && isPalindrome(words[i], j+1, words[i].size()-1)) // O(1)+O(1)+O(m-k) => 300
                    ans_st.insert({i, rev_mp[str]});
            }

            str = "";
            for(int j=words[i].size()-1; j>=0; j--){ // O(m*(m-k)) => 300 * 300 // Traversing each word char-by-char in reverse manner
                str += words[i][j];

                // If reverse of str exist in the forward_words map && forward_words's idx not same as i && word before(index wise) jth idx(traversed till now AND added to str) to the end is itself a palindrome string
                if(frw_mp.find(str) != frw_mp.end() && frw_mp[str] != i && isPalindrome(words[i], 0, j-1)) // O(1)+O(1)+O(m-k) => 300
                    ans_st.insert({frw_mp[str], i});
            }
        }

        for(auto val: ans_st) // O(n)
            ans.push_back(val);

        return ans;
    }
};