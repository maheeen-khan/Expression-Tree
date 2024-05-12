//Prefix Expression to Expression Tree

#include <iostream>
#include <stack>
#include <cstring>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

TreeNode* createNode(char data) {
	
   TreeNode* newNode =  (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* prefix_Tree(char* prefixExpression) {
	
    stack<TreeNode*> st;
    int length = strlen(prefixExpression);

    for (int i = length - 1; i >= 0; --i) {
        char c = prefixExpression[i];

        if (isOperator(c)) {
            TreeNode* newNode = createNode(c);
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
            st.push(newNode);
        }
		else {
            TreeNode* newNode = createNode(c);
            st.push(newNode);
        }
    }

    return st.top();
}

void inorderTraversal(TreeNode* root) {
    if (root!= NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
	
     char* prefixExpression = "*+//ABF-CDE";
    TreeNode* root = prefix_Tree(prefixExpression);

    cout << "\tPrefix Expression to Expression tree:";
    cout<<"\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"\n\n\tPrefix Expression : "<<prefixExpression;
    cout<<"\n\n\tExpression Tree : ";
    inorderTraversal(root);
	cout<<"\n";
	
    return 0;
}

