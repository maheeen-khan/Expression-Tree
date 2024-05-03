//Postfix expression to Tree
//Traversal after creating Tree

#include <iostream>
#include <conio.h>
 
using namespace std;
 
struct node{
        char data;
        node *left;
        node *right;
};

int top = -1;
node *arr[35];
 
int check_input(char inputchar){ //for checking symbol is operand or operator
    if (inputchar == '+' || inputchar == '-' || inputchar == '*' || inputchar
            == '/')
        return (-1);
    else if (inputchar >= 'a' || inputchar <= 'z')
        return (1);
    else if (inputchar >= 'A' || inputchar <= 'Z')
        return (1);
    else
        return (-99); //for error
}
 
//it is used for inseting an single element in//a tree, i.e. is pushing of single element.
void push(node *tree)
{
    top++;
    arr[top] = tree;
}
 
node *pop()
{
    top--;
    return (arr[top + 1]);
}
 
void create_expr_tree(char *suffix){
	
    char symbol;
    node *newl, *ptr1, *ptr2;
    int flag; //flag=-1 when operator and flag=1 when operand
    symbol = suffix[0]; //Read the first symbol from the postfix expr.
    
    for (int i = 1; symbol != NULL; i++){ //continue till end of the expr.
        flag = check_input(symbol); //check symbol is operand or operator.
        if (flag == 1)//if symbol is operand.
        {
            newl = new node;
            newl->data = symbol;
            newl->left = NULL;
            newl->right = NULL;
            push(newl);
        }
        else
        { //If the symbol is operator//pop two top elements.
            ptr1 = pop();
            ptr2 = pop();
            newl = new node;
            newl->data = symbol;
            newl->left = ptr2;
            newl->right = ptr1;
            push(newl);
        }
        symbol = suffix[i];
    }
}
 
void preOrder(node *tree)
{
    if (tree != NULL)
    {
        cout << tree->data;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
 
void inOrder(node *tree){
    if (tree != NULL){
        inOrder(tree->left);
        cout << tree->data;
        inOrder(tree->right);
    }
}
 
void postOrder(node *tree){
    if (tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data;
    }
}
 
int main(){
	
	char postfix[35];
	
	cout<<"Postfix expression to Tree\n";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "Enter Postfix Expression : ";
    cin >> postfix;
 	
    //Creation of Expression Tree
    create_expr_tree(postfix);
 
    //Traversal Operation on expression tree
    cout << "\n\nIn-Order Traversal :   ";
    inOrder(arr[0]);
 
    cout << "\n\nPre-Order Traversal :  ";
    preOrder(arr[0]);
 
    cout << "\n\nPost-Order Traversal : ";
    postOrder(arr[0]);
    
    cout<<"\n\n";
    return 0;
}
