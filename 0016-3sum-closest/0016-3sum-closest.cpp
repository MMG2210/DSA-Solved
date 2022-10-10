class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {      
        if(a.size()<3)return 0;
        int closest = a[0]+a[1]+a[2];
        sort(a.begin(),a.end());
        for(int f=0;f<a.size()-2;f++){
            if(f && a[f]==a[f-1])continue;
            int s = f+1, t=a.size()-1;
            while(s<t){
                int sum = a[f]+a[s]+a[t];
                if(sum==target)return sum;
                if(abs(target-sum)<abs(target-closest))closest=sum;
                if(sum>target)t--;
                else s++;
            }
        }
        return closest;
    }
};