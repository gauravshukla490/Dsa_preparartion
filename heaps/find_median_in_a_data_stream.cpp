class MedianFinder {
public:
    priority_queue<int , vector<int> , greater<int>>right;
    priority_queue<int>left;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(left.empty() || num <= left.top()){
         left.push(num);
       }
       else right.push(num);

       if(left.size() > right.size() + 1){
          right.push(left.top());
          left.pop();
       }
       else if(right.size() > left.size() ){
        left.push(right.top());
        right.pop();
       }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return (double)(left.top() + right.top()) / 2;
        }

        else if(left.size() > right.size()){
            return (double)(left.top());
        }
        else return (double)(right.top());
    }
};