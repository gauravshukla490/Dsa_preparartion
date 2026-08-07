class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
     int n = isConnected.size();
      vector<vector<int>>adj(n);
      vector<int>vis(n,0);

     for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(isConnected[i][j] == 1 && i!=j){
                 adj[i].push_back(j);
            }
        }
     }   

     int cnt = 0;
     queue<int>q;

     for(int i = 0 ; i < n ; i++){
        
        if(vis[i]!=1){
            vis[i]=1;
            cnt++;
            q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(vis[it]!=1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
     }
     return cnt;
    }
};