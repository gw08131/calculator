#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};
Node* insert_node(Node* head, int new_data)
{
	Node* newNode = new Node();
	newNode->data = new_data;
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		Node* ptr = head;
		while (1)
		{
			if (ptr->next == NULL)
				break;
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}

	return head;
}
void print(Node* head)
{
	while (1)
	{
		cout << head->data << " ";
		head = head->next;
		if (head == NULL)
			break;
	}

	return;
}
Node* remove(Node* head, int data)
{
	Node* target = NULL;
	if (head->data == data)
	{
		head = head->next;
	}
	else
	{
		Node* ptr = head;
		while (1)
		{
			ptr = ptr->next;
			if (ptr->next->data == data)
			{
				break;
			}

		}
		target = ptr->next;
		ptr->next = ptr->next->next;
		delete target;
	}
	return head;
}
void insert(Node* head, int before_data, int new_data) {
	
	Node* ptr = head;
	
	while (1)
	{
		ptr = ptr->next;
		if (ptr->data == before_data)
		{
			break;
		}

	}
	Node* temp = ptr->next;
	Node* newNode = new Node();
	ptr->next = newNode;
	newNode->data = new_data;

	ptr->next = newNode;
	newNode->next = temp;	

}

int main() {

	Node* head = NULL;
	
	/*Node node1;
	node1.data = 1;
	node1.next = NULL;

	head = &node1;

	Node node2;
	node2.data = 2;
	node2.next = NULL;

	head->next = &node2; */

	for (int i = 1; i <= 50; i++)
	{
		head = insert_node(head, i);
	}

	print(head);
	cout << endl;
	/// 1 2 ~ 49 50
	head = remove(head, 23);
	print(head);

	insert(head, 22, 23);
	print(head);
	vector<int > v;
	v.push_back(2);
	/// 1 2 3 ~ 20 21 22 24 25 ~ 49 50*/


	// f5 debugging
	// f10 1 line run?

	return 0;
}