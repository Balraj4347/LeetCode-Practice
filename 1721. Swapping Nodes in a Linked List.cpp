/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        vector<int> ll;
        ListNode* temp = head;
        while(temp!=NULL){
                ll.push_back(temp->val);
                temp = temp->next;
            }
            int n=ll.size();
            
            swap(ll[k-1], ll[n-k]);
            temp = head;
            for(int i=0;i<ll.size();i++){
                    temp->val = ll[i];
                    temp = temp->next;
                }
            return head;
        
        
    }
};
