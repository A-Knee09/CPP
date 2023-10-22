#include <iostream>
using namespace std;

class Node // Class to define what a node is;
{
private:
public: // A new node will have a data , a 'next' var that stores the memory address of next node , and a 'head' that will stay null;
    int data;
    Node *next;
    Node *head;
    Node(int data) // Parameterised constructor;
    {
        this->data = data;
        this->next = NULL;
        this->head = NULL;
        // cout<<"Data is: "<<data<<endl;
        // cout<<"Next node Address is : "<<next<<endl;
        // cout<<"Head node address is: "<<head<<endl;
    }
    ~Node()
    {
        // Memory free;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void InsHead(Node *&head, int d) // Function to add a new node at the head of the orignal node;
{
    Node *temp = new Node(d); // Create a new node temp;
    temp->next = head;        // Temp node will be added at the head of the orignal node;
    head = temp;              // Point the head of the list to the temp node;
}

void InsTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void InsAtPos(Node *&head, int pos, int d)
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
        // Memory free;
        delete temp;
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

void Display(Node *&head) // Function to print the list;
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
    Node *N1 = new Node(0);
    Node *head = N1;
    Node *tail = N1;
    cout<<"Node Inserted at Head: ";
    InsHead(head , 10);
    InsHead(head , 20);
    InsHead(head , 30);
    InsHead(head , 40);
    InsHead(head , 50);
    Display(head);
    cout<<"Deleting the last node: ";
    DeleteNode(6,head);
    Display(head);
    cout<<"Inserting Node at A specified position: ";
    InsAtPos(head , 6 , 0);
    Display(head);
    // cout<<"Node Inserted At tail: ";
    // InsTail(tail , 10);
    // InsTail(tail , 20);
    // InsTail(tail , 30);
    // InsTail(tail , 40);
    // InsTail(tail , 50);
    // Display(head);
    
}
