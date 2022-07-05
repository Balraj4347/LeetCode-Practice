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
    
// Morris Traversal 100% faster T.C:O(N) S.C: O(1)
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>result;
        TreeNode* curr=root;
        TreeNode* prev=nullptr;
        while(curr){
            if(curr->left){
                prev=curr->left;
                while(prev->right && prev->right!=curr)
                    prev=prev->right;
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }else if(prev->right==curr) {
                    prev->right=nullptr;
                    result.push_back(curr->val);
                    curr=curr->right;
                }
                
            }
            else{
                result.push_back(curr->val);
                curr=curr->right;
            }
            
        }
        
        return result;
    }
// Iterative approch
//     vector<int> inorderTraversal(TreeNode* root){
//         vector<int> result;
//         stack<TreeNode*> s;
//         while(root || !s.empty()){
//             while(root)
//             {
//                 s.push(root);
//                 root=root->left;
//             }
//             root=s.top();
//             s.pop();
//             result.push_back(root->val);
//             root=root->right;
                
//         }
     
//         return result;
//     }

// Recursive approch
    // void solve(TreeNode* root, vector<int>& result){
    //     if(root==nullptr)
    //         return;
    //     solve(root->left,result);
    //     result.push_back(root->val);
    //     solve(root->right,result);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     solve(root,result);
    //     return result;
    // }
};
