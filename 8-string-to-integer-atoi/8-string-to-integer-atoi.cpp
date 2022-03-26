class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        if(len==0)return 0;
        int ind=0;
        while(ind<len && s[ind]==' ')
            ind++;
        bool isNegative = false;
        if(s[ind]=='-'){
            isNegative = true;
            ind++;
        }
        else if(s[ind]=='+')ind++;
        int res = 0;
        while(ind<len && isdigit(s[ind]))
        {
            int temp = s[ind]-'0';
            if (res>INT_MAX/10 || (res == (INT_MAX / 10) && temp > 7)){
                return isNegative? INT_MIN : INT_MAX;
            }
            res = res*10 + temp;
            ind++;
        }
        if(isNegative)res*=-1;
        return res;
    }
};