class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> res(n,0);
        stack<int> dayInd;
        
        res[n-1]=0;
        dayInd.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!dayInd.empty() && t[dayInd.top()]<=t[i])
            {
                if(!dayInd.empty())
                    dayInd.pop(); 
            }
            if(dayInd.empty()){res[i]=0; dayInd.push(i);continue;}
            res[i]=dayInd.top()-i;
            dayInd.push(i);
        }
        
        return res;
    }
};