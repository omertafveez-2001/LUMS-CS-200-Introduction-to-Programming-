// C++ program for the above approach
#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node 
{
    public:
        int data;
        Node* next;

    // Default constructor
    Node();
};

Node::Node()
{
    data=0;
    next=NULL;
}


class Linkedlist {
	Node* head;

public:
	// Default constructor
	Linkedlist();
    ~Linkedlist();

    //copy constructor
    //Linkedlist(Linkedlist &rhs);
    Linkedlist& operator=(const Linkedlist &rhs);

	// Function to insert a
	// node at the end of the
	// linked list.

	// Function to print the
	// linked list.
	void printList();
    void insertAtHead(int);

	// Function to delete the
	// node at given position
	void deleteNode(int);

    Node* getNode(int a);
    void insertAtTail(int a);
    void removeHead();
    void removeTail();
};


Linkedlist& Linkedlist::operator=(const Linkedlist &rhs)
{
    if (this != &rhs) // check for self-assignment
    {
        // delete any existing nodes in the current list
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        
        // copy nodes from rhs to this list
        Node *rptr = rhs.head;
        Node *prev = nullptr;
        while (rptr != nullptr)
        {
            Node *newNode = getNode(rptr->data);
            if (prev == nullptr)
            {
                head = newNode;
            }
            else
            {
                prev->next = newNode;
            }
            prev = newNode;
            rptr = rptr->next;
        }
    }
    return *this;
}

Linkedlist::~Linkedlist()
{
    Node* p = head;
    while(p!=NULL)
    {
        head=head->next;
        delete p;
        p=head;
    }
}

void Linkedlist::removeTail()
{
    if(head==NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
        }
        else
        {
            Node* p = head;
            Node* q = head;
            while(q->next!=NULL)
            {
                p=q;
                q=q->next;
            }
            delete q;
            p->next=NULL;
        }
    }
}

void Linkedlist::removeHead()
{
    if(head==NULL)
    {
        cout << "empty list" << endl;
    }
    else
    {
        head=head->next;
    }
}

void Linkedlist::insertAtTail(int a)
{
    if(head==NULL)
    {
        head=getNode(a);
    }
    else
    {
        Node* newnode = head;
        while(newnode->next!=NULL)
        {
            newnode=newnode->next;
        }
        newnode->next = getNode(a);
    }
}

void Linkedlist::insertAtHead(int a)
{
    if(head==NULL)
    {
        head=getNode(a);
    }
    else
    {
        Node* newnode = getNode(a);
        newnode->next = head;
        head = newnode;
    }
}

Node* Linkedlist::getNode(int a)
{
    Node* p = new Node;
    if(p==NULL)
    {
        cerr << "Error Message" << endl;
        exit(-1);
    }
    else
    {
        p->data=a;
        p->next=NULL;
    }
    return p;
}

Linkedlist::Linkedlist()
{
    head=NULL;
}

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	// Check if the position to be
	// deleted is greater than the length
	// of the linked list.
	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	// Declare temp1
	temp1 = head;

	// Deleting the head.
	if (nodeOffset == 1) {

		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to
	// find the node to be deleted.
	while (nodeOffset-- > 1) {

		// Update temp2
		temp2 = temp1;

		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
}

// Function to insert a new node.

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
	Node* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

// Driver Code
int main()
{
	Linkedlist list, list2;

	// Inserting nodes
	list.insertAtHead(2);
    list.insertAtHead(3);
    list.insertAtHead(4);
    list.insertAtHead(5);
    list.insertAtTail(10);

	cout << "Elements of the list are: ";

	// Print the list
	list.printList();
	cout << endl;

	// Delete node at position 2.
	list.removeHead();
    list.removeTail();

    
	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
    cout << "Elements of the list 2 are: ";
    list2 = list;
    list2.printList();
	return 0;
}
