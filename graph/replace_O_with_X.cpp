class Solution {
  public:
    vector<pair<int,int>>directions={{0 , -1},{0 , 1},{1 , 0},{-1 , 0}};
    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i = 0 ; i < n ; i++){
           if(i==0 || i== n-1){
               for(int j=0 ; j<m ; j++){
                   if(grid[i][j]=='O'){
                       grid[i][j]='#';
                       q.push({i , j});
                   }
               }
           }
           else{
               if(grid[i][0] == 'O') {
                 grid[i][0] = '#';
                  q.push({i,0});
                }

          
               if(grid[i][m-1] == 'O') {
                 grid[i][m-1] = '#';
                 q.push({i,m-1});
                }
           }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(auto it : directions){
                int new_row = row + it.first;
                int new_col = col + it.second;
                
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col]=='O'){
                    grid[new_row][new_col] = '#';
                    q.push({new_row , new_col});
                }
            }
            
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                if(grid[i][j]=='#'){
                    grid[i][j]='O';
                }
            }
        }
       
    }
};