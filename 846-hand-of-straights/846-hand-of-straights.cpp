class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int,int>m;
        for(auto it: hand){
            m[it]++;
        }
        for(auto it: m){
            if(m[it.first]>0){
                for(int i = 1; i<groupSize; i++){
                    m[it.first+i] -= m[it.first];
                    if(m[it.first+i]<0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};