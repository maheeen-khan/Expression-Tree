//AVL Tree
//include Insertion, Searching, Deletion, Traversal operations.
#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

struct AVLTree {
    TreeNode* root;

    AVLTree() : root(NULL) {}

    bool isTreeEmpty() {
        return (root == NULL);
    }

    int height(TreeNode* r) {
        if (r == NULL)
            return -1;
        else {
            int lheight = height(r->left);
            int rheight = height(r->right);
            return (lheight > rheight) ? (lheight + 1) : (rheight + 1); //if returns true then left height + 1, otherwise right height +1
        }
    }

    int getBalanceFactor(TreeNode* n) {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        return y;
    }

    TreeNode* insert(TreeNode* r, TreeNode* new_node) {
        if (r == NULL) {
            r = new_node;
            return r;
        }
        if (new_node->value < r->value)
            r->left = insert(r->left, new_node);
        else if (new_node->value > r->value)
            r->right = insert(r->right, new_node);
        else {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }
        int bf = getBalanceFactor(r);
        
        if (bf > 1 && new_node->value < r->left->value)
            return rightRotate(r);
            
        if (bf < -1 && new_node->value > r->right->value)
            return leftRotate(r);
            
        if (bf > 1 && new_node->value > r->left->value) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        
        if (bf < -1 && new_node->value < r->right->value) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        
        return r;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* r, int v) {
        if (r == NULL)
            return NULL;
        else if (v < r->value)
            r->left = deleteNode(r->left, v);
        else if (v > r->value)
            r->right = deleteNode(r->right, v);
        else {
            if (r->left == NULL) {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            } else if (r->right == NULL) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            } else {
                TreeNode* temp = minValueNode(r->right);
                r->value = temp->value;
                r->right = deleteNode(r->right, temp->value);
            }
        }
        int bf = getBalanceFactor(r);
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
            return rightRotate(r);
        else if (bf == 2 && getBalanceFactor(r->left) == -1) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        } else if (bf == -2 && getBalanceFactor(r->right) <= -0)
            return leftRotate(r);
        else if (bf == -2 && getBalanceFactor(r->right) == 1) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }
};

  void printInorder(TreeNode * root) //  (Left, current node, Right)
  {
    if (root == NULL)
      return;
    
    printInorder(root -> left);
    cout << root -> value << " ";
    printInorder(root -> right);
  }
  
TreeNode * search(TreeNode * r, int val) {
    if (r == NULL || r -> value == val)
      return r;

    else if (val < r -> value)
      return search(r -> left, val);

    else
      return search(r -> right, val);
  }
  
int main() {
    AVLTree obj;
    int option, val, toSearch;

	cout<<"AVL Tree\n";
	cout<<"**********\n\n";
    do {
        cout << "Select 1 option : \n\n";
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Print AVL Tree values" << endl;
        cout << "4. Height of Tree" << endl;
        cout << "0. Exit Program\n\n";

        cin >> option;
        TreeNode* new_node = new TreeNode();

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "AVL INSERT" << endl;
                cout << "Enter value to insert : ";
                cin >> val;
                new_node->value = val;
                obj.root = obj.insert(obj.root, new_node);
                cout << endl;
                break;
            case 2:
                cout << "DELETE" << endl;
                cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
                cin >> val;
                obj.root = obj.deleteNode(obj.root, val);
                break;
            case 3:
                cout << "PRINT : " << endl;
                printInorder(obj.root);
                cout << endl;
                break;
            case 4:
                cout << "TREE HEIGHT : " << endl;
                cout << "Height : " << obj.height(obj.root) << endl;
                break;
         	case 5:
      			cout << "SEARCH" << endl;
     			cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
      			cin >> toSearch;
      			new_node = search(obj.root, toSearch);
      			if (new_node != NULL) {
        		cout << "Value found" << endl;
     			 } else {
        		cout << "Value NOT found" << endl;
      			}
      			break;
            default:
                cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}

