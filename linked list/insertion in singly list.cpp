#include <iostream>

using namespace std;

struct Node {
	Node *next;
	int val;
};

Node* createNode(int val)
{
	Node *temp;
	temp = new Node;
	temp->val = val;
	temp->next = NULL;
	return temp;
}

int main()
{
	int n, val, i;
	Node *temp, *head;
	head = temp = new Node;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> val;
		if (i == 0)
		{
			head = createNode(val);
			temp = head;
		}
		else
		{
			temp->next = createNode(val);
			temp = temp->next;
		}
	}

	temp = head;
	while (temp)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
}

