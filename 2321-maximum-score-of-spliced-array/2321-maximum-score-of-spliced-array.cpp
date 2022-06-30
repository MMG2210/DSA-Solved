class Solution {
public:
    int getMax(vector<int>& n1, vector<int>& n2){
        int i=0,sum1=0,sum2=0,diff=0;
        while(i<n1.size()){
            if(sum1>sum2)sum1=sum2=0;
            else{
                diff = max(diff, sum2-sum1);
                sum1+=n1[i];
                sum2+=n2[i];
                i++;
            }
            
        }
        return max(diff,sum2-sum1);
    }
    
    int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
        int leftMax = accumulate(n1.begin(),n1.end(),0)+getMax(n1,n2);
        int rightMax = accumulate(n2.begin(),n2.end(),0)+getMax(n2,n1);
        return max(leftMax, rightMax);
    }
};