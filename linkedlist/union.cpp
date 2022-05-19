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
node *arrayToList(int a[], int n)
{
    node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
        insert(&head, a[i]);
    return head;
}
node *intersection(node *a, node *b)
{
    if (a == NULL || b == NULL)
        return NULL;
    // move the smaller element to right
    if (a->data < b->data)
        return intersection(a->next, b);
    if (a->data > b->data)
        return intersection(a, b->next);
    // if both the values are same

    node *temp = new node;
    if (a->data == b->data)
    {
        temp->data = a->data;
        temp->next = intersection(a->next, b->next);
    }
    return temp;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    node *l1;
    node *l2;
    node *root = arrayToList(a, n);
    display(root);
    cout << endl;
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    node *root1 = arrayToList(b, m);
    display(root1);
    cout << endl;
    node *ans = intersection(root, root1);
    display(ans);
    return 0;
}