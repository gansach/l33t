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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> nodes;

        unordered_map<TreeNode *, bool> rootContender;

        for (auto &description : descriptions)
        {
            int parent = description[0];
            int child = description[1];
            bool isLeft = description[2];

            if (nodes.find(parent) == nodes.end())
                nodes[parent] = new TreeNode(parent);
            if (nodes.find(child) == nodes.end())
                nodes[child] = new TreeNode(child);

            TreeNode *parentNode = nodes[parent];
            TreeNode *childNode = nodes[child];

            if (isLeft)
                parentNode->left = childNode;
            else
                parentNode->right = childNode;

            if (rootContender.find(parentNode) == rootContender.end())
                rootContender[parentNode] = true;

            rootContender[childNode] = false;
        }
        for (auto itr : rootContender)
        {
            if (itr.second)
                return itr.first;
        }
        return NULL;
    }
};