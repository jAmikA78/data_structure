// اذكر الله
// صلِ على خير الخلق
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

struct linkedlist
{
    node *head;
    linkedlist()
    {
        head = NULL;
    }

    void insert_at_beginning(int element)
    {
        node *temp = new node(element);
        temp->next = head; // 1st step
        head = temp;       // 2nd step
    }

    void insert_at_end(int element)
    {
        node *temp = new node(element);
        if (head == NULL)
        {
            insert_at_beginning(element);
            return;
        }
        node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
    }

    void insert_in_order(int element)
    {
        node *temp = new node(element);
        if (head == NULL || head->data >= element)
        {
            insert_at_beginning(element);
            return;
        }
        node *cur = head;
        while (cur->next != NULL && cur->next->data < element)
            cur = cur->next;
        temp->next = cur->next;
        cur->next = temp;
    }

    void insert_at_position(int element, int pos)
    {
        node *temp = new node(element);
        if (pos == 1)
        {
            insert_at_beginning(element);
            return;
        }
        node *cur = head;
        int cnt = 1;
        while (cnt < pos - 1 && cur != NULL)
            cnt++, cur = cur->next;
        if (cur == NULL)
        {
            insert_at_end(element);
            return;
        }
        temp->next = cur->next;
        cur->next = temp;
    }

    void delete_from_begainging()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    void delete_from_end()
    {
        if (head == NULL)
        {
            cout << "list  is empty\n";
            return;
        }
        if (head->next == NULL)
        {
            delete_from_begainging();
            return;
        }
        node *cur = head;
        while (cur->next->next != NULL)
            cur = cur->next;
        delete cur->next;
        cur->next = NULL;
    }

    void delete_from_position(int pos)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        if (pos <= 0)
        {
            cout << "invalid position\n";
            return;
        }
        if (pos == 1)
        {
            delete_from_begainging();
            return;
        }
        node *cur = head;
        int cnt = 1;
        while (cnt < pos - 1 && cur != NULL)
            cur = cur->next, cnt++;
        if (cur == NULL || cur->next == NULL)
        {
            delete_from_end();
            return;
        }
        node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    void delete_by_value(int element)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        if (head->data == element)
        {
            delete_from_begainging();
            return;
        }
        node *cur = head;
        while (cur->next != NULL && cur->next->data != element)
            cur = cur->next;
        if (cur->next == NULL)
        {
            cout << "value not found in your list\n";
            return;
        }
        node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    void update(int old_value, int new_value)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        node *cur = head;
        while (cur != NULL)
        {
            if (cur->data == old_value)
            {
                cur->data = new_value;
                return;
            }
            cur = cur->next;
        }
        cout << "invalid input\n";
    }

    int size_of_list()
    {
        int cnt = 0;
        node *cur = head;
        while (cur != NULL)
            cnt++,cur=cur->next;
        return cnt;
    }

    void display()
    {
        cout << "-----------here is your linkedlist's element------------------\n";
        node *cur = head;
        while (cur != NULL)
        {
            cout << cur->data << '\n';
            cur = cur->next;
        }
        cout << "-----------end of your linkedlist's element------------------\n";
    }
};

int main()
{
    linkedlist list;
    int x, y, z;
    while (true)
    {
        cout << "-------------please choose what you need-------------\n";
        cout << "1 >> insert at begining\n";
        cout << "2 >> insert at end\n";
        cout << "3 >> insert at position\n";
        cout << "4 >> insert in order\n";
        cout << "5 >> delete from begaining\n";
        cout << "6 >> delete from end\n";
        cout << "7 >> delete from position\n";
        cout << "8 >> delete by value\n";
        cout << "9 >> update value\n";
        cout << "10 >> show size of your list\n";
        cout << "99 >> display\n";
        cout << "0 >> exit\n";
        cin >> x;
        cout << "-------------end-------------\n";
        if (x == 1)
        {
            cout << "please enter elemnt you need to add\n";
            cin >> y;
            list.insert_at_beginning(y);
        }
        else if (x == 2)
        {
            cout << "please enter elemnt you need to add\n";
            cin >> y;
            list.insert_at_end(y);
        }
        else if (x == 3)
        {
            cout << "please enter elemnt you need to add\n";
            cin >> y;
            cout << "please enter poition of your element\n";
            cin >> z;
            list.insert_at_position(y, z);
        }
        else if (x == 4)
        {
            cout << "please enter elemnt you need to add\n";
            cin >> y;
            list.insert_in_order(y);
        }
        else if (x == 5)
            list.delete_from_begainging();
        else if (x == 6)
            list.delete_from_end();
        else if (x == 7)
        {
            cout << "please enter position of element you need to delete\n";
            cin >> y;
            list.delete_from_position(y);
        }
        else if (x == 8)
        {
            cout << "please enter the value of element you need to delete\n";
            cin >> y;
            list.delete_by_value(y);
        }
        else if (x == 9)
        {
            cout << "please enter value of item you need to update\n";
            cin >> y;
            cout << "please enter new value of item\n";
            cin >> z;
            list.update(y, z);
        }
        else if (x == 10)
           cout<< list.size_of_list()<<'\n';
        else if (x == 99)
            list.display();
        else if (x == 0)
            break;
        else
            cout << "Try again\n";
    }
    return 0;
}
