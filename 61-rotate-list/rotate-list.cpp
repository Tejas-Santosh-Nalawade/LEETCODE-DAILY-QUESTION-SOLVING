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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next==NULL){
            return head;
        }
        ListNode*ptr = head;
        int count =1;
        while(ptr->next!=NULL){
            count++;
            ptr=ptr->next;
        }
        ptr->next=head;
        ptr = head;
        int count2 =1;
        k = k % count;
        while(count2<=count-k-1){
            ptr=ptr->next;
            count2++;
        }
        ListNode* newHead = ptr->next;
        ptr->next = nullptr;
        return newHead;   
    }
};