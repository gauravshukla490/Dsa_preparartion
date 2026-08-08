class Solution {
  public:
    vector<pair<int,int>>directions={{0 , -1},{0 , 1},{-1 , 0},{1 , 0}};
    
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int fresh = 0;
        queue<pair<int,int>>q;
        
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(mat[i][j]==2) q.push({i,j});
                
                else if(mat[i][j] == 1) fresh++;
                
                else continue;
            }
        }
        int min = 0;
        if(fresh==0) return min;
        
        while(!q.empty()){
            int size = q.size();
            
          while(size--){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(auto it : directions){
                int new_row = row + it.first;
                int new_col = col + it.second;
                
                if(new_row >=0 && new_row < n && new_col >= 0 && new_col < m && mat[new_row][new_col]==1){
                    mat[new_row][new_col] = 2;
                    fresh--;
                    q.push({new_row , new_col});
                }
            }
          } 
          min++;
          if(fresh==0) return min;
        }
        
       return fresh != 0 ? -1 : min ;
    }
};