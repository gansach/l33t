/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void dfs(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &paths)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (sum == root->val)
            {
                path.push_back(root->val);
                paths.push_back(path);
                path.pop_back();
            }
        }

        path.push_back(root->val);
        dfs(root->left, sum - root->val, path, paths);
        dfs(root->right, sum - root->val, path, paths);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> paths;

        vector<int> path;
        dfs(root, targetSum, path, paths);

        return paths;
    }
};