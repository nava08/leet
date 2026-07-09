#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
    
private:
    std::vector<TreeNode*> buildTrees(int start, int end) {
        std::vector<TreeNode*> trees;
        
        // Base case: if start > end, there is no tree to build, add nullptr
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }
        
        // Iterate through all possible roots from 'start' to 'end'
        for (int i = start; i <= end; ++i) {
            // Recursively generate all possible left and right subtrees
            std::vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            std::vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);
            
            // Connect each left and right subtree combination to the current root 'i'
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        
        return trees;
    }
};