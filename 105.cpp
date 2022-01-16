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
    TreeNode *construct(int &i, int inS, int inE, vector<int> &pre, vector<int> &in, map<int, int> &idx)
    {
        if (inS > inE)
            return NULL;

        int rootData = pre[i];

        i++;

        TreeNode *root = new TreeNode(rootData);
        root->left = construct(i, inS, idx[rootData] - 1, pre, in, idx);
        root->right = construct(i, idx[rootData] + 1, inE, pre, in, idx);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int i = 0;
        map<int, int> idx;
        for (auto itr : inorder)
            idx[itr] = i++;

        i = 0;
        return construct(i, 0, inorder.size() - 1, preorder, inorder, idx);
    }
};