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

  
  //Recurrsive T.C: O(n) S.C : O(n) //stack space used in recursion
  void solve(TreeNode* root, vector<int>& rslt){
         if(root==nullptr)
          {  
                return;
          }
         
         solve(root->left,rslt);
         solve(root->right,rslt);
         rslt.push_back(root->val);
        
        return;
         
    }
     vector<int> postorderTraversal(TreeNode* root){
            vector<int> rslt;
            solve(root,rslt);
            return rslt;
         
     }
   //Iterative solution T.C : O(n) S.C: O(n) //stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)
            return result;
        
        if((root->left==nullptr) && (root->right==nullptr) )
        {   result.push_back(root->val);    
            return result;}
        
        TreeNode* temp =root;
        TreeNode* prev=nullptr;
        stack<TreeNode* > s;
        do{
            while(temp!=nullptr)
            {
                s.push(temp);
                temp= temp->left;
            }
            
            while( temp==nullptr && !s.empty() ){
                temp= s.top();
            
                if( temp->right== nullptr || temp->right == prev){
                    
                    result.push_back(temp->val);
                    s.pop();
                    
                    prev=temp;
                    temp=nullptr;
                    
                }
                else
                    temp=temp->right;
                
            }
        }while(!s.empty());
            
            return result;
        
      
    }
};
