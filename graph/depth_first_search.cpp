class Solution {
  public:
    vector<int>ans;
    void solve(int curr , vector<int>&vis , vector<vector<int>>& adj){
       for(auto neighbour : adj[curr]){
           if(vis[neighbour]!=1){
               ans.push_back(neighbour);
               vis[neighbour]=1;
               solve(neighbour , vis , adj);
           }
       }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>vis(n,0);
         vis[0]=1;
        ans.push_back(0);
        solve(0 , vis , adj);
        return ans;
    }
};