class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
    vector<vector<int>>adj(V);
    vector<int>vis(V , 0);
    
    for(int i = 0 ; i < edges.size() ; i++){
        int  first = edges[i][0];
        int second = edges[i][1];
        
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    
    queue<int>q;
     int cnt = 0;
     vector<vector<int>>ans;
     
    for(int i = 0 ; i < V ; i++){
        vector<int>temp;
        if(vis[i]!=1){
            vis[i]=1;
            temp.push_back(i);
            q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(vis[it]!=1){
                    vis[it]=1;
                    temp.push_back(it);
                    q.push(it);
                }
            }
        }
        
        if(temp.size() != 0) ans.push_back(temp);
    }
    return ans;
    }
};
