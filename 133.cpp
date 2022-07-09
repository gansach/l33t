/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneNode(Node *node, map<Node *, Node *> &node2node)
    {
        if (node2node[node] == NULL)
        {
            node2node[node] = new Node(node->val);
        }
        return node2node[node];
    }

    void traverse(Node *node, map<Node *, bool> &visited, map<Node *, Node *> &node2node)
    {
        if (visited[node])
            return;
        visited[node] = true;

        Node *nodeCopy = cloneNode(node, node2node);

        for (Node *neighbor : node->neighbors)
        {

            Node *neighborCopy = cloneNode(neighbor, node2node);

            nodeCopy->neighbors.push_back(neighborCopy);

            traverse(neighbor, visited, node2node);
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        map<Node *, Node *> node2node;
        map<Node *, bool> visited;

        traverse(node, visited, node2node);
        return node2node[node];
    }
};