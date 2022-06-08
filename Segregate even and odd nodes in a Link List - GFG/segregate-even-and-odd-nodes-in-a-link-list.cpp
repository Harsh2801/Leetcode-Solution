// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
            Node* even=new Node(-1);
       Node* odd=new Node(-1);
       Node* tempeve=even;//pointing to even LL
       Node* tempodd=odd;//pointing to odd LL
       Node* curr=head;//pointng to head
       while(curr!=NULL){
           //it data is even
           if(curr->data%2==0){
               tempeve->next=curr;
               tempeve=tempeve->next;
           }else{
               //it means data is odd
               tempodd->next=curr;
               tempodd=tempodd->next;
           }
           curr=curr->next;
       }
       tempodd->next=NULL;
       //simply attach odd's linked list after even
       //linked list 
       tempeve->next=odd->next;
       //move head to even->next
       //bcz here even is pointing to node -1 so we will have to 
       //move the pointer to next
       
       head=even->next;
       return head;//return head
        
    }
};


     

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends