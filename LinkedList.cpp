#include <iostream>
using namespace std;

void menu() {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "please select what you would like to do (ex. type in B2, G6 or D): " << endl;
	cout << "NOTE when you choose an option from each of the type of linked lists, it only edits that list" << endl;
	cout << "for Doubly Linked list" << endl;
	cout << "	" << "A.Insert a node into a doubly linked list" << endl;
	cout << "		" << "1. At the beginning of the doubly linked list" << endl;
	cout << "		" << "2. Insert a new node after a given node" << endl;
	cout << "		" << "3. At the end of the doubly linked list" << endl;
	cout << "	" << "B.Delete a node from a doubly linked list" << endl;
	cout << "		" << "1. Delete the first node" << endl;
	cout << "		" << "2. Delete a node from the end" << endl;
	cout << "		" << "3. Delete a node based on its key" << endl;
	cout << "	" << "C.Search a node according to its key" << endl;
	cout << "	" << "D.Display a doubly linked list" << endl;
	cout << "	" << "E.Press E to go back to the main menu" << endl;
	cout << "for Circular linked list" << endl;
	cout << "	" << "F.Insert a node into a circular linked list" << endl;
	cout << "		" << "1. At the beginning of the circular linked list" << endl;
	cout << "		" << "2. Insert a new node after a given node" << endl;
	cout << "		" << "3. At the end of the circular linked list" << endl;
	cout << "	" << "G.Delete a node from a circular linked list" << endl;
	cout << "		" << "1. Delete a node from the end" << endl;
	cout << "		" << "2. Delete a node after a given node" << endl;
	cout << "	" << "H.Search a node according to its key" << endl;
	cout << "	" << "I.Display a circular linked list" << endl;
	cout << "	" << "J.Press E to go back to the main menu" << endl;
	cout << "Or type esc to exit" << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
struct Node {
	int data;
	Node* prev;
	Node* next;
};
struct NodeC {
	int data;
	struct NodeC* next;
};
void insertFront(struct Node** head, int data) {
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = (*head);
	newNode->prev = NULL;
	if ((*head) != NULL) {
		(*head)->prev = newNode;
	}
	(*head) = newNode;
}
void insertEnd(struct Node** head, int data) {
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	struct Node* temp = *head;
	if (*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}
void insertAfter(struct Node* prev_node, int data) {
	if (prev_node == NULL) {
		cout << "previous node cannot be NULL";
		return;
	}
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = prev_node->next;
	prev_node->next = newNode;
	newNode->prev = prev_node;
	if (newNode->next != NULL) {
		newNode->next->prev = newNode;
	}
}
void displayList(struct Node* node) {
	struct Node* last;
	while (node != NULL) {
		cout << node->data << "->";
		last = node;
		node = node->next;
	}
	if (node == NULL) {
		cout << "NULL\n";
	}
}
void deleteNode(struct Node** head, struct Node* del_node) {
	if (*head == NULL || del_node == NULL) {
		return;
	}
	if (*head == del_node) {
		*head = del_node->next;
	}
	if (del_node->next != NULL) {
		del_node->next->prev = del_node->prev;
	}
	if (del_node->prev != NULL) {
		del_node->prev->next = del_node->next;
	}
	free(del_node);
}
bool searchNode(struct Node** head_ref, int key) {
	struct Node* current = *head_ref;
	while (current != NULL) {
		if (current->data == key)
			return true;
		current = current->next;
	}
	return false;
}
void insertFrontC(NodeC*& headC, int data_node) {
	NodeC* newNode = new NodeC;
	newNode->data = data_node;
	if (headC == NULL) {
		newNode->next = newNode; 
		headC = newNode;
	}
	else {
		NodeC* tail = headC;
		while (tail->next != headC) {
			tail = tail->next;
		}
		newNode->next = headC; 
		tail->next = newNode; 
		headC = newNode; 
	}
}
void insertAfterC(NodeC* prev_node, int node_data) {
	if (prev_node == nullptr) {
		cout << "The given previous node is required, cannot be NULL" << endl;
		return;
	}
	NodeC* newNode = new NodeC;
	newNode->data = node_data;
	newNode->next = prev_node->next;
	prev_node->next = newNode;
}
void insertEndC(NodeC** headC, int data) {
	NodeC* newNode = new NodeC;
	newNode->data = data;
	newNode->next = NULL;
	if (*headC == NULL) {
		*headC = newNode;
		newNode->next = newNode; 
		return;
	}
	NodeC* temp = *headC;
	while (temp->next != *headC) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = *headC; 
}
void deleteNodeC(NodeC** headC, NodeC* del_node) {
	if (*headC == NULL || del_node == NULL) {
		return;
	}
	if (*headC == del_node) {
		if (del_node->next == del_node) {
			*headC = nullptr;
		}
		else {
			NodeC* last = del_node;
			while (last->next != *headC) {
				last = last->next;
			}
			last->next = del_node->next;
			*headC = del_node->next; 
		}
	}
	else {
		NodeC* prev = *headC;
		while (prev->next != del_node) {
			prev = prev->next;
			if (prev == *headC) {
				return;
			}
		}
		prev->next = del_node->next;
	}
	delete del_node;
}
bool searchNodeC(NodeC** head_ref, int key) {
	if (*head_ref == nullptr) {
		return false; 
	}
	NodeC* current = *head_ref;
	do {
		if (current->data == key)
			return true;
		current = current->next;
	} while (current != *head_ref); 
	return false; 
}
void displayListC(NodeC* node, NodeC* head) {
    if (head == NULL) {
        cout << "circular linked list is empty" << endl;
        return;
    }

    while (true) {
        cout << node->data << "->";
        node = node->next;
        if (node == head) // Check if we've reached the head node again
            break;
    }
    cout << "head" << endl;
}
int main()
{
	NodeC* headC = NULL;
	Node* head = NULL;
	string input;
	int value;
	int position;
	menu();
	cin >> input;
	while (input != "esc") {
		if (input == "A1") {
			cout << "what value would you like to input to front" << endl;
			cin >> value;
			insertFront(&head, value);
			//&head
			menu();
			cin >> input;
		}
		else if (input == "A2") {
			cout << "what value would you like to input" << endl;
			cin >> value;
			cout << "what position would you like to insert it AFTER if 1 is the first node" << endl;
			cin >> position;
			Node* node = head;
			for (int i = 1; i < position; i++) {
				if (node == NULL) {
					//cout << "position is out of range" << endl;
					return 0;
				}
				node = node->next;
			}
			insertAfter(node, value);
			menu();
			cin >> input;
			//insert after
		}
		else if (input == "A3") {
			cout << "what value would you like to input to end" << endl;
			cin >> value;
			insertEnd(&head, value);
			menu();
			cin >> input;
			//insert end
		}
		else if (input == "B1") {
			deleteNode(&head, head);
			menu();
			cin >> input;
		}
		else if (input == "B2") {
			Node* node = head;
			while (node->next != NULL) {
				node = node->next;
			}
			deleteNode(&head, node);
			menu();
			cin >> input;
			//delete end 
		}
		else if (input == "B3") {
			cout << "what is the position of the node you would like to delete if 1 is first node" << endl;
			cin >> position;
			Node* node = head;
			for (int i = 1; i < position; i++) {
				if (node == NULL) {
					//cout << "position is out of range" << endl;
					return 0;
				}
				node = node->next;
			}
			deleteNode(&head, node);
			menu();
			cin >> input;
			//delete based on key 
		}
		else if (input == "C") {
			cout << "what is the value of the node you are searching for" << endl;
			cin >> value;
			cout << "what is the position you are checking if this value is at" << endl;
			cin >> position;
			Node* node = head;
			for (int i = 1; i < position; i++) {
				if (node == NULL) {
					//cout << "position is out of range" << endl;
					return 0;
				}
				node = node->next;
			}
			if (searchNode(&node, value))
				cout << "true" << endl;
			else
				cout << "false" << endl;

			menu();
			cin >> input;
			//search node based on key
		}
		else if (input == "D") {
			displayList(head);
			menu();
			cin >> input;
			//
		}
		else if (input == "E") {
			menu();
			cin >> input;
			//go back to main menu 
		}
		else if (input == "F1") {
			cout << "what value would you like to input to front" << endl;
			cin >> value;
			insertFrontC(headC, value);
			//&head
			menu();
			cin >> input;
			//insert beginning 
		}
		else if (input == "F2") {
		cout << "what value would you like to input" << endl;
		cin >> value;
		cout << "what position would you like to insert it AFTER if 1 is the first node" << endl;
		cin >> position;
		NodeC* node = headC;
		for (int i = 1; i < position; i++) {
			if (node == NULL) {
				//cout << "position is out of range" << endl;
				return 0;
			}
			node = node->next;
		}
		insertAfterC(node, value);
		menu();
		cin >> input;
			//insert after 
		}
		else if (input == "F3") {
		cout << "what value would you like to input to end" << endl;
		cin >> value;
		insertEndC(&headC, value);
		menu();
		cin >> input;
			//insert end 
		}
		else if (input == "G1") {
		NodeC* node = headC;
		while (node->next != headC) {
			node = node->next;
		}
		deleteNodeC(&headC, node);
		menu();
		cin >> input;
		//delete end 
		}
		else if (input == "G2") {
		cout << "what is the position of the node you would like to delete if 1 is first node" << endl;
		cin >> position;
		NodeC* node = headC;
		for (int i = 1; i < position; i++) {
			if (node == NULL) {
				//cout << "position is out of range" << endl;
				return 0;
			}
			node = node->next;
		}
		deleteNodeC(&headC, node);
		menu();
		cin >> input;
			//delete after 
		}
		else if (input == "H") {
		cout << "what is the value of the node you are searching for" << endl;
		cin >> value;
		cout << "what is the position you are checking if this value is at" << endl;
		cin >> position;
		NodeC* node = headC;
		for (int i = 1; i < position; i++) {
			if (node == NULL) {
				//cout << "position is out of range" << endl;
				return 0;
			}
			node = node->next;
		}
		if (searchNodeC(&node, value))
			cout << "true" << endl;
		else
			cout << "false" << endl;

		menu();
		cin >> input;
			//search according to key
		}
		else if (input == "I") {
			displayListC(headC,headC);
			menu();
			cin >> input;
			//display
		}
		else if (input == "J") {
			menu();
			cin >> input;
				//back to main menu 
		}
		else {
			cout << "that was not a command please enter a command" << endl;
			menu();
			cin >> input;
		}
	}
}
