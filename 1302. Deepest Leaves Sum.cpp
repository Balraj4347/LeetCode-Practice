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
    
   int findHeight(TreeNode* head){
       if(head ==nullptr)
           return 0;
       else{
        
           int lheight= findHeight(head->left);
           int rheight=findHeight(head->right);
           
           if(lheight>rheight)
                return lheight+1;
           else
               return rheight+1;
       }
           
   }
    
    void printCurrentLevel(TreeNode* root, int level,int &ans)
    {
            if (root == NULL)
                return;
            if (level == 1)
                ans=ans+ root->val;
         else if (level > 1) {
               printCurrentLevel(root->left, level - 1,ans);
              printCurrentLevel(root->right, level - 1,ans);
      }
    }
    int deepestLeavesSum(TreeNode* root) {
        
        int ans=0;
        int height=0;
        
        height=findHeight(root);
        printCurrentLevel(root,height,ans);
        
        
        return ans;
    }
};
