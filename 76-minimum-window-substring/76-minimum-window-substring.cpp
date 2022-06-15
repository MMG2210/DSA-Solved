class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128,0);
        for(auto& ch:t)mp[ch]++;
        int counter=t.size(),i=0,j=0,d=INT_MAX,start=0;
        while(j<s.size()){
            if(mp[s[j++]]-->0)counter--;
            while(counter==0){
                if(j-i<d)d=j-(start=i);
                if(mp[s[i++]]++==0)counter++;
            }
        }
        
        return d==INT_MAX?"":s.substr(start,d);
    }
};