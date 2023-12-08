// اذكر الله
// صلِ على خير الخلق
#include <iostream>
using namespace std;

struct Queue
{
    int front = -1;
    int rear = -1;
    int *queue;
    int SIZE;

    Queue(int n)
    {
        SIZE = n;
        queue = new int[SIZE];
    }

    bool is_Full()
    {
        // Check if the next position after the rear is the front
        return (rear + 1) % SIZE == front;
    }

    bool is_Empty()
    {
        return front == -1;
    }

    void inQueue(int element)
    {
        if (is_Full())
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (is_Empty())
            front = 0;

        // Circularly increment rear
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
    }

    void deQueue()
    {
        if (is_Empty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            // Circularly increment front
            front = (front + 1) % SIZE;
        }
    }

    void Display()
    {
        cout << "____________________________________________________________________\n";
        if (is_Empty())
            cout << "Your queue is empty\n";
        else
        {
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

int main()
{
    int SIZE;
    cout << "Please enter the size of your queue\n";
    cin >> SIZE;

    Queue queue(SIZE);

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
