class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(),res=0;
        vector<int> mask(n);
        for(int i=0; i<n; i++){
            for(char& w:words[i]){
                mask[i]|=(1<<(w-'a'));
            }
            
            for(int j=0;j<i;j++){
                if(!(mask[i]&mask[j])){
                    int prod=words[i].length()*words[j].length();
                    res=max(res,prod);
                }
            }
        }
        
        return res;
    }
};