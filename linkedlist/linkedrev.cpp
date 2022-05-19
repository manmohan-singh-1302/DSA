// #include<bits/stdc++.h>
// using namespace std;
// struct node{
//   int data;
//   node* next;
// };
// void insert(node** root, int item){
//   node* temp = new node;
//   temp->data = item;
//   temp->next = *root;
//   *root = temp;
// }
// void reverseUtil(node* curr, node* prev, node** root)
// {
//     if (!curr->next) {
//         *root = curr;
//          curr->next = prev;
//         return;
//     }
//      node* next = curr->next;
//     curr->next = prev;
 
//     reverseUtil(next, curr, root);
// }
// void display(node* root){
//   while(root!=NULL){
//     cout<<root->data<<" ";
//     root=root->next;
//   }
// }   
// void reverse(node** root)
// {
//     if (!root)
//         return;
//     reverseUtil(*root, NULL, root);
// }
// node* arrayToList(int a[], int n){
//   node *root = NULL;
//   for(int i=n-1;i>=0;i--)
//     insert(&root,a[i]);
//     return root;
// }
// int main(){
//   int n;
//   cin>>n;
//   int a[n];
//   for(int i=0;i<n;i++){
//     cin>>a[i];
//   }
//   node* root = arrayToList(a,n);
//   display(root);
//   reverse(&root);
//   cout<<endl;
//   display(root);
//   return 0;
// }

//preferred code

#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *next;
  node(int x)
  {
    data = x;
    next = NULL;
  }
};
class Solution
{
public:
  node *reverse(node **head)
  {
    node *curr = *head;
    node *next = NULL;
    node *prev = NULL;
    while (curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    *head = prev;
  }
};
void display(node *head)
{
  while (head != NULL)
  {
    cout << head->data;
    head = head->next;
  }
}
int main()
{
  node *head = NULL;
  node *tail = head;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;
    if (head == NULL)
      head = tail = new node(data);
    else
    {
      tail->next = new node(data);
      tail = tail->next;
    }
  }
  display(head);
  cout << endl;
  Solution onj;
  node *ans = onj.reverse(&head);
  display(head);
  return 0;
}