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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)return nullptr;
        int l = 1 ;
        ListNode* curr = lists[0];

        while(l<n){
            ListNode* temp = lists[l];
            curr = mergeTwoLists(curr, temp);
            l++;
        }
        return curr;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode(-1);
        ListNode* pointer = prev ;
        while(list1 && list2){
            if(list1->val > list2->val){
                prev->next = list2;
                list2=list2->next;
            }else{
                prev->next = list1;
                list1 = list1->next;
            }
            prev = prev->next;
        }
        while(list1){
            prev->next = list1;
            list1=list1->next;
            prev = prev->next;
        }
        while(list2){
            prev->next = list2;
            list2 = list2->next;
            prev = prev->next;
        }
        return pointer->next;
    }
};
