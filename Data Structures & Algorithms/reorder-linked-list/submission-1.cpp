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
    void reorderList(ListNode* head) {
        if(!head || !head->next)return ;
        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* prev = new ListNode();

        while(fast && fast->next){
            prev->next = slow;
            prev = slow;
            slow = slow->next ;
            fast = fast->next->next;
        }
        cout<<prev->val;
        ListNode* last = nullptr;
        while(slow->next){
            ListNode* next = slow->next ;
            slow->next = last ;
            last = slow ;
            slow = next ;
        }
        slow->next = last;
        prev->next = slow ;

        ListNode* pointer1 = head ;
        ListNode* pointer2 = prev->next ;
        prev->next = nullptr;
        while(pointer2 && pointer1){
            ListNode* next1 = pointer1->next ;
            ListNode* next2 = pointer2->next ;
            pointer1->next = pointer2 ;
            pointer1 = next1 ;
            if(pointer1)pointer2->next = pointer1;
            pointer2 = next2 ;
        }
    }
};
