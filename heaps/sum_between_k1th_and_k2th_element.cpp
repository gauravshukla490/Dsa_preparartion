class Solution {
  public:
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
    int n = arr.size();
    if(n==0) return 0;
    
     priority_queue<int>p;
     
     for(int i=0;i<n;i++){
         p.push(arr[i]);
         
         while(p.size() >= k2){
             p.pop();
         }
     }
     int ans = 0;
     
     while(p.size() > k1){
         ans += p.top();
         p.pop();
     }
       return ans; 
    }
};