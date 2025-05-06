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
       vector<int>front;
       ListNode* curr=head;
       while(curr!=NULL){
            front.push_back(curr->val);
            curr=curr->next;
       } 
       int n=front.size();
       int i=0;
       int j=n-1;
       while(i<j)
       {
        if(front[i]!=front[j]){
            return false;

        }
        else{
            i++;
            j--;
        }
       }
       return true;
    }
};