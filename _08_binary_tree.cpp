// اذكر الله
// صلِ على خير خلق الله محمد
// Include necessary header file for input and output operations
#include <iostream>
using namespace std;

// Define a structure for a node in the Binary Search Tree (BST)
struct node
{
    int data;         // Data of the node
    node *right;      // Pointer to the right child node
    node *left;       // Pointer to the left child node
    node(int element)  // Constructor to initialize a node with a given element
    {
        data = element;
        right = NULL;
        left = NULL;
    }
};

// Define a structure for a Binary Search Tree (BST)
struct Tree
{
    node *root;        // Pointer to the root of the BST
    Tree()             // Constructor to initialize an empty BST
    {
        root = NULL;
    }

    // Insert a new element into the BST
    void insert(node *&temp, int element)
    {
        if (temp == NULL)
        {
            node *newnode = new node(element);
            temp = newnode;
        }
        else if (temp->data < element)
            insert(temp->right, element);
        else
            insert(temp->left, element);
        return;
    }

    // Delete an element from the BST
    void delete_element(node *&temp, int element)
    {
        if (temp == NULL)
        {
            cout << "not Found";
        }
        else if (temp->data == element)
        {
            if (temp->left == NULL)
            {
                node *temp_right = temp->right;
                delete temp;
                temp = temp_right;
            }
            else if (temp->right == NULL)
            {
                node *temp_left = temp->left;
                delete temp;
                temp = temp_left;
            }
            else
            {
                node *save_sort = min_node(temp->right);
                temp->data = save_sort->data;
                delete_element(temp->right, save_sort->data);
            }
        }
        else if (temp->data > element)
            delete_element(temp->left, element);
        else
            delete_element(temp->right, element);
    }

    // Find the node with the minimum value in the BST
    node *min_node(node *temp)
    {
        if (temp == NULL)
        {
            cout << "tree is empty\n";
            return NULL;
        }
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    // Find the node with the maximum value in the BST
    node *max_node(node *temp)
    {
        if (temp == NULL)
        {
            cout << "tree is empty\n";
            return NULL;
        }
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    // Traverse the BST in-order and print the elements
    void in_order(node *temp)
    {
        if (temp != NULL)
        {
            in_order(temp->left);
            cout << temp->data << ' ';
            in_order(temp->right);
        }
        else
            cout << '\n';
    }

    // Traverse the BST pre-order and print the elements
    void pre_order(node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << ' ';
            pre_order(temp->left);
            pre_order(temp->right);
        }
        else
            cout << '\n';
    }

    // Traverse the BST post-order and print the elements
    void post_order(node *temp)
    {
        if (temp != NULL)
        {
            post_order(temp->left);
            post_order(temp->right);
            cout << temp->data << ' ';
        }
        else
            cout << '\n';
    }
};

// Main function
int main()
{
    Tree tree;
    int x, y;
    while (true)
    {
        // User menu for Binary Search Tree (BST) operations
        cout << "_____________choose what you need to do_____________\n";
        cout << "1 >> insert\n";
        cout << "2 >> delete\n";
        cout << "3 >> get_min\n";
        cout << "4 >> get_max\n";
        cout << "5 >> in_order\n";
        cout << "6 >> pre_order\n";
        cout << "7 >> post_order\n";
        cout << "0 >> exit\n";
        cin >> x;
        cout << "____________________________________________________\n";

        // Perform the selected operation based on user input
        if (x == 1)
        {
            cout << "please enter element you need to add\n";
            cin >> y;
            tree.insert(tree.root, y);
        }
        else if (x == 2)
        {
            cout << "please enter element you need to delete\n";
            cin >> y;
            tree.delete_element(tree.root, y);
        }
        else if (x == 3)
            cout << tree.min_node(tree.root)->data << '\n';
        else if (x == 4)
            cout << tree.max_node(tree.root)->data << '\n';
        else if (x == 5)
            tree.in_order(tree.root);
        else if (x == 6)
            tree.pre_order(tree.root);
        else if (x == 7)
            tree.post_order(tree.root);
        else if (x == 0)
            break;
        else
            cout << "try again\n";
    }

    return 0;
}
