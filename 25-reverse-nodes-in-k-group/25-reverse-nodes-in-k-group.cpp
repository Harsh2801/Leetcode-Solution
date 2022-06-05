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
     int length(ListNode* head)
        {
            int len=0;
            while(head!=NULL)
            {
                len++;
                head=head->next;
            }
         return len;
            
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
      //first  traverse the list and get length
         if(head==NULL) return NULL;
         int x = length(head);
       
        if(x<k) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp;
        int count=0;
        while(curr!=NULL && count<k)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            count++;
        }
        //now recursively call and we have reverse first k so head is at last
        head->next=reverseKGroup(temp,k);
        //now our new head is stored in prev so just return it;
        return prev;
        
       
    }
};