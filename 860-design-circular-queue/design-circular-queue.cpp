class MyCircularQueue {
public:
        int f;
        int b;
        int s; //curr size
        int c; //capacity
        vector<int> arr;
    MyCircularQueue(int k) { //k is capacity
        f = 0;
        b = 0;
        s = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }
    
    bool enQueue(int value) { //push
        if(s==c) return 0;
        else {
            arr[b] = value;
            b++;
            if(b == c) b = 0; //imp
            s++;
            return 1;
        }
    }
    
    bool deQueue() { //pop
        if( s == 0) return 0;
        else{
            f++;
            if(f == c) f = 0; //imp
            s--;
            return 1;
        }
    }
    
    int Front() { //front ele
        if(s == 0) return -1;
        return arr[f];
    }
    
    int Rear() { //back ele
        if(s == 0) return -1;
        else{
            if(b == 0) return arr[c-1]; //imp
            return arr[b-1];
        }
    }
    
    bool isEmpty() { //khali toh nahi
        if(s == 0) return 1;
        else return 0;
    }
    
    bool isFull() { //bhara toh nahi
        if(s == c) return 1;
        else return 0;
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