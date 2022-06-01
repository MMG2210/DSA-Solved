class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size(), size=1<<k, count=0, hash=0, allOnes=~size;
        vector<bool> set(size,false);
        
        for(int i=0;i<n;i++){
            hash=((hash<<1)&allOnes)|(s[i]-'0');
            if(i>=k-1 && !set[hash]){
                count++;
                set[hash]=true;
            }
        }
        
        return size==count;
    }
};