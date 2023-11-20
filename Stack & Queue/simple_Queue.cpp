#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int qfront;
    int qrear;

public:
    Queue()
    {
        size = 100;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    void Enqueue(int data)
    {
        if (qrear == size)
        {
            cout << "Queue is full." << endl;
        }
        else
        {
            arr[qrear] = data;
            qrear++;
        }
    }

    int Dequeue()
    {
        if (qfront == qrear)
        {
            cout << "Queue underflow." << endl;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == qrear)
            {
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    void IsEmpty()
    {
        if (qfront == qrear)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }

    int front()
    {
        if (qfront == qrear)
        {
            return -1; // Queue is empty
        }
        else
        {
            return arr[qfront];
        }
    }

    int rear()
    {
        if (qfront == qrear)
        {
            return -1;
        }
        else
        {
            int rearPos = (qrear - 1 + size) % size;
            cout << "Rear element is " << arr[rearPos] << endl;
        }
    }

    int lenght()
    {
        int len = 0;
        int current = qfront;

        while (current != qrear)
        {
            len++;
            current = (current + 1) % size; // Increment current while considering circular queue
        }

        if (len == 0)
        {
            cout << "Length is 0" << endl;
        }
        else
        {
            cout << "Length is " << len << endl;
        }

        return len;
    }
    void Display()
    {
        if (qfront == qrear)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            int current = qfront;
            while (current != qrear)
            {
                cout << arr[current] << " ";
                current = (current + 1) % size;
            }
            cout << "\n";
        }
    }
};

int main()
{
    Queue *Q = new Queue;
    Q->Enqueue(5);
    Q->Enqueue(6);
    Q->Enqueue(7);
    Q->Enqueue(8);
    Q->Enqueue(9);
    Q->Display();
    Q->Dequeue();
    Q->Display();
    Q->rear();
    Q->IsEmpty();
    return 0;
}
