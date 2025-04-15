// 144. Binary Tree Preorder Traversal
void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    result[(*index)++] = root->val;
    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // Constraint: max 100 nodes
    int index = 0;
    preorder(root, result, &index);
    *returnSize = index;
    return result;
}

// 99. Binary Tree Inorder Traversal 
void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    inorder(root->left, result, index);         
    result[(*index)++] = root->val;             
    inorder(root->right, result, index);        
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // Max 100 nodes based on constraint
    int index = 0;
    inorder(root, result, &index);
    *returnSize = index;
    return result;
}
