// 101. Symmetric Tree

bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// 200. Number of Islands

void dfs(char** grid, int i, int j, int rows, int cols) {
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == '0')
        return;

    grid[i][j] = '0'; 

    dfs(grid, i + 1, j, rows, cols);
    dfs(grid, i - 1, j, rows, cols);
    dfs(grid, i, j + 1, rows, cols);
    dfs(grid, i, j - 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize[0] == 0) return 0;

    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }
    return count;
}

