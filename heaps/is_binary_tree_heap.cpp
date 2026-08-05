class Solution {
	public:
	int countNodes(Node* root){
	    if(root==NULL) return 0;
	    
	    return 1 + countNodes(root->left) + countNodes(root->right);
	}
	
	bool isCBT(Node* root , int idx , int totalNodes){
	    if(root==NULL) return true;
	    
	    if(idx >= totalNodes) return false;
	    
	    return isCBT(root->left ,2 * idx + 1 , totalNodes ) && isCBT(root->right ,2 * idx + 2 , totalNodes );
	}
	bool check(Node* root) {
		if (root == NULL)
			return true;
		
		if (root->left == NULL && root->right == NULL)
			return true;
		
		if (root->right == NULL) {
			return (root->data >= root->left->data) && check(root->left);
		}
		
		return (root->data >= root->left->data) && (root->data >= root->right->data) && check(root->left) && check(root->right);
		
	}
	bool isHeap(Node* tree) {
		int totalNodes = countNodes(tree);
		
		return isCBT(tree , 0 , totalNodes) && check(tree);
		
	}
};
