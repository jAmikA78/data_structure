// اذكر الله
// صلِ على خير خلق الله محمد
// Include necessary header file for input and output operations
#include <iostream>
using namespace std;

// Define a structure for a node in the linked stack
struct node
{
    int data;         // Data of the node
    node *next;       // Pointer to the next node
    node(int element)  // Constructor to initialize a node with a given element
    {
        data = element;
        next = NULL;
    }
};

// Define a structure for a linked stack
struct linked_Stack
{
    node *head;        // Pointer to the head of the linked stack
    linked_Stack()     // Constructor to initialize an empty linked stack
    {
        head = NULL;
    }

    // Insert (push) an element to the linked stack
    void insert(int element)
    {
        node *temp = new node(element);
        temp->next = head;
        head = temp;
    }

    // Remove (pop) an element from the linked stack
    void remove()
    {
        if (head == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    // Display the elements of the linked stack
    void display()
    {
        cout << "________________________________________\n";
        if (head == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        node *cur = head;
        while (cur != NULL)
        {
            cout << cur->data << '\n';
            cur = cur->next;
        }
    }
};

// Main function
int main()
{
    linked_Stack stack;
    int x, y;
    while (true)
    {
        // User menu for linked stack operations
        cout << "________________________________________\n";
        cout << "1 >> insert\n";
        cout << "2 >> remove\n";
        cout << "3 >> display\n";
        cout << "0 >> exit\n";
        cout << "________________________________________\n";
        cin >> x;
        if (x == 1)
        {
            // Insert operation
            cout << "please enter the element\n";
            cin >> y;
            stack.insert(y);
        }
        else if (x == 2)
        {
            // Remove operation
            stack.remove();
        }
        else if (x == 3)
        {
            // Display operation
            stack.display();
        }
        else if (x == 0)
        {
            // Exit the program
            break;
        }
        else
        {
            // Invalid input, prompt user to try again
            cout << "Try again\n";
        }
    }
    return 0;
}
