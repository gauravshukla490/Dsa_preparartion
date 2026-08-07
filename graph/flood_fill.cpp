class Solution {
public:
    vector<pair<int,int>>dir={{0 , -1},{0 , 1},{-1 , 0},{1 , 0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int original_color = image[sr][sc];

        if(original_color == color) return image;

        queue<pair<int,int>>q;
        q.push({sr , sc});
        image[sr][sc]=color;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto it : dir){
                int new_row = row + it.first;
                int new_col = col + it.second;

                if(new_row < n && new_row >= 0 && new_col >=0 && new_col < m && image[new_row][new_col] == original_color){
                    image[new_row][new_col]=color;
                    q.push({new_row , new_col});
                }
            }
        }
        return image;
    }
};