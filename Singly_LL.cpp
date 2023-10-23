#include <iostream>
using namespace std;

class Node // Define what a node is;
{

public:
    int data;      // A node will contain some data;
    Node *next;    // A node will contain a pointer 'next' that points to the next node;
    Node(int data) // Parameterized constructor;
    {
        this->data = data;
        this->next = NULL; // A new node will always point to NULL;
    }
    ~Node() // Destructor to free memory;
    {
        int val = this->data; // Optional
        // Memory free;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory has been freed for data: " << val << endl;
    }
};

void InsHead(Node *&head, int d) // Function for Inserting a node at head;
{
    Node *temp = new Node(d); // Create a new Node "temp' that is to be inserted at beginning of the list;
    temp->next = head;        // New node 'temp' next pointer will point to the head node;
    head = temp;              // Now the new node 'temp' which was inserted at the beginning will be the head node;
}

void InsTail(Node *&tail, int d) // Functoin for inserting a node at tail;
{
    Node *temp = new Node(d); // // Create a new Node "temp' that is to be inserted at end of the list(tail);
    tail->next = temp;        // tail node next pointer should point to the temp;
    tail = temp;              // Now the new node temp will be the tail of the linked list;
}
void InsAtPos(Node *&head, int pos, int d) // A function to insert a node at any pos of LL;
{
    if (pos == 1)
    {
        InsHead(head, d); // In case the user requires to ins a node at start ,we call the InsAtHead func;
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *NodeToIns = new Node(d);

    NodeToIns->next = temp->next;
    temp->next = NodeToIns;
}

void DeleteNode(int pos, Node *&head)
{
    // Deletion of first Node;
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        // Memory free;
        delete temp;
        return;
    }
    // Deletion of other node;
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void PrintLL(Node *&head) // Function to print the list;
{
    Node *temp = head;   // Create a pointer that will point to the head of the list;
    while (temp != NULL) // While the pointer is not NULL;
    {
        cout << temp->data << " "; // Print the data ;
        temp = temp->next;         // Increment the position of temp;
    }
}

int main()
{
    Node *N1 = new Node(10);
    Node *head = N1;
    Node *tail = N1;
    // InsHead(head , 20);
    // InsHead(head , 30);
    // InsHead(head , 40);
    // InsHead(head , 50);
    // PrintLL(head);
    // cout << endl;
    // DeleteNode(2 , head);
    // PrintLL(head);
    // DeleteNode(4,head);
    // PrintLL(head);
    InsTail(tail, 90);
    InsTail(tail, 20);
    InsTail(tail, 30);
    InsTail(tail, 40);
    InsTail(tail, 50);
    PrintLL(head);
    cout << endl;
    DeleteNode(1, head);
    PrintLL(head);
}