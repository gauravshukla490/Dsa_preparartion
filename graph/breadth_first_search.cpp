class Solution {
  public:
    vector<int>ans;
    
    void solve(int start , vector<int>&vis , vector<vector<int>>& adj){
        queue<int>q;
        vis[start]=1;
        q.push(start);
        ans.push_back(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neighbour : adj[node]){
                if(!vis[neighbour]){
                    ans.push_back(neighbour);
                    vis[neighbour]=1;
                    q.push(neighbour);
                }
            }
            
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        int start = 0;
        solve(start , vis , adj);
        return ans;
    }
};