class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    
    bool even;
    
    MedianFinder() {
        even = true;
    }
    
    void addNum(int num) {
        
        if(even){
            
            large.push(num);
            small.push(large.top());
            large.pop();
            
        }
        else{
            
            small.push(num);
            large.push(small.top());
            small.pop();
            
        }
        even=!even;
    }
    
    double findMedian() {
        
        if(even)
            return (small.top()+large.top())/2.0;
        
        else
            return small.top();
    }
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */