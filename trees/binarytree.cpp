#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	//constructor for the node function
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
};
node *generate(string str)
{
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str;)
		ip.push_back(str);

	// Create the root of the tree
	node *root = new node(stoi(ip[0]));

	// Push the root to the queue
	queue<node *> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size())
	{

		// Get and remove the front of the queue
		node *currnode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N")
		{

			// Create the left child for the current node
			currnode->left = new node(stoi(currVal));

			// Push it to the queue
			queue.push(currnode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N")
		{

			// Create the right child for the current node
			currnode->right = new node(stoi(currVal));

			// Push it to the queue
			queue.push(currnode->right);
		}
		i++;
	}

	return root;
}
void inorder(node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		inorder(root->left);
		inorder(root->right);
	}
}
int main()
{
	string tree;
	getline(cin, tree);
	node *root = generate(tree);
	inorder(root);
}

// #include <bits/stdc++.h>
// using namespace std;
// struct node
// {
// 	int data;
// 	node *left;
// 	node *right;
// };
// node *newnode(int value)
// {
// 	node *n = new node;
// 	n->data = value;
// 	n->left = NULL;
// 	n->right = NULL;
// 	return n;
// }
// node *insert(node *root, int value, queue<node *> &q)
// {
// 	node *temp = newnode(value);
// 	if (root == NULL)
// 		root = temp;
// 	else if (q.front()->left == NULL)
// 		q.front()->left = temp;
// 	else
// 	{
// 		q.front()->right = temp;
// 		q.pop();
// 	}
// 	q.push(temp);
// 	return root;
// }
// node *tree(int a[], int n)
// {
// 	// create a node pointer
// 	// create a queue of node pointers and for every element in the array
// 	// insert the element into the tree using the queue
// 	node *head = NULL;
// 	queue<node *> q;
// 	for (int i = 0; i < n; i++)
// 		head = insert(head, a[i], q);
// 	return head;
// }
// void inorder(node *root)
// {
// 	// reverse level order
// 	if (root != NULL)
// 	{
// 		inorder(root->left);
// 		cout << root->data << " ";
// 		inorder(root->right);
// 	}
// }
// void postorder(node *root)
// {
// 	if (root != NULL)
// 	{
// 		postorder(root->left);
// 		postorder(root->right);
// 		cout << root->data << " ";
// 	}
// }
// void levelorder(node *root)
// {
// 	// preorder
// 	if (root == NULL)
// 		return;
// 	queue<node *> n;
// 	n.push(root);
// 	while (!n.empty())
// 	{
// 		cout << n.front()->data << " ";
// 		if (n.front()->left != NULL)
// 			n.push(n.front()->left);
// 		if (n.front()->right != NULL)
// 			n.push(n.front()->right);
// 		n.pop();
// 	}
// 	cout << endl;
// }
// int main()
// {
// 	int n;
// 	cin >> n;
// 	int a[n];
// 	for (int i = 0; i < n; i++)
// 		cin >> a[i];
// 	node *root = tree(a, n);
// 	levelorder(root);
// 	cout << endl;
// 	inorder(root);
// 	cout << endl;
// 	cout << "the postorder is:" << endl;
// 	postorder(root);
// 	return 0;
// }