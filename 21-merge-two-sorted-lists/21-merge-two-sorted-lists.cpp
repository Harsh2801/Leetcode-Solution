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
        
        
        //------------------------------------RECURSIVE------------------------------------
        
//         // Base case -> If list1 is null return list2 and vice versa
//         if(list1==NULL) return list2;
//         if(list2==NULL) return list1;
        
//         // Add next in sorted order in ans using Recursion
//         ListNode *ans;
        
//         if(list1->val <= list2->val){
// 		    // current ans node set to current min(list1->val,list2->val) then add address to upcoming parts
//             ans=list1;
//             ans->next = mergeTwoLists(list1->next,list2);
//         }
//         else{
//             ans=list2;
//             ans->next = mergeTwoLists(list2->next,list1);
//         }
//         return ans;
        
        
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *head;
        ListNode *tail;
        ListNode *p1=list1;
        ListNode *p2=list2;
        if(list1->val<=list2->val)
        {
            head=list1;
            tail=list1;
            p1=p1->next;
        }
        if(list2->val<list1->val)
        {
            head=list2;
            tail=list2;
            p2=p2->next;
        }
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val<=p2->val)
            {
                 tail->next=p1;
                 p1=p1->next;
            }
            else
            {
                tail->next=p2;
                p2=p2->next;
            }
            tail=tail->next;
        }
        if(!p1) tail->next=p2;
        if(!p2) tail->next=p1;
        return head;
    }
};