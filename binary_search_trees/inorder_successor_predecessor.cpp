
class Solution {
  public:
    vector<Node*>ans={NULL , NULL};
    
    void findSuc(Node* root , int key){
        while(root!=NULL){
            if(root->data > key){
                ans[1]=root;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    
    void findPre(Node* root , int key){
        while(root!=NULL){
            if(root->data < key){
                ans[0]=root;
                root=root->right;
            }
            else root = root->left;
        }
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        if(root==NULL) return ans;
        findPre( root , key);
        findSuc(root , key);
        return ans;
    }
};