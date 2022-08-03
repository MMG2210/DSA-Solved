class MyCalendar {
public:
    set<pair<int,int>> booked;
    MyCalendar() {
        
    }
    
    bool found(int st, int end, int k){
        while(st<=end){
            int mid=st + (end-st)/2;
            if(mid==k)return true;
            else if(mid>k)end=mid-1;
            else st=mid+1;
        }
        return false;
    }
    
    bool book(int s1, int e1) {
        // for(auto it:booked){
        //     int lS=it.first;
        //     int lE=it.second;
        //     // if(lE+1==start){
        //     //     booked.erase({lS,lE});
        //     //     booked.insert({lS,end-1});
        //     //     return true;
        //     // }
        //     if(lE<start)continue;
        //     for(int i=start;i<end;i++){
        //         if(found(lS, lE, i))return false;
        //     }
        // }
        for(auto e:booked){
            int s2=e.first, e2=e.second;
            if(s2<e1 && s1<e2)return false;
        }
        booked.insert({s1,e1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */