class Solution {
  public:
    Node* targetNode;
    
    void findTarget(Node* root , int target){
        if(root==NULL) return;
        
        if(root->data ==  target){
            targetNode=root;
            return;
        }
        
        findTarget(root->left , target);
        findTarget(root->right , target);
    }
    void markParent(Node* root , unordered_map<Node* , Node*>&parent){
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    int minTime(Node* root, int target) {
       if(root==NULL) return 0;
       unordered_map<Node* , Node*>parent;
       markParent(root , parent);
        unordered_map<Node* , bool>visited;
       
       findTarget(root , target);
       
       queue<Node*>q;
       q.push(targetNode);
       visited[targetNode]=true;
       
       int cnt=0;
       
       while(!q.empty()){
           int size= q.size();
           bool burned=false;
           
           for(int i=0;i<size;i++){
               Node* curr= q.front();
               q.pop();
          
               if(curr->left && !visited[curr->left]){
                   q.push(curr->left);
                   visited[curr->left]=true;
                   burned=true;
               }
               
               if(curr->right && !visited[curr->right]){
                   q.push(curr->right);
                   visited[curr->right]=true;
                   burned=true;
               }
               
               if(parent[curr] && !visited[parent[curr]]){
                   q.push(parent[curr]);
                   visited[parent[curr]]=true;
                   burned=true;
               }
              
           }
           if(burned) cnt++;
            
       }
        return cnt;
    }
};