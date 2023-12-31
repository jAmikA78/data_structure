// اذكر الله
// صلِ على خير خلق الله محمد
// Include necessary header file for input and output operations
#include <iostream>
using namespace std;

// Define a structure for the Queue
struct Queue
{
    int front = -1; // Initialize front to -1
    int rear = -1;  // Initialize rear to -1
    int *queue;     // Pointer to the array representing the queue
    int SIZE;       // Maximum size of the queue

    // n here refer to user input of queue size
    Queue(int n)
    {
        SIZE = n;
        // create queue with  size which user entered before
        queue = new int[SIZE];
    }

    // Check if the queue is full
    bool is_Full()
    {
        // Check if the next position after the rear is the front
        return (rear + 1) % SIZE == front;
    }

    // Check if the queue is empty
    bool is_Empty()
    {
        return front == -1;
    }

    // Add an element to the queue
    void inQueue(int element)
    {
        if (is_Full())
        {
            cout << "Queue Overflow\n";
            return;
        }

        // add first element in queue
        if (is_Empty())
            front = 0;
        // Circularly increment rear and add the element
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
    }

    // Remove an element from the queue
    void deQueue()
    {
        if (is_Empty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear)
        {
            // If there is only one element in the queue, reset front and rear to -1
            front = -1;
            rear = -1;
        }
        else
        {
            // Circularly increment front
            front = (front + 1) % SIZE;
        }
    }

    // Display the elements of the queue
    void Display()
    {
        cout << "____________________________________________________________________\n";
        if (is_Empty())
            cout << "Your queue is empty\n";
        else
        {
            // Display the elements from front to rear in a circular manner
            int i = front;
            do
            {
                cout << queue[i] << '\n';
                i = (i + 1) % SIZE;
            } while (i != (rear + 1) % SIZE);
        }
        cout << "____________________________________________________________________\n";
    }
};

// Main function
int main()
{
    int SIZE;
    cout << "Please enter the size of your queue\n";
    cin >> SIZE;

    // Create a queue object with the specified size
    Queue queue(SIZE);

    while (true)
    {
        // User menu for queue operations
        cout << "_________________Please enter what you need to do_________________ \n";
        cout << "           1 >> InQueue element to my Queue\n";
        cout << "           2 >> DeQueue element from my Queue\n";
        cout << "           3 >> Print my Queue\n";
        cout << "           0 >> Exit\n";
        cout << "____________________________________________________________________\n";

        // User input for the selected operation
        int CHOICE;
        cin >> CHOICE;

        // user decied to add element
        if (CHOICE == 1)
        {
            int element;
            cout << "Please enter the element\n";
            cin >> element;
            queue.inQueue(element);
        }
        // user decied to delete element
        else if (CHOICE == 2)
            queue.deQueue();
        // user decied to print the queue
        else if (CHOICE == 3)
            queue.Display();
        // user decide to Exit the program
        else if (CHOICE == 0)
            break;
        // user entered wrong choise
        else
            cout << "You have entered a wrong number, please try again\n";
    }
    // end of the program
    return 0;
}
