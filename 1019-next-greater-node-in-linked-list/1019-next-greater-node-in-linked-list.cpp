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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodelist;
        
        while(head!=NULL){
            nodelist.push_back(head->val);
            head = head->next;
        }
        
        vector<int> outputlist(nodelist.size());
        stack<int> st;
        
        for(int i = 0;i<nodelist.size();i++){
            while(!st.empty() && nodelist[st.top()]<nodelist[i]){
                outputlist[st.top()] = nodelist[i];
                st.pop();
            }
            st.push(i);
        }
        
        return outputlist;
    }
};