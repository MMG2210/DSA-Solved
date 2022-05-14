class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res=0;
        string temp = to_string(num);
        for(int i=0;i<temp.size();i++){
            if(i+k-1>=temp.size())break;
            string t=temp.substr(i,k);
            int n=stoi(t);
            if(!n)continue;
            if(num%n==0)res++;
        }
        return res;
    }
};