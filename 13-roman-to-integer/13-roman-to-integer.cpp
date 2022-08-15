class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        unordered_map<char,int> val;
        val['I']=1;
        val['V']=5;
        val['X']=10;
        val['L']=50;
        val['C']=100;
        val['D']=500;
        val['M']=1000;
        res = val[s.back()];
        for(int i=s.size()-2;i>=0;i--){
            if(val[s[i]]<val[s[i+1]]){
                res-=val[s[i]];
            }
            else{
                res+=val[s[i]];
            }
        }
        return res;
    }
};