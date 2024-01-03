// اذكر الله
// صلِ على خير خلق الله محمد
// Include necessary header file for input and output operations
#include <iostream>
using namespace std;

// create struct to define stack functions
struct Stack
{
    int top = -1; // the top element in my stack
    int *stack;   // pointer to intialize stack as array
    int SIZE;     // size of the stack

    // n here refer to user input (size of the stack)
    Stack(int n)
    {
        SIZE = n;
        // create array of the stack
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
        // remove element from the top of the stack by decrement top by 1
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

// main function
int main()
{
    // get size of the stack from user
    int SIZE;
    cout << "Please enter the size of your stack\n";
    cin >> SIZE;

    // create a new stack named (myStack) with size which user entered before
    Stack myStack(SIZE);

    // start using my stack
    while (true)
    {
        // take user choice
        cout << "_________________Please enter what you need to do_________________ \n";
        cout << "           1 >> Push element onto the stack\n";
        cout << "           2 >> Pop element from the stack\n";
        cout << "           3 >> Print the stack\n";
        cout << "           0 >> Exit\n";
        cout << "____________________________________________________________________\n";
        int CHOICE;
        cin >> CHOICE;
        // user decied to push element
        if (CHOICE == 1)
        {
            int element;
            cout << "Please enter the element\n";
            cin >> element;
            myStack.push(element);
        }
        // user decied to pop element
        else if (CHOICE == 2)
            myStack.pop();
        // user decied to print the stack
        else if (CHOICE == 3)
            myStack.Display();
        // user decied to exit the program
        else if (CHOICE == 0)
            break;
        // user entered wrong choice
        else
            cout << "You have entered a wrong number, please try again\n";
    }
    // end of the program
    return 0;
}
