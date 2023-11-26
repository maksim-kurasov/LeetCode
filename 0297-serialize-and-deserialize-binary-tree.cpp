#include <bits/stdc++.h>

using namespace std;

/**
    Serialization is the process of converting a data structure or object into
    a sequence of bits so that it can be stored in a file or memory buffer, or
    transmitted across a network connection link to be reconstructed later in
    the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree. There is
    no restriction on how your serialization/deserialization algorithm should
    work. You just need to ensure that a binary tree can be serialized to a
    string and this string can be deserialized to the original tree structure.

    Input: root = [1,2,3,null,null,4,5]
    Output: [1,2,3,null,null,4,5]

    Solution:
    Preorder serialization, deserialize using streams
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringstream& out) {
        if(!root) {
            out << "N";
            return;
        }

        out << root->val << " ";
        out << serialize(root->left) << " ";
        out << serialize(root->right);
    }

    TreeNode* deserialize(istringstream& in) {
        string str;
        in >> str;

        if(str == "N")
            return nullptr;

        TreeNode* tree = new TreeNode(stol(str));
        tree->left = deserialize(in);
        tree->right = deserialize(in);

        return tree;
    }
};

/** [TEST]
int main() {
    TreeNode* tree = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4), new TreeNode(5)));
    Codec codec;
    string str = codec.serialize(tree);
    TreeNode* newTree = codec.deserialize(str);
}
**/