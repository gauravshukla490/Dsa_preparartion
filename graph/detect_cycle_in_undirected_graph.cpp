class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adj(V);
       vector<int>vis(V,0);
       
       for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
         queue<pair<int,int>>q;
         
        for(int i = 0 ; i < V ; i++){
            
            if(vis[i]) continue;
            
            q.push({i , -1});
            vis[i]=1;
            
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                
                for(auto it : adj[node]){
                    
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it , node});
                    }
                    else if(parent != it){
                        return true;
                        break;
                    }
                }
            }
        }
        return false;
    }
};