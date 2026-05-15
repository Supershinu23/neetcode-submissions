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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        int size = 0 ;
        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next;
            size++;
        }
        if(!fast){
            size = 2*size;
        }else{
            size = 2*size +1;
        }

        ListNode* node = new ListNode();
        ListNode* prev = node;
        int t = 0 ;
        while(t<size){
            t++;
            if(t==size-n+1){
                prev->next = head->next;
                break;
            }else{
                prev->next = head ;
                prev = head ;
                head = head->next;
            }
        }
        return node->next;
    }
};
