class Solution {
public:
    int cnt[26], maxcnt = 0, e = 0,sz;
    int leastInterval(vector<char>& tasks, int n) {
        memset(cnt,0,sizeof(cnt));
        sz=tasks.size();
        for (char c : tasks) cnt[c-'A']++;
        for (int i = 0; i < 26; i++) maxcnt = max(maxcnt, cnt[i]);
        for (int i = 0; i < 26; i++) 
            if (cnt[i] == maxcnt) e++;
        return max(sz, (maxcnt-1)*(n+1) + e);
    }
};