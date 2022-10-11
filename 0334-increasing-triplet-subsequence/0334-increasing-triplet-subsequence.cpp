class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int c1=INT_MAX, c2=INT_MAX;
        for(int& x:a){
            if(x<=c1){
                c1=x;
            }
            else if(x<=c2){
                c2=x;
            }
            else return true;
        }
        return false;
    }
};