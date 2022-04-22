class MyHashMap {
private:
    vector<int> hash = vector<int>(1e6+2);
public:
    MyHashMap() {
       for(int i=0;i<hash.size();i++){
           hash[i]=-1;
       }
    }
    
    void put(int key, int value) {
        hash[key]=value;
    }
    
    int get(int key) {
        return hash[key]>=0?hash[key]:-1;
    }
    
    void remove(int key) {
        hash[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */