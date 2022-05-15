#define F first
#define S second
class CountIntervals {
public:
    map<int,int> m;
    int cnt=0;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it=m.upper_bound(left);
        if(it!=m.begin()){
            auto p=prev(it);
            if(p->S>=left){
                left = p->F;
                right = max(p->S,right);
                cnt-=p->S-p->F+1;
                m.erase(p);
            }
        }
        for(;it!=m.end() && it->F<=right;m.erase(it++)){
            right=max(it->S,right);
            cnt-=it->S-it->F+1;
        }
        cnt+=right-left+1;
        m[left]=right;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */