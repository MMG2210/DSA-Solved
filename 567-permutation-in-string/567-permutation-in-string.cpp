class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> perm,temp;
        int n=s2.size(),i=0,j=0,k=s1.size(),cnt=0;
        for(char& c:s1){
            perm[c]++;
        }
        
        while(j<n){
            if(cnt<k)temp[s2[j]]++,cnt++;
            if(cnt==k){
                if(temp==perm)return true;
                else{
                    if(temp[s2[i]]==1)temp.erase(s2[i]);
                    else temp[s2[i]]--;
                    i++;
                    cnt--;
                }
            }
            j++;
        }
        
        return false;
    }
};