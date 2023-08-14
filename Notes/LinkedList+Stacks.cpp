#include <iostream>
using namespace std;

class Node
{
    public:
        char data;
        Node* next;
        Node();
};

Node::Node()
{
    data='\0';
    next=NULL;
}

class LinkedList
{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList();
        ~LinkedList();
        void insertAtTail(char);
        void insertAtHead(char);
        char removeHead();
        void removeTail();
        Node* getNode(char);
        void print();
        bool isEmpty();
};

bool LinkedList::isEmpty()
{
    if(head==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void LinkedList::print()
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
Node* LinkedList::getNode(char a)
{
    Node* p = new Node;
    if(p==NULL)
    {
        cout << "List is empty" << endl;
        exit(-1);
    }
    else
    {
        p->data = a;
        p->next = NULL;
    }
    return p;
}

LinkedList::LinkedList()
{
    head=NULL;
    tail=NULL;
}

LinkedList::~LinkedList()
{
    Node*p = head;
    while(p!=NULL)
    {
        head = head->next;
        delete p;
        p=head;
    }
}

void LinkedList::insertAtHead(char a)
{
   if(head==NULL)
   {
        head=getNode(a);
   }
   else
   {
        Node* p = getNode(a);
        p->next = head;
        head = p;
   }
}

void LinkedList::insertAtTail(char a)
{
    if(head==NULL)
    {
        head=getNode(a);
    }
    else
    {
        Node* p = head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = getNode(a);
    }
}

char LinkedList::removeHead()
{
    if(head==NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node* p = head;
        char temp = p->data;
        head = head->next;
        delete p;
        return temp;
    }
}

void LinkedList::removeTail()
{
    if(head==NULL)
    {
        cout << "List is empty" << endl;
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
        p->next = NULL;
    }
}

class Stack
{
    private:
        LinkedList *object;
    public:
        void push(char a);
        char pop();
        bool isStackEmpty();
        Stack();
        ~Stack();
        void displayStack();
        int count = 0;
};

void Stack::displayStack()
{
    for(int i = 0; i<count; i++)
    {
        cout << pop();
    }
}

Stack::Stack()
{
    object = new LinkedList();
}

bool Stack::isStackEmpty()
{
    if(object->isEmpty())
    {
        return true;
    }
    else
    {
        false;
    }
}

Stack::~Stack()
{
    delete object;
}

void Stack::push(char a)
{
    object->insertAtHead(a);
    count++;
}

char Stack::pop()
{
    return object->removeHead();
}

int main()
{
    Stack s1;
    string hello = "Hello World";
    for(int i = 0; i<hello.length();i++)
    {
        s1.push(hello[i]);
    }
    /*for(int i = 0; i<hello.length();i++)
    {
        cout << s1.pop();
    }*/

    s1.displayStack();

}