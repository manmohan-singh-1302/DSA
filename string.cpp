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
        cout << head->data << " ";
        head = head->next;
    }
}
struct node reverse(node *head)
{
    if (!head || !(head->next))
        return head->data;
    auto res = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
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
    cout << "reverse the linked list:" << endl;
    reverse(head);
    display(head);
    return 0;
}