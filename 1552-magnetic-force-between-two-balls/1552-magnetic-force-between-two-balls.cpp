class Solution {
public:
    
    bool isValid(vector<int>& position, int m, int minDis){
        int count=1, first=position[0];
        
        for(int i=1;i<position.size();i++){
            if(position[i]-first>=minDis){
                first=position[i];
                count++;
            }
            if(count==m)return true;
        }
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int res=INT_MIN, n=position.size();
        
        int l=1, r=position[n-1]-position[0];
        
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isValid(position,m,mid)){res=max(res,mid); l=mid+1;}
            else r=mid-1;
        }
        
        return res;
    }
};