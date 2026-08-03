class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
     int n = arr.size();
     
     if(k > n) return -1;
     
     priority_queue<int>p;
     
     for(int x : arr){
         p.push(x);
         
         while(p.size() > k){
             p.pop();
         }
     }
       
       return  p.empty() ? -1 : p.top();
    }
};