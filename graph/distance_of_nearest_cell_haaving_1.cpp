class Solution {
  public:
    vector<pair<int,int>>directions={{0 , -1},{0 , 1},{1 , 0},{-1 , 0}};
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j]=-1;
                }
            }
        }
        int dist = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
              for(auto it : directions){
                int new_row = row + it.first;
                int new_col = col + it.second;
                
                if(new_row >=0 && new_row < n && new_col >=0 && new_col < m && grid[new_row][new_col]==0){
                    grid[new_row][new_col] = dist + 1;
                    q.push({new_row , new_col});
                }
                
              }
            }
            
            dist++;
        }
         for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == -1){
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }
        return grid;
    }
};