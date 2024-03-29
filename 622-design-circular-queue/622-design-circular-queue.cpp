class MyCircularQueue {
public:
    int sz,cnt=0,head;
    vector<int> q;
    MyCircularQueue(int k) {
        sz = k;
        head=0;
        q.resize(sz);
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        q[(head+cnt)%sz]=value;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        head = (head+1)%sz;
        cnt--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:q[head];
    }
    
    int Rear() {
        return isEmpty()?-1:q[(head+cnt-1)%sz];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */