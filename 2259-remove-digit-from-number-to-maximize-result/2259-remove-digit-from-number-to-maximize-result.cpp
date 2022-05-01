class Solution {
public:
    string removeDigit(string number, char digit) {
        string res="";
        int n=number.size();
        //vector<string> combos;
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string temp = number.substr(0,i)+number.substr(i+1,n);
                //combos.push_back(temp);
                res=max(temp,res);
            }
        }
        
        //res=combos[0];
        
//         int csize=combos.size();
        
//         sort(combos.begin(), combos.end());
        // for(string& c:combos){
        //     res=max(res,c);
        // }
        
        return res;
    }
};