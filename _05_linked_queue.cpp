// اذكر الله
// صلِ على خير خلق الله محمد
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int element)
    {
        data = element;
        next = NULL;
    }
};

struct linked_Queue
{
    node *head;
    node *last;
    linked_Queue()
    {
        head = NULL;
        last = NULL;
    }

    void inQueue(int element)
    {
        node *temp = new node(element);
        if (last == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    void deQueue()
    {
        if (head == NULL)
        {
            cout << "Queu is empty\n";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            last = NULL;
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display()
    {
        cout << "________________________________________________\n";
        if (head == NULL)
        {
            cout << "Queu is empty\n";
            return;
        }
        else
        {
            node *cur = head;
            while (cur != NULL)
            {
                cout << cur->data << '\n';
                cur = cur->next;
            }
        }
    }
};

int main()
{
    linked_Queue queue;
    int x, y;
    while (true)
    {
        cout << "________________________________________________\n";
        cout << "1 >> inQueue\n";
        cout << "2 >> deQueue\n";
        cout << "3 >> display\n";
        cout << "0 >> exit\n";
        cin >> x;
        if (x == 1)
        {
            cout << "enter the element you need to add\n";
            cin >> y;
            queue.inQueue(y);
        }
        else if (x == 2)
            queue.deQueue();
        else if (x == 3)
            queue.display();
        else if (x == 0)
            break;
            else 
            cout<<"try again\n";
    }
    return 0;
}