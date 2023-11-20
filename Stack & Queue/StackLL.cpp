#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

class stack
{
public:
    void push(Node *&head, int d)
    {
        Node *temp = new Node(d);
        if (head == NULL)
        {
            head = temp;
        }

        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void pop(Node *&head)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Can't pop element further, Stack underflow." << endl;
        }
        else
        {
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    }

    void peek(Node *&head)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "Can't display element. Stack is empty." << endl;
        }

        else
        {
            cout << temp->data << endl;
        }
    }

    void Display(Node *&head)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "Can't display elements. Stack is empty." << endl;
        }

        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void IsEmpty(Node *&head)
    {
        if (head == NULL)
        {
            cout << "Stack is empty." << endl;
        }

        else
        {
            cout << "Stack is not empty" << endl;
        }
    }

    int size(Node *&head)
    {
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        cout << "Lenght of the stack is " << len << endl;
        return len;
    }
};

int main()
{
    Node *N1 = new Node(0);
    Node *head = N1;
    stack *s1 = new stack;
    s1->peek(head);
    s1->pop(head);
    s1->peek(head);
    s1->push(head, 10);
    s1->push(head, 20);
    s1->push(head, 30);
    s1->Display(head);
    s1->size(head);
}
