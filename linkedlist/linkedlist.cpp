#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *next;
};
void insert(node **head_ref, int item)
{
  node *temp = new node;
  temp->data = item;
  temp->next = *head_ref;
  *head_ref = temp;
}
void display(node *root)
{
  while (root != NULL)
  {
    cout << root->data << " ";
    root = root->next;
  }
}
/*void append(node** root, int key){
  node* new_node = new node;
  node* last = *root;
  new_node->data = key;
  new_node->next = NULL;
  if(*root == NULL){
    *root = new_node;
    return;
  }
  while(last->next!=NULL){
    last = last->next;
  }
  last->next = new_node;
  return;
}*/
node *arrayToList(int a[], int n)
{
  node *head = NULL;
  for (int i = n - 1; i >= 0; i--)
    insert(&head, a[i]);
  return head;
}
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  node *root = arrayToList(a, n);
  display(root);
  return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
void push(node *&headred, int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = headred;
    headred = temp;
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    int cnt = 0;
    node *l1;
    // node *l2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        push(l1, t);
    }
    display(l1);
}

*/

/*

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    int n, num;
    cin >> n;
    node *tail = NULL;
    node *head = NULL;
    cin >> num;
    head = new node(num);
    tail = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> num;
        tail->next = new node(num);
        tail = tail->next;
    }
    display(head);
    return 0;
}
*/

prefered one

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
  return 0;
}