class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        int mod = 1e9+7, maxh = 0, maxw=0;
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        for(int i=0;i<hC.size();i++){
            if(!i){
                maxh = max(maxh,hC[i]);
            }
            if(i!=0)maxh = max(maxh, hC[i]-hC[i-1]);
            if(i==hC.size()-1)maxh = max(maxh, h-hC[i]);
            //cout<<maxh<<' ';
        }
        //cout<<"\n";
        for(int i=0;i<vC.size();i++){
            if(!i){
                maxw = max(maxw,vC[i]);
            }
            
            if(i!=0)maxw = max(maxw, vC[i]-vC[i-1]);
            if(i+1==vC.size())maxw = max(maxw, w-vC[i]);
            //cout<<maxw<<' ';
        }
        long long res=(1ll*maxh*maxw)%mod;
        //cout<<"\n";
        //cout<<"Final answers are : "<<maxh<<' '<<maxw<<' '<<res<<"\n";
        return res;
    }
};