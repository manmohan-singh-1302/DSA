#include <bits/stdc++.h>
using namespace std;
int stacking[100], n = 100, top = -1;
void push(int val)
{
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        stacking[top] = val;
    }
}
void pop()
{
    if (top <= -1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        cout << "The poped element is" << stacking[top] << endl;
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        cout << "stack elements are:" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << stacking[i] << " ";
            cout << endl;
        }
    }
    else
        cout << "Stack is empty" << endl;
}
int main()
{
    int ch, val;
    cout << "1) Push" << endl;
    cout << "2) Pop" << endl;
    cout << "3) display" << endl;
    cout << "4) exit" << endl;
    do
    {
        cout << "enter the choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "enter the value to be pushed" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            cout << "exit" << endl;
            break;
        }
        default:
        {
            cout << "invalid choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}