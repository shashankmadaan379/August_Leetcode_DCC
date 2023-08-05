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
    vector<TreeNode*> constructTrees(int start, int end){
        vector<TreeNode*> trees;
        if(start > end){
            trees.push_back(NULL);
            return trees;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftsubtrees = constructTrees(start, i-1);
            vector<TreeNode*> rightsubtrees = constructTrees(i+1, end);

            for(int j=0; j<leftsubtrees.size(); j++){
                TreeNode* left = leftsubtrees[j];
                for(int k=0 ; k<rightsubtrees.size() ; k++){
                    TreeNode*right = rightsubtrees[k];
                    TreeNode*Node = new TreeNode(i);
                    Node->left = left;
                    Node->right = right;
                    trees.push_back(Node);
                }
            }
        }

        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return constructTrees(1,n);
    }
};
