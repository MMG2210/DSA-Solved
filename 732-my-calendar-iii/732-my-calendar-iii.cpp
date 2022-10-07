#define F first
#define S second
class MyCalendarThree {
public:
    map<int,int> cnt = {{-1,0}};
    int res=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        auto s = cnt.emplace(start,(--cnt.upper_bound(start))->S);
        auto e = cnt.emplace(end,(--cnt.upper_bound(end))->S);
        for(auto i = s.F;i!=e.F;i++){
            res = max(res,++(i->S));
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */