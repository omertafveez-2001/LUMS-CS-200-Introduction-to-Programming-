#include <iostream>
using namespace std;

// Node Class
class Node
{
    public:
        int num;
        Node* right;
        Node* down;
        
        Node();
        void setNum(int n);
        void setRightPtr(Node* right);
        void setDownPtr(Node* down_ptr);
        
        int getNum();
        Node* getRightPtr();
        Node* getDownPtr();
};
Node::Node()
{
    num = 0;
    right = NULL;
    down = NULL;
}
void Node::setNum(int n)
{
    num = n;
}
void Node::setRightPtr(Node* right_ptr)
{
    right = right_ptr;
}
void Node::setDownPtr(Node* down_ptr)
{
    down = down_ptr;
}
int Node::getNum()
{
    return num;
}
Node* Node::getRightPtr()
{
    return right;
}
Node* Node::getDownPtr()
{
    return down;
}

class LinkedList
{
    Node* upperleft;
    int size;
    
    public:
        LinkedList();
        ~LinkedList();
        
        void populateMyList(int size);
        void kickOutOfTheList(int n); 
        void makeItDisappear(int i, int j);
        
        void transposeLeloBhai(); //
        void swapDiagonals(); //
        
        friend ostream& operator<<(ostream& out, LinkedList& rhs);

        string wellDone();
};

void LinkedList::makeItDisappear(int i, int j)
{
    // Check if the given indices are valid
    if (i < 1 || i > size || j < 1 || j > size) {
        cout << "Invalid indices: (" << i << ", " << j << ")" << endl;
        return;
    }
    
    // Traverse to the node to be deleted and its previous node in the row and column
    Node* row_prev = upperleft;
    Node* col_prev = upperleft;
    for (int k = 1; k < i; k++) {
        row_prev = row_prev->down;
    }
    for (int k = 1; k < j; k++) {
        col_prev = col_prev->right;
    }
    Node* to_delete = col_prev->right;
    
    // Adjust pointers to remove the node
    col_prev->right = to_delete->right;
    row_prev->down = to_delete->down;
    
    // Free memory of the deleted node
    delete to_delete;
}


LinkedList::LinkedList()
{
    upperleft = NULL;
    size = 0;
}
LinkedList::~LinkedList() {
    Node* current = upperleft;
    Node* temp;
    while (current != NULL) {
        while (current->right != NULL) {
            temp = current;
            current = current->right;
            delete temp;
        }
        temp = current;
        current = current->down;
        delete temp;
    }
    upperleft = NULL;
}


void LinkedList::populateMyList(int size) 
{
    this->size = size;
    upperleft = NULL;
    Node *lastRow[size];   // keep track of the last node of each row
    
    for (int i = 0; i < size; i++) {
        Node *prev = NULL;
        Node *last = NULL;  // last node of the current row
        
        for (int j = 0; j < size; j++) {
            Node *new_node = new Node;

            cout << "Enter data for node (" << i << "," << j << "): ";
            cin >> new_node->num;

            if (j == 0) {
                // start a new row
                if (i == 0) {
                    upperleft = new_node;
                } else {
                    lastRow[i-1]->down = new_node;
                }
                lastRow[i] = new_node;
            } else {
                // add node to the right of previous node
                prev->right = new_node;
            }
            prev = new_node;
            last = new_node;
        }
        
        // connect nodes of the current row to nodes of the previous row
        if (i > 0) {
            Node *prev_row_node = lastRow[i-1];
            Node *current_row_node = lastRow[i];
            
            for (int j = 0; j < size; j++) {
                prev_row_node->down = current_row_node;
                prev_row_node = prev_row_node->right;
                current_row_node = current_row_node->right;
            }
        }
    }
}


void LinkedList::kickOutOfTheList(int n)
{
    if(n < 1 || n > size)
    {
        cout << "Invalid Number" << endl;
        return;
    }
    if(n == 1)
    {
        Node* temp = (upperleft->right)->down;
        delete upperleft;
        upperleft = temp;
        size--;
    }
    else
    {
        Node* prev_col = upperleft;
        for (int i = 1; i < n-1; i++)
        {
            prev_col = prev_col->right;
        }
        Node* prev_row = prev_col->down;
        while(prev_row != NULL)
        {
            Node* temp = prev_row->down;
            delete prev_row;
            prev_row = temp;
        }
        prev_col->down = prev_row;
        while(prev_col->right != NULL)
        {
            Node* temp = prev_col->right;
            prev_col->num = temp->num;
            prev_col->down = temp->down;
            prev_col = temp;
        }
        delete prev_col;
        size--;
    }
}


void LinkedList::transposeLeloBhai()
{
    Node * p = upperleft;
    Node * d_temp = upperleft;
    int row = 1;

    while(p != NULL)
    {
        d_temp = p->down; 
        p->down = p->right; 
        p->right = d_temp;
        if(p->down != NULL)
        {
            p = p->down; 
        }
        else
        {
            row++;
            p = upperleft;
            if(row <= size) 
            {
                for(int i = 1; i <row; i++)
                {
                    p = p->right;
                }
            }
            else
            {
                p = NULL; 
            }
        }
    }

}
void LinkedList::swapDiagonals()
{
    Node* top_right = upperleft;
    Node* bottom_left = upperleft;
    int replace = upperleft->num;
    while(top_right->right!=NULL)
    {
        top_right = top_right->right;
    }
    upperleft->num = top_right->num;
    top_right->num = replace;
    while(bottom_left->down!=NULL)
    {
        bottom_left = bottom_left->down;
    }
    Node * bottom_right = bottom_left;
    while(bottom_right->right!=NULL)
    {
        bottom_right = bottom_right->right;
    }
    replace = bottom_left->num;
    bottom_left->num = bottom_right->num;
    bottom_right->num = replace;
}

ostream& operator<<(ostream& out, LinkedList& rhs)
{
    Node *current = rhs.upperleft;
    while (current != NULL)
    {
        Node *rowStart = current;
        while (rowStart != NULL) 
        {
            cout << rowStart->num << " ";
            rowStart = rowStart->right;
        }
        cout << endl;
        current = current->down;
    }
    return out;
}
string LinkedList::wellDone()
{
   return "\nWell Done!\n";
}
int main()
{
    int size;
    cout << "Enter the size of the linked list: ";
    cin >> size;
    LinkedList myList;
    myList.populateMyList(size);
    cout << "Populated List: " << endl;
    cout << myList << endl;
    myList.transposeLeloBhai();
    cout << "Transposed Linked List: " << endl;
    cout << myList << endl;
    myList.kickOutOfTheList(1);
    cout << "After Deletion" << endl;
    cout << myList << endl;
    myList.swapDiagonals();
    cout << "After swapping: " << endl;
    cout << myList << endl;
    myList.makeItDisappear(1,1);
    cout << "After Disappearing: " << endl;
    cout << myList << endl;
    cout << myList.wellDone();
    return 0;
}