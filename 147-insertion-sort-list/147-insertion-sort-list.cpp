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
    ListNode* insertionSortList(ListNode* head) {
        return mergeSort(head);
    }
    ListNode * mergeSort(ListNode* head){
        if(!head || !head->next) return head;
        ListNode * fast = head, * slow = head;
        while(slow->next && fast->next && fast->next->next){//fast->next->next might cause runtime error without fast->next.
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * leftHead = head;
        ListNode * rightHead = slow->next;
        slow->next = nullptr;
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        return mergeList(leftHead, rightHead);
    }
    ListNode* mergeList(ListNode * lhead, ListNode * rhead){
        ListNode dummy(0), *p1 = &dummy, *p2 = rhead;
        p1->next = lhead;
        while(p1->next && p2){
            if(p1->next->val> p2->val){//keep stable
                ListNode * tmp = p2;
                p2 = p2->next;
                tmp->next = p1->next;
                p1 ->next = tmp;
                p1 = p1->next;
            }else{
                p1 = p1->next;
            }
        }
        if(p2) p1->next = p2;
        return dummy.next;
    }
};