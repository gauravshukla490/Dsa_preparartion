class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n==0) return -1;

        priority_queue<vector<int>,vector<vector<int>> , greater<vector<int>>>p;

        int col = 0;

        for(int i = 0 ; i < n;i++){
            p.push({matrix[i][col] , i , col});
        }

        int cnt = 0;

        while(cnt < k-1 && !p.empty()){
            int row = p.top()[1];
            int col = p.top()[2];
            p.pop();
              cnt++;

           if((col + 1)< n){
            p.push({matrix[row][col+1] , row , col + 1});
          
           }
        }

        return !p.empty() ? p.top()[0] : -1;
    }
};