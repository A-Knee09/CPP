#include <iostream>
using namespace std;

class Node // Class to define what a node is.
{
public:
    int data;   // Data for node
    Node *next; // pointer pointing to the memory address of next node.

    Node(int d) // Constructor
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node() // Destructor
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

class Single // Seperate class for all single linked list function.
{
public:
    void InsHead(Node *&head, int d) // Function to insert a node at the beginning of the list or head of the Linked list.
    {

        Node *temp = new Node(d); // Create a new Node 'temp'
        temp->next = head;        // New Node(temp) next pointer should point to the orignal head of the list.
        head = temp;              // New Node(temp) should now be assigned as the head of list.
    }

    void InsTail(Node *&head, Node *&tail, int d) // Function to insert a node at end or tail of the linked list.
    {
        Node *temp = new Node(d); // Create a new Node 'temp'
        if (tail == NULL)         // If the list is empty
        {
            head = tail = temp; // New Node(temp) is now the tail of the linked list.
        }

        else // If the list is not empty
        {
            tail->next = temp; // Point the next pointer of the orignal tail to New Node(temp)
            tail = temp;       // New Node(temp)should now be assigned as the tail of the linked list.
        }
    }

    void InsAtPos(Node *&head, int pos, int d) // Function to insert a node at any position.
    {
        if (pos == 1) // If node is to be inserted at the beginning of the list
        {
            InsHead(head, d); // Call the InsHead function
            return;
        }
        else // If node is to be inserted at any other position
        {
            Node *temp = head; // Create a pointer temp that points to head of the linked list
            int count = 1;
            while (count < pos - 1) // While loop to traverse to the node before desired insertion position
            {
                temp = temp->next; // traverse by incrementing the position.
                count++;
            }
            Node *NTI = new Node(d); // Once the desired position has been reached create a new node NTI
            NTI->next = temp->next;  // New Node NTI next pointer should point to temp's next node.
            temp->next = NTI;        // The node before the desired position or temp's next pointer should point to our new Node
        }
    }

    void Delete(Node *&head, int pos) // Function to delete a node.
    {
        if (pos == 1) // If the node to be deleted is at the head or beginning of the linked list
        {
            Node *temp = head; // Create a pointer temp that points to head of the linked list (selects the head of the list)
            head = temp->next; // Assign Head to next position
            temp->next = NULL; // Original head next pointer should point to NULL
            delete temp;       // Delete the orignal head.
        }
        else if (head == NULL) // If there are no nodes in linked list.
        {
            cout << "List is Empty can't ,delete the element at pos " << pos << endl; // Display this message
        }

        else // If the desired position is something other than first one
        {
            int count = 1;
            Node *curr = head; // create a pointer curr that points to head of Linked list
            Node *prev = NULL; // create a pointer prev that points to NULL

            while (count < pos && curr != NULL) // traverse the list to desired position
            {
                prev = curr;       // prev and curr are at same position
                curr = curr->next; // curr is incremented
                count++;
            }
            if (curr == NULL) // if position entered in the list is not present
            {
                cout << "Exceeding list limit. Please redefine Position." << endl; // Display this message
                return;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }

    void Display(Node *&head) // Function to display All the elements
    {
        Node *temp = head; // Create pointer temp that points to head of the list.
        if (temp == NULL)  // If list is empty
        {
            cout << "No elements to display , List is empty." << endl; // Display this message.
        }
        while (temp != NULL) // While loop to traverse the list
        {
            cout << temp->data << " -> "; // Display data of the list
            temp = temp->next;            // increment the node position
        }
        cout << "NULL" << endl;
    }

    int GetLen(Node *&head) // Function to return the lenght of the list.
    {
        Node *temp = head;
        int len = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        cout << "The length of the list is " << len << endl;
        return len;
    }
};

int main()
{
    // Node *N1 = new Node(0);
    Node *head = NULL;
    Node *tail = NULL;
    Single *s1 = new Single;
    s1->Display(head);
    s1->InsTail(head, tail, 20);
    s1->InsTail(head, tail, 30);
    s1->InsTail(head, tail, 40);
    s1->InsTail(head, tail, 50);
    s1->Delete(head, 1);
    s1->Display(head);
    s1->Delete(head, 1);
    s1->Display(head);
    s1->GetLen(head);
    // s1->Delete(head, 1);
    // s1->Display(head);
}
