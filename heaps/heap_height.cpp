class Solution {
  public:
 
    int heapHeight(int n, int arr[]) {
    if(n==0) return 0;
    if(n==1) return 1;
    int cnt=0;
    int i = 0;
    while(i < n){
        i = 2*i + 1;
         cnt++;
    }
       return cnt-1; 
    }
};