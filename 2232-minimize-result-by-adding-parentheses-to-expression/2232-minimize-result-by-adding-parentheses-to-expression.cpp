class Solution {
public:
    int evaluate(string e, int i,int j, int p){
        int a=1;
        if(i>0) a=stoi(e.substr(0,i));
        int b=stoi(e.substr(i,p-i));
        int c=stoi(e.substr(p+1,j-p));
        int d=1;
        if(j+1<e.size()) d=stoi(e.substr(j+1,e.size()-j));
        return a*(b+c)*d;
    }
    string minimizeResult(string e) {
        int p=0;
        for(p=0;p<e.size();p++){
            if(e[p]=='+')
                break;
        }
        int globMin=INT_MAX;
        string res="";
        for(int i=0;i<p;i++){
            for(int j=p+1;j<e.size();j++){
                int val = evaluate(e,i,j,p);
                if(val<globMin){
                    globMin=val;
                    res=e;
                    res.insert(j+1,1,')');
                    res.insert(i,1,'(');
                }
            }
        }
        return res;
    }
};