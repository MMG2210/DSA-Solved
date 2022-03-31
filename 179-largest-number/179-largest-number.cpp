class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        vector<string> cache;
        for(int it : nums)
            cache.push_back(to_string(it));
        sort(cache.begin(),cache.end(),[](string &s1, string &s2){return s1+s2>s2+s1;});
        //This sorts the string vector in descending order
        for(auto &i:cache){
            res+=i;
        }
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
    /*string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }*/
};