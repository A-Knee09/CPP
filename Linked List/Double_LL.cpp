#include <iostream>
using namespace std;

class Node // Define what a node is;
{
public:
    int data;   // Node will contain some data;
    Node *prev; // A node data type pointer that points to the previous node;
    Node *next; // A node data type pointer that points to the next node;

    Node(int d) // Parameterized constructor;
    {
        this->data = d;
        this->prev = NULL; // First node will point to no previous node;
        this->next = NULL; // First node will point to no next node;
    }

    ~Node()
    {
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
    }
    
};

void InsHead(Node *&head, Node *&tail, int d) // Function for Inserting a node at head;
{
    Node *temp = new Node(d); // Create a new Node "temp' that is to be inserted at beginning of the list(head);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head; // New node 'temp' next pointer will point to the head node;
        head->prev = temp; // Head node prev pointer will point to the new node inserted before it;
        head = temp;       // Now the new node 'temp' will be the head node;
    }
}

void InsTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d); // Create a new Node "temp' that is to be inserted at end of the list(tail);
    if (tail == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp; // tail node next pointer should point to the temp;
        temp->prev = tail; // temp node prev pointer will point to the tail;
        tail = temp;       // Now the new node temp will be the tail of the linked list;
    }
}

void InsAtPos(Node *&head, Node *&tail, int pos, int d) // FUnction to add a node at any positon;
{
    if (pos == 1) // If the position is 1 i.e start of the list
    {
        InsHead(head, tail, d); // Call the InsHead function;
    }
    else
    {
        Node *temp = head;
        int count = 1;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        Node *NTI = new Node(d);
        NTI->next = temp->next;
        temp->next->prev = NTI;
        temp->next = NTI;
        NTI->prev = temp;
    }
}

void Delete(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int count = 1;

        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

void display(Node *&head)
{
    Node *temp = head; // Create a pointer temp that points to the head of LL;
    if (temp == NULL)  // If there is no data in the list print that the list is empty;
    {
        cout << "List is empty";
        cout << endl;
    }
    while (temp != NULL) // As long as temp is not empty print data of LL and increment the position of temp;
    {
        cout << temp->data << " -> "; // Printing data;
        temp = temp->next;            // Incrementing position aka travelling forward;
    }
    cout << "NULL" << endl;
}

int GetLen(Node *&head) // To find the length of the list;
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int main()
{
    Node *N1 = new Node(10);
    Node *head = N1;
    Node *tail = N1;
    InsTail(head, tail, 12);
    InsTail(head, tail, 15);
    InsTail(head, tail, 19);
    InsTail(head, tail, 21);
    display(head);
    Delete(head, 1);
    display(head);
    Delete(head, 1);
    display(head);
}
