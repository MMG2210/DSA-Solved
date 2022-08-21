class Solution {
public:
    vector<int> movesToStamp(string s, string t) {
        vector<int> res;
        int total_stamp=0,turn_stamp=-1;
        while(turn_stamp){
            turn_stamp=0;
            for(int sz=s.size();sz>0;--sz){
                for(int i=0;i<=s.size()-sz;i++){
                    string new_stamp = string(i,'*') + s.substr(i,sz) + string(s.size()-sz-i,'*');
                    auto pos = t.find(new_stamp);
                    while(pos != string::npos){
                        res.push_back(pos);
                        turn_stamp+=sz;
                        fill(begin(t)+pos,begin(t)+pos+s.size(),'*');
                        pos = t.find(new_stamp);
                    }
                }
            }
            total_stamp+=turn_stamp;
        }
        reverse(begin(res),end(res));
        return total_stamp == t.size() ? res : vector<int>();
    }
};