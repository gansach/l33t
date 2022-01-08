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
    bool areIdentical(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        else if (root1 == NULL || root2 == NULL)
            return false;

        if (root1->val == root2->val)
        {
            if (areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right))
                return true;
        }
        return false;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL)
            return true;
        else if (root == NULL || subRoot == NULL)
            return false;

        if (areIdentical(root, subRoot))
            return true;

        if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
            return true;

        return false;
    }
};