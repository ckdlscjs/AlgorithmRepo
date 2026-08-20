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
class Solution {
public:
    std::unordered_map<int, int> lookup;
    TreeNode* makeTree(const std::vector<int>& inorder, const std::vector<int>& postorder, int inSt,int inEn, int poSt, int poEn)
    {
        if(inSt > inEn || poSt > poEn) return nullptr;
        TreeNode* newNode = new TreeNode(postorder[poEn]);
        int rootIdx = lookup[postorder[poEn]];
        int leftSize = rootIdx - inSt;
        newNode->left = makeTree(inorder, postorder, inSt, rootIdx-1, poSt, poSt + leftSize-1);
        newNode->right = makeTree(inorder, postorder, rootIdx + 1, inEn, poSt + leftSize, poEn - 1);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for(int i = 0; i < inorder.size(); i++)
            lookup[inorder[i]] = i;
        return makeTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};