// اذكر الله
// صلِ على خير الخلق
#include <iostream>
using namespace std;

struct Queue
{
    // the first element in my queue
    int front = -1;
    // the last element in my queue
    int rear = -1;
    int *queue;
    int SIZE;
    Queue(int n)
    {
        SIZE = n;
        queue = new int[SIZE];
    }

    // function to check if my queue is full
    bool is_Full()
    {
        return rear == SIZE - 1;
    }

    // function to check if my queue is empty
    bool is_Empty()
    {
        return rear == -1;
    }

    // function to add element
    void inQueue(int element)
    {
        if (is_Full())
        {
            cout << "Queue Overflow\n";
            return;
        }
        // first element in my queue
        if (rear == -1)
            front++;
        // to add element in my queue
        rear++;
        queue[rear] = element;
    }

    // function to remove element from my queue
    void deQueue()
    {
        if (is_Empty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        // check if my queue has only one element and I want to delete it
        if (rear == front)
        {
            rear = -1, front = -1;
            return;
        }
        // delete element from the front of my queue
        front++;
    }

    void Display()
    {
        cout << "____________________________________________________________________\n";
        // check if my queue is empty
        if (is_Empty())
            cout << "Your queue is empty\n";
        else
        {
            // going from the first element to the last element in my queue
            for (int i = front; i <= rear; i++)
                cout << queue[i] << '\n';
        }
        cout << "____________________________________________________________________\n";
    }
};

int main()
{
    int SIZE;
    cout << "Please enter the size of your queue\n";
    cin >> SIZE;

    // create element from Queue struct with size which I have
    Queue queue(SIZE);

    // start using my queue
    while (true)
    {
        cout << "_________________Please enter what you need to do_________________ \n";
        cout << "           1 >> InQueue element to my Queue\n";
        cout << "           2 >> DeQueue element from my Queue\n";
        cout << "           3 >> Print my Queue\n";
        cout << "           0 >> Exit\n";
        cout << "____________________________________________________________________\n";
        int CHOICE;
        cin >> CHOICE;
        if (CHOICE == 1)
        {
            int element;
            cout << "Please enter the element\n";
            cin >> element;
            queue.inQueue(element);
        }
        else if (CHOICE == 2)
            queue.deQueue();
        else if (CHOICE == 3)
            queue.Display();
        else if (CHOICE == 0)
            break;
        else
            cout << "You have entered a wrong number, please try again\n";
    }

    return 0;
}