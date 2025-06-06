// B-6 Beginning with an empty binary search tree, Construct binary search tree by inserting
// the values in the order given. After constructing a binary tree -
// i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
// value found in the tree, iv. Change a tree so that the roles of the left and right pointers
// are swapped at every node, v. Search a value 

#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class bst {
public:
    node* root;

    bst() {
        root = NULL;
    }

    void create(node*& root) {
        int total, data;
        cout << "Enter the total number of elements: ";
        cin >> total;
        for (int i = 0; i < total; i++) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> data;
            insert(root, data);
        }
    }

    void insert(node*& root, int data) {
        if (root == NULL) {
            root = new node;
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }
        else if (data < root->data) {
            insert(root->left, data);
        }
        else if (data > root->data) {
            insert(root->right, data);
        }
    }

    int findmax(node* root) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return -1;
        }
        while (root->right != NULL) {
            root = root->right;
        }
        cout << "Maximum value: " << root->data << endl;
        return root->data;
    }

    int findmin(node* root) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return -1;
        }
        while (root->left != NULL) {
            root = root->left;
        }
        cout << "Minimum value: " << root->data << endl;
        return root->data;
    }

    void search(node* root, int value) {
        while (root != NULL) {
            if (root->data == value) {
                cout << "Value " << value << " found in the tree." << endl;
                break;
            }
            else if (value < root->data) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        cout << "Value " << value << " not found in the tree." << endl;
    }

    void mirror(node*& root) {
        if (root == NULL) {
            return;
        }

        // Swap left and right
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirror(root->left);
        mirror(root->right);
    }

    int height(node* root) {
        if (root == NULL) {
            return 0;
        }
        int hl = height(root->left);
        int hr = height(root->right);
        return max(hl, hr) + 1;
    }

    void Display(node* root) {
        if (root != NULL) {
            Display(root->left);
            cout << root->data << " ";
            Display(root->right);
        }
    }
};

int main() {
    bst B;
    int data;
    int value;
    int choice;

    do {
        cout << "\n--Menu--" << endl;
        cout << "1. Create BST" << endl;
        cout << "2. Insert Node" << endl;
        cout << "3. Find Maximum" << endl;
        cout << "4. Find Minimum" << endl;
        cout << "5. Display BST (Inorder)" << endl;
        cout << "6. Search Value" << endl;
        cout << "7. Mirror BST" << endl;
        cout << "8. Find Height" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            B.create(B.root);
            break;

        case 2:
            cout << "Enter the number to be inserted: ";
            cin >> data;
            B.insert(B.root, data);
            break;

        case 3:
            B.findmax(B.root);
            break;

        case 4:
            B.findmin(B.root);
            break;

        case 5:
            cout << "BST (Inorder): ";
            B.Display(B.root);
            cout << endl;
            break;

        case 6:
            cout << "Enter the value to be searched: ";
            cin >> value;
            B.search(B.root, value);
            break;

        case 7:
            B.mirror(B.root);
            cout << "BST mirrored. Inorder traversal after mirroring: ";
            B.Display(B.root);
            cout << endl;
            break;

        case 8:
            cout << "Height of BST: " << B.height(B.root) << endl;
            break;

        case 9:
            cout << "---END---" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 9);

    return 0;
}
