#include <iostream>
using namespace std;
class BST
{
private:
    int data;
    BST *left;
    BST *right;

public:
    BST()
    {
        data = 0;
        left = NULL;
        right = NULL;
    };
    BST(int value)
    {
        data = value;
        left = right = NULL;
    }
    BST *insert(BST *root, int x)
    {
        if (!root)
        {
            return new BST(x);
        }
        if (x > root->data)
        {
            root->right = insert(root->right, x);
        }
        else if (x < root->data)
        {
            root->left = insert(root->left, x);
        }
        return root;
    }
    BST *search(BST *root, int key)
    {
        if (root == NULL || root->data == key)
            return root;
        if (root->data < key)
            return search(root->right, key);
        else
            return search(root->left, key);
    }
    BST *minValueNode(BST *node)
    {
        BST *current = node;

        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    BST *deleteNode(BST *root, int key)
    {
        if (root == NULL)
            return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL and root->right == NULL)
                return NULL;

            else if (root->left == NULL)
            {
                BST *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                BST *temp = root->left;
                free(root);
                return temp;
            }

            BST *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    void inorder(BST *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(BST *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(BST *root)
    {
        if (!root)
        {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void printLevelOrder(BST *root)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevel(root, i);
    }
    void printCurrentLevel(BST *root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
            cout << root->data << " ";
        else if (level > 1)
        {
            printCurrentLevel(root->left, level - 1);
            printCurrentLevel(root->right, level - 1);
        }
    }
    int height(BST *node)
    {
        if (node == NULL)

            return 0;
        else
        {
            int lheight = height(node->left);
            int rheight = height(node->right);

            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }
};
int main()
{
    BST b;
    BST *root = NULL;
    int rootelement;
    cout << "Insert the root : ";
    cin >> rootelement;
    root = b.insert(root, rootelement);
    int choice;
    do
    {
        cout << "1. insert an Element" << endl;
        cout << "2. Delete an Element " << endl;
        cout << "3. Search for Element x and replace value y to its appropriate position "<<endl;
        cout<< "4. Display the Elements in preorder, inorder and postorder transversal "<<endl;
        cout<< "5. Display the elements of BST in level-by-level transversal "<<endl;
        cout<< "6. Display the Height of BST" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter the element :";
            cin >> x;
            b.insert(root, x);
            break;
        case 2:
            int delelement;
            cout << "Enter the element to delete";
            cin >> delelement;
            root = b.deleteNode(root, delelement);
            cout << "Element deleted : " << endl;
            break;
        case 3:
            int del, ins;
            cout << "Enter the element to replace : ";

            cin >> del;
            cout << "Enter the element to isnert : ";
            cin >> ins;
            root = b.deleteNode(root, del);
            b.insert(root, ins);
            cout << "Element inserted" << endl;
        case 4:
            cout << "\nInorder is :" << endl;
            b.inorder(root);
            cout << "\nPreorder is :" << endl;
            b.preorder(root);
            cout << "\nPostorder is : " << endl;
            b.postorder(root);
            cout << endl;
            break;
        case 5:
            b.printLevelOrder(root);
            break;
        case 6:
            int ans = b.height(root) - 1;
            cout << ans << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
