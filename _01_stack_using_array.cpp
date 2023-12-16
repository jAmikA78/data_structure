// اذكر الله
// صلِ على خير خلق الله محمد 
#include <iostream>
using namespace std;

struct Stack
{
    // the top element in my stack
    int top = -1;
    int *stack;
    int SIZE;

    Stack(int n)
    {
        SIZE = n;
        stack = new int[SIZE];
    }

    // function to check if my stack is full
    bool is_Full()
    {
        return top == SIZE - 1;
    }

    // function to check if my stack is empty
    bool is_Empty()
    {
        return top == -1;
    }

    // function to push element onto the stack
    void push(int element)
    {
        if (is_Full())
        {
            cout << "Stack Overflow\n";
            return;
        }
        // add element to the top of the stack
        stack[++top] = element;
    }

    // function to pop element from the stack
    void pop()
    {
        if (is_Empty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        // remove element from the top of the stack
        top--;
    }

    void Display()
    {
        cout << "____________________________________________________________________\n";
        // check if my stack is empty
        if (is_Empty())
            cout << "Your stack is empty\n";
        else
        {
            // going from the top element to the bottom element in my stack
            for (int i = top; i >= 0; i--)
                cout << stack[i] << '\n';
        }
        cout << "____________________________________________________________________\n";
    }
};

int main()
{
    int SIZE;
    cout << "Please enter the size of your stack\n";
    cin >> SIZE;

    // create element from Stack struct with size which I have
    Stack myStack(SIZE);

    // start using my stack
    while (true)
    {
        cout << "_________________Please enter what you need to do_________________ \n";
        cout << "           1 >> Push element onto the stack\n";
        cout << "           2 >> Pop element from the stack\n";
        cout << "           3 >> Print the stack\n";
        cout << "           0 >> Exit\n";
        cout << "____________________________________________________________________\n";
        int CHOICE;
        cin >> CHOICE;
        if (CHOICE == 1)
        {
            int element;
            cout << "Please enter the element\n";
            cin >> element;
            myStack.push(element);
        }
        else if (CHOICE == 2)
            myStack.pop();
        else if (CHOICE == 3)
            myStack.Display();
        else if (CHOICE == 0)
            break;
        else
            cout << "You have entered a wrong number, please try again\n";
    }

    return 0;
}
