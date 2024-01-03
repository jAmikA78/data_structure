// اذكر الله
// صلِ على خير خلق الله محمد
// Include necessary header file for input and output operations
#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct node
{
    int data;         // Data of the node
    node *next;       // Pointer to the next node
    node(int element) // Constructor to initialize a node with a given element
    {
        data = element;
        next = NULL;
    }
};

// Define a structure for a linked list
struct linkedlist
{
    node *head;  // Pointer to the head of the linked list
    linkedlist() // Constructor to initialize an empty linked list
    {
        head = NULL;
    }

    // check if the linked list is empty
    bool is_empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    // Insert an element at the beginning of the linked list
    void insert_at_beginning(int element)
    {
        node *temp = new node(element);
        temp->next = head; // 1st step
        head = temp;       // 2nd step
    }

    // Insert an element at the end of the linked list
    void insert_at_end(int element)
    {
        node *temp = new node(element);
        // if linked list is empty so insert in begaining is the same with insert at end
        if (is_empty())
        {
            insert_at_beginning(element);
            return;
        }
        // find the end of my linked list
        node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        // insert node in the end
        cur->next = temp;
    }

    // Insert an element in sorted order in the linked list
    void insert_in_order(int element)
    {
        node *temp = new node(element);
        // check the 2 conditions to add it in begaining
        // 1st : linked list is empty
        // 2nd : the first element in my linked list is greater than or equal the node i need to add
        if (is_empty() || head->data >= element)
        {
            insert_at_beginning(element);
            return;
        }
        // find the targeted possition have 2 condition
        // 1st : if i reach the end it''s mean all of the list element is less targeted node and i will add it in the end
        // 2nd : find the first element is greater than targeted node and add it before it
        node *cur = head;
        while (cur->next != NULL && cur->next->data < element)
            cur = cur->next;
        // add node in the targeted position
        temp->next = cur->next;
        cur->next = temp;
    }

    // Insert an element at a specified position in the linked list
    void insert_at_position(int element, int pos)
    {
        node *temp = new node(element);
        // insert in the begaining if targeted possition = 1
        if (pos == 1)
        {
            insert_at_beginning(element);
            return;
        }
        // find the targeted possition
        node *cur = head;
        int cnt = 1;
        while (cnt < pos - 1 && cur != NULL)
            cnt++, cur = cur->next;
        // if i reach the targeted possition is greater then linked list size
        if (cur == NULL)
        {
            insert_at_end(element);
            return;
        }
        // insert in the targeted possition
        temp->next = cur->next;
        cur->next = temp;
    }

    // Delete the first element from the beginning of the linked list
    void delete_from_begainging()
    {

        if (is_empty())
        {
            cout << "list is empty\n";
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the last element from the end of the linked list
    void delete_from_end()
    {
        if (is_empty())
        {
            cout << "list is empty\n";
            return;
        }
        // if the list have only one element so delete from the begainig is equal to delete from the end
        if (head->next == NULL)
        {
            delete_from_begainging();
            return;
        }
        // find end of the lisr
        node *cur = head;
        while (cur->next->next != NULL)
            cur = cur->next;
        // delete last element
        delete cur->next;
        cur->next = NULL;
    }

    // Delete the element at a specified position in the linked list
    void delete_from_position(int pos)
    {
        if (is_empty())
        {
            cout << "list is empty\n";
            return;
        }
        // position must be greater then or equal 1
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
        // get the targeted position
        node *cur = head;
        int cnt = 1;
        while (cnt < pos - 1 && cur != NULL)
            cur = cur->next, cnt++;
        // if i rach end of the list or the targetd element is the last element
        // i will delete the last element in the list
        if (cur == NULL || cur->next == NULL)
        {
            delete_from_end();
            return;
        }
        // delete the targeted element
        node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    // Delete the first occurrence of a specified value from the linked list
    void delete_by_value(int element)
    {
        if (is_empty())
        {
            cout << "list is empty\n";
            return;
        }
        // check if targeted element is the ffirst element
        if (head->data == element)
        {
            delete_from_begainging();
            return;
        }
        // get the targeted element possition
        node *cur = head;
        while (cur->next != NULL && cur->next->data != element)
            cur = cur->next;
        // if i reach the end of the list and i didnt fint targeted element
        if (cur->next == NULL)
        {
            cout << "value not found in your list\n";
            return;
        }
        // delete the targeted element
        node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    // Update the first occurrence of a specified old value with a new value
    void update(int old_value, int new_value)
    {
        if (is_empty())
        {
            cout << "list is empty\n";
            return;
        }
        // get the targeted element possition and replace if found
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
        // the targeted element is not found
        cout << "invalid input, the targeted element is not found\n";
    }

    // Get the size of the linked list
    int size_of_list()
    {
        int cnt = 0;
        node *cur = head;
        while (cur != NULL)
            cnt++, cur = cur->next;
        return cnt;
    }

    // Display the elements of the linked list
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

// Main function
int main()
{
    linkedlist list;
    int x, y, z;
    while (true)
    {
        // User menu for linked list operations
        cout << "-------------please choose what you need-------------\n";
        cout << "1 >> insert at beginning\n";
        cout << "2 >> insert at end\n";
        cout << "3 >> insert at position\n";
        cout << "4 >> insert in order\n";
        cout << "5 >> delete from beginning\n";
        cout << "6 >> delete from end\n";
        cout << "7 >> delete from position\n";
        cout << "8 >> delete by value\n";
        cout << "9 >> update value\n";
        cout << "10 >> show size of your list\n";
        cout << "99 >> display\n";
        cout << "0 >> exit\n";
        cin >> x;
        cout << "-------------end-------------\n";

        // user decide to insert at begaining
        if (x == 1)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            list.insert_at_beginning(y);
        }
        // user decide to insert at end
        else if (x == 2)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            list.insert_at_end(y);
        }
        // user decide to insert at targeted possition
        else if (x == 3)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            cout << "please enter position of your element\n";
            cin >> z;
            list.insert_at_position(y, z);
        }
        // user decide to insert in sorted order
        else if (x == 4)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            list.insert_in_order(y);
        }
        // user decide to delete from begaining
        else if (x == 5)
            list.delete_from_begainging();
        // user decide to delete from end
        else if (x == 6)
            list.delete_from_end();
        // user decide to delete specific element by it's possition
        else if (x == 7)
        {
            cout << "please enter position of element you need to delete\n";
            cin >> y;
            list.delete_from_position(y);
        }
        // user decide to delete specific element by it's value
        else if (x == 8)
        {
            cout << "please enter the value of element you need to delete\n";
            cin >> y;
            list.delete_by_value(y);
        }
        // user decide to  change specific value
        else if (x == 9)
        {
            cout << "please enter value of item you need to update\n";
            cin >> y;
            cout << "please enter new value of item\n";
            cin >> z;
            list.update(y, z);
        }
        // user decide to get size of the list
        else if (x == 10)
            cout << list.size_of_list() << '\n';
        // user decide to print list
        else if (x == 99)
            list.display();
        // user decide to exit the program
        else if (x == 0)
            break;
        // user entered a wrong choise
        else
            cout << "Try again\n";
    }
    // end of the program
    return 0;
}
