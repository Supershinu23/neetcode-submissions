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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* prev = temp ;
        int rem = 0 ;
        while(l1 && l2){
            int co = (l1->val + l2->val + rem)%10;
            rem = (l1->val + l2->val + rem)/10;
            ListNode* t = new ListNode(co);

            prev->next = t ;
            prev = t ;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int co = (l1->val+rem)%10;
            rem = (l1->val+rem)/10;
            ListNode* t = new ListNode(co);

            prev->next = t ;
            prev = t ;
            l1 = l1->next;
        }
        while(l2){
            int co = (l2->val+rem)%10;
            rem = (l2->val+rem)/10;
            ListNode* t = new ListNode(co);

            prev->next = t ;
            prev = t ;
            l2 = l2->next;
        }
        if(rem!=0){
            prev->next = new ListNode(rem);
        }
        return temp->next;
    }
};
