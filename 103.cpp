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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> levels;

        queue<TreeNode *> q;
        if (root)
            q.push(root);

        while (!q.empty())
        {
            levels.push_back(vector<int>());
            for (int i = 0, n = q.size(); i < n; i++)
            {
                auto *front = q.front();
                levels.back().push_back(front->val);
                q.pop();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            if (levels.size() % 2 == 0)
            {
                reverse(levels.back().begin(), levels.back().end());
            }
        }
        return levels;
    }
};