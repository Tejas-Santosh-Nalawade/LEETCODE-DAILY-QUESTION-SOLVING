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
    bool isPalindrome(ListNode* head) {
        stack<int>stk;
        for(ListNode *curr = head; curr!=NULL; curr=curr->next )
        {
            stk.push(curr->val);
        }

        for(ListNode* left=head; left!=NULL; left=left->next){
            int lval = left->val;
            int rval = stk.top();
            stk.pop();

            if(lval !=rval) return false;
        }
        return true;
    }
};