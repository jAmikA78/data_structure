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

struct linked_Stack
{
    node *head;
    linked_Stack()
    {
        head = NULL;
    }

    void insert(int element)
    {
        node *temp = new node(element);
        temp->next = head;
        head = temp;
    }

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

int main()
{

    linked_Stack stack;
    int x, y;
    while (true)
    {
        cout << "________________________________________\n";
        cout << "1 >> insert\n";
        cout << "2 >> remove\n";
        cout << "3 >> display\n";
        cout << "0 >> exit\n";
        cout << "________________________________________\n";
        cin >> x;
        if (x == 1)
        {
            cout << "please enter the element\n";
            cin >> y;
            stack.insert(y);
        }
        else if (x == 2)
            stack.remove();
        else if (x == 3)
            stack.display();
        else if (x == 0)
            break;
        else
            cout << "Try again\n";
    }
    return 0;
}