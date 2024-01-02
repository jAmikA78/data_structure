// اذكر الله
// صلِ على خير خلق الله محمد
// Include necessary header file for input and output operations
#include <iostream>
using namespace std;

// Define a structure for a node in the linked queue
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

// Define a structure for a linked queue
struct linked_Queue
{
    node *head;        // Pointer to the head of the linked queue
    node *last;        // Pointer to the last node of the linked queue
    linked_Queue()     // Constructor to initialize an empty linked queue
    {
        head = NULL;
        last = NULL;
    }

    // Enqueue (add) an element to the linked queue
    void inQueue(int element)
    {
        node *temp = new node(element);
        if (last == NULL)
        {
            // If the queue is empty, set both head and last to the new node
            head = temp;
            last = temp;
        }
        else
        {
            // Add the new node to the end of the queue and update last
            last->next = temp;
            last = temp;
        }
    }

    // Dequeue (remove) an element from the linked queue
    void deQueue()
    {
        if (head == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }
        if (head->next == NULL)
        {
            // If there's only one element, delete it and set head and last to NULL
            delete head;
            head = NULL;
            last = NULL;
        }
        else
        {
            // Remove the front node and update head
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Display the elements of the linked queue
    void display()
    {
        cout << "________________________________________________\n";
        if (head == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }
        else
        {
            // Traverse and display the elements in the queue
            node *cur = head;
            while (cur != NULL)
            {
                cout << cur->data << '\n';
                cur = cur->next;
            }
        }
    }
};

// Main function
int main()
{
    linked_Queue queue;
    int x, y;
    while (true)
    {
        // User menu for linked queue operations
        cout << "________________________________________________\n";
        cout << "1 >> inQueue\n";
        cout << "2 >> deQueue\n";
        cout << "3 >> display\n";
        cout << "0 >> exit\n";
        cin >> x;
        if (x == 1)
        {
            // Enqueue operation
            cout << "Enter the element you need to add\n";
            cin >> y;
            queue.inQueue(y);
        }
        else if (x == 2)
        {
            // Dequeue operation
            queue.deQueue();
        }
        else if (x == 3)
        {
            // Display operation
            queue.display();
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
