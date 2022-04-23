class Solution {
public:
    vector<int> psum;
    Solution(vector<int>& w) {
        psum.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            psum.push_back(psum[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        int i=rand()%psum.back()+1;
        return lower_bound(psum.begin(),psum.end(),i)-psum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */