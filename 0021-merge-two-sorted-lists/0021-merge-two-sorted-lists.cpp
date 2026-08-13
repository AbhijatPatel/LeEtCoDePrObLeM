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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // if (list1 == NULL)
        //     return list2;

        // if (list2 == NULL)
        //     return list1;

        // ListNode* head;

        // if (list1->val <= list2->val) {
        //     head = list1;
        //     list1 = list1->next;
        // }
        // else {
        //     head = list2;
        //     list2 = list2->next;
        // }

        // ListNode* tail = head;

        // while (list1 != NULL && list2 != NULL) {

        //     if (list1->val <= list2->val) {
        //         tail->next = list1;
        //         list1 = list1->next;
        //     }
        //     else {
        //         tail->next = list2;
        //         list2 = list2->next;
        //     }

        //     tail = tail->next;
        // }

        // if (list1 != NULL)
        //     tail->next = list1;
        // else
        //     tail->next = list2;

        // return head;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummyNode = new ListNode(-1); 
        ListNode*  temp =  dummyNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 =t2->next;
            }
        }
        if(t1) temp->next = t1;
        else temp->next = t2;
        return dummyNode->next;
    }
};