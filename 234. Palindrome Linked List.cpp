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
    ListNode* prev;
    bool helper(ListNode* head){
        if(head == NULL) return true;
        if(!helper(head->next)) return false;
        bool isTrue=  helper(head->next)  head->val == prev->val;
        prev=prev->next;
        return isTrue;
    }
    bool isPalindrome(ListNode* head) {
       ListNode* temp=head;
        prev=head;
        
        return helper(temp);
        
    }
};
