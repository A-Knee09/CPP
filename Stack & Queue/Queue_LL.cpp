#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
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

class Queue
{
public:
    void enqueue(Node *&front, Node *&rear, int d)
    {
        Node *temp = new Node(d);
        if (rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue(Node *&front)
    {
        if (front == NULL)
        {
            cout << "Cannot dequeue elements , Queue underflow." << endl;
        }
        else
        {
            Node *temp = front;
            front = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void peek(Node *&front)
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            Node *temp = front;
            cout << temp->data << endl;
        }
    }

    void display(Node *&front)
    {
        if (front == NULL)
        {
            cout << "Queue is empty, please insert elements to display." << endl;
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void IsEmpty(Node *&front)
    {
        if (front == NULL)
        {
            cout << "True." << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
};

int main()
{
    Node *front = NULL;
    Node *rear = NULL;
    Queue *Q1 = new Queue;
    Q1->display(front);
    Q1->enqueue(front, rear, 10);
    Q1->enqueue(front, rear, 20);
    Q1->enqueue(front, rear, 30);
    Q1->enqueue(front, rear, 40);
    Q1->display(front);
    Q1->dequeue(front);
    Q1->peek(front);
    Q1->IsEmpty(front);
}
