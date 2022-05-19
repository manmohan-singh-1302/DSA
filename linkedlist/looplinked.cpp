#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};
bool check(node* head){
  //hashing method
  // unordered_set<node*> s;
  // while(head!=NULL){
  //   if(s.find(head)!=s.end())
  //     return true;
  //   s.insert(head);
  //   head=head->next;
  // }
  // return false;
  /* floyd cycle method
   
        if(!head) return false;
        
        //using two pointers and moving one pointer(slow) by one node and 
        //another pointer(fast) by two nodes in each iteration.
        Node* fast = head->next;
        Node* slow = head;
        
        while( fast != slow)
        {
            //if the node pointed by first pointer(fast) or the node 
            //next to it is null, we return false.
            if( !fast || !fast->next ) 
            return false;
            
            fast=fast->next->next;
            slow=slow->next;
        }
        //if we reach here it means both the pointers fast and slow point to 
        //same node which shows the presence of loop so we return true.
        return true;*/
         if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    // If loop does not exist
    if (slow != fast)
        return NULL;
 
    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
 
    return slow;
}
void insert(node** head_ref, int item){
  node* temp = new node;
  temp->data = item;
  temp->next = *head_ref;
  *head_ref = temp;
}
void display(node* root){
  while(root!=NULL){
    cout<<root->data<<" ";
    root=root->next;
  }
}
node* arrayToList(int a[], int n){
  node *head = NULL;
  for(int i=n-1;i>=0;i--)
    insert(&head,a[i]);
    return head;
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  node* root = arrayToList(a,n);
  display(root);
  root->next->next->next=root;
  if(check(root))
    cout<<"loop found"<<endl;
  else  
    cout<<"no loop"<<endl;
  return 0;
}