class KthLargest {
     priority_queue<int , vector<int>, greater<int>>p;
     int cnt;
public:
    KthLargest(int k, vector<int>& nums) {
       cnt = k;
      int n = nums.size();
     
       for(int i=0 ; i<n ; i++){
        p.push(nums[i]);

        while(p.size() > k){
            p.pop();
        }
      }  
     
    }
    
    int add(int val) {

        p.push(val);

        while(p.size() > cnt){
            p.pop();
        }

        return p.top();
    }
};