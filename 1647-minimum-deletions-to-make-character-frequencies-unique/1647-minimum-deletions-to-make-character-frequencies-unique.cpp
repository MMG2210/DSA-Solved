class Solution {
public:
    // int minDeletions(string s) {
    //     int res=0;
    //     vector<int> v(1e5+10, 0),alp(26,0);
    //     for(char& c:s)alp[c-'a']++;
    //     sort(alp.begin(),alp.end());
    //     for(int i=0; i<26; i++){
    //         if(alp[i] && !v[alp[i]]){
    //             v[alp[i]]=1;
    //         }else if(v[alp[i]]){
    //             int curr = alp[i];
    //             while(curr>0 && v[curr])curr--;
    //             if(curr)v[curr]=1;
    //             res+=alp[i]-curr;
    //         }
    //     }
    //     return res;
    // }
    int minDeletions(string s){
        int res=0;
        priority_queue<int> pq;
        vector<int> freq(26,0);
        for(char& c:s)freq[c-'a']++;
        for(int i=0;i<26; i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        
        while(pq.size()>1){
            int top = pq.top();pq.pop();
            if(top==pq.top()){
                res++;
                top--;
                if(top>0)pq.push(top);
            }
        }
        return res;
    }
};