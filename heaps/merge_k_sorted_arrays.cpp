class Solution {
  public:
    struct compare {
        
        bool operator()(vector<int>a , vector<int>b){
            return a[0] > b[0];
        }
    };
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        priority_queue<vector<int>, vector<vector<int>> , compare>p;
        int n = mat.size();
        
        for(int i = 0 ; i < n ; i++){
            if(!mat[i].empty()) p.push({mat[i][0] , i , 0});
        }
        
        vector<int>ans;
        
        while(!p.empty()){
            vector<int>temp = p.top();
            p.pop();
            
            int row = temp[1];
            int col = temp[2];
            
            ans.push_back(temp[0]);
            if(col + 1 < mat[row].size()) p.push({mat[row][col+1] , row , col + 1});
        }
        
        return ans;
    }
};