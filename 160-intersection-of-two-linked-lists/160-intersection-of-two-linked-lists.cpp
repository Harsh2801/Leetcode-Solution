class Solution {
public:
// len calculator
int len(ListNode* head){
if(head->next == NULL){
return 1;
}
return 1+len(head->next);
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // base case
    if(headA == NULL || headB == NULL)
{
        return NULL;
}
    
    int lenA = len(headA);
    int lenB = len(headB);
    int diff = abs(lenA-lenB);
    
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    
    // to bring both pointers on same level
    if(lenA > lenB){
        for(int i = 0; i < diff; i++){
            temp1 = temp1->next;
        }
    }
    else
    {
        for(int i = 0; i < diff; i++){
            temp2 = temp2->next;
        }
    }
    
    while(temp1 != NULL && temp2 != NULL)
    {
        
        if(temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}
};