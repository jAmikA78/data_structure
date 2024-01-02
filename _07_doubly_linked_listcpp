// اذكر الله
// صلِ على خير خلق الله محمد
// Include necessary header file for input and output operations
#include <iostream>
using namespace std;

// Define a structure for a node in the doubly linked list
struct node
{
    int data;         // Data of the node
    node *next;       // Pointer to the next node
    node *prev;       // Pointer to the previous node
    node(int element)  // Constructor to initialize a node with a given element
    {
        data = element;
        next = NULL;
        prev = NULL;
    }
};

// Define a structure for a doubly linked list
struct linked_list
{
    node *head;        // Pointer to the head of the doubly linked list
    linked_list()      // Constructor to initialize an empty doubly linked list
    {
        head = NULL;
    }

    // Insert a node at the beginning of the doubly linked list
    void insertatbeginning(int element)
    {
        node *temp = new node(element);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
        }
    }

    // Insert a node at the end of the doubly linked list
    void insertatend(int element)
    {
        node *temp = new node(element);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *cur = head;
            while (cur->next != NULL)
                cur = cur->next;
            cur->next = temp;
            temp->prev = cur;
        }
    }

    // Insert a node in sorted order in the doubly linked list
    void insertsorted(int element)
    {
        node *temp = new node(element);
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
        }
        else
        {
            node *cur = head;
            while (cur != NULL && cur->data > element)
            {
                cur = cur->next;
            }
            temp->next = cur;
            temp->prev = cur->prev;
            if (cur->prev != NULL)
            {
                cur->prev->next = temp;
            }
            cur->prev = temp;
            if (temp->prev == NULL)
            {
                head = temp;
            }
        }
    }

    // Search for a value in the doubly linked list
    bool search(int value)
    {
        node *cur = head;
        while (cur != NULL)
        {
            if (cur->data == value)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    // Delete a node from the beginning of the doubly linked list
    void deletefrombeginning()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
        }
    }

    // Delete a node from the end of the doubly linked list
    void deletefromend()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            node *cur = head;
            if (cur->next == NULL)
                deletefrombeginning();
            else
            {
                while (cur->next->next != NULL)
                {
                    cur = cur->next;
                }
                delete cur->next;
                cur->next = NULL;
            }
        }
    }

    // Delete a node with a specific value from the doubly linked list
    void deleteitem(int value)
    {
        if (head == NULL)
            cout << "list is empty\n";
        else if (search(value))
        {
            node *cur = head;
            node *temp2 = NULL;
            if (head->data == value)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    delete (cur);
                }
                else
                {
                    head = head->next;
                    head->prev = NULL;
                    delete cur;
                }
            }
            else
            {
                while ((cur->data != value) && (cur != NULL))
                {
                    temp2 = cur;
                    cur = cur->next;
                }
                if (cur->next == NULL)
                {
                    temp2->next = NULL;
                    delete cur;
                }
                else
                {
                    temp2->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete (cur);
                }
            }
        }
        else
            cout << "not found";
    }

    // Display the doubly linked list elements along with their next and previous nodes
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->next != NULL)
                cout << "Next: " << temp->next->data << " ";
            if (temp->prev != NULL)
                cout << "Prev: " << temp->prev->data;
            cout << endl;
            temp = temp->next;
        }
        cout << "END" << endl;
    }
};


// Main function
int main()
{
    linked_list list;
    int x, y;
    while (true)
    {
        // User menu for doubly linked list operations
        cout << "-------------please choose what you need-------------\n";
        cout << "1 >> insert at beginning\n";
        cout << "2 >> insert at end\n";
        cout << "3 >> insert in sorted order\n";
        cout << "4 >> delete from beginning\n";
        cout << "5 >> delete from end\n";
        cout << "6 >> delete by value\n";
        cout << "7 >> display\n";
        cout << "0 >> exit\n";
        cin >> x;
        cout << "-------------end-------------\n";

        // Perform the selected operation based on user input
        if (x == 1)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            list.insertatbeginning(y);
        }
        else if (x == 2)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            list.insertatend(y);
        }
        else if (x == 3)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            list.insertsorted(y);
        }
        else if (x == 4)
            list.deletefrombeginning();
        else if (x == 5)
            list.deletefromend();
        else if (x == 6)
        {
            cout << "please enter the value of element you need to delete\n";
            cin >> y;
            list.deleteitem(y);
        }
        else if (x == 7)
            list.display();
        else if (x == 0)
            break;
        else
            cout << "Try again\n";
    }
    return 0;
}
