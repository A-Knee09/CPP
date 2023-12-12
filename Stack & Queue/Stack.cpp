#include <iostream>
using namespace std;

class stack
{
public:
    int size; // size of the array;
    int top;  // acts as the index;
    int *arr; // dynamic array;

    stack(int size) // Constructor to initialize size and create array;
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) // Function to insert element;
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }

        else
        {
            cout << "Can't enter more elements.Stack Overflow.";
            cout << endl;
        }
    }

    void pop() // Fucntion to remove the element from the top of stack;
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Can't remove elements further.Stack Underflow.";
            cout << endl;
        }
    }

    int peek() // Returns the top most element in stack;
    {
        if (top >= 0)
        {
            cout << arr[top];
        }
        else
        {
            cout << "Stack is empty, nothing to display";
        }
    }

    bool IsEmpty() // T/F to check if stack is empty.
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsFull() // T/F to check if stack is Full.
    {
        if (top + 1 == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int Length()
    {
        return top + 1;
    }

    void print()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    stack *st = new stack(4);
    st->push(10);
    st->push(20);
    st->push(30);
    st->push(40);
    st->push(50);
    cout << endl;
    st->peek();
    cout << endl;
    st->display();
    st->pop();
    // st->pop();
    // st->pop();
    // st->peek();
    // cout << endl;
    // st->pop();
    // st->pop();
    // cout << endl;
    if (st->IsFull())
    {
        cout << "Stack is full.";
    }
    else
    {
        cout << "Stack is not full.";
    }
}
