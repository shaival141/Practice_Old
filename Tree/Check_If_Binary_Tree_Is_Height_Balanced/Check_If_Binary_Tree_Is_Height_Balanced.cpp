#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
};

bool isBalanced(struct node *root, int *height)
{
    int lh=0;
    int rh=0;
    bool l=false, r=false;
    if(root==NULL)
    {
        *height=0;
        return true;
    }
    l=isBalanced(root->left, &lh);
    r=isBalanced(root->right, &rh);
    *height=((lh>rh)?lh:rh)+1;
    if((lh - rh >= 2) || (rh - lh >= 2))
        return false;
    return l&&r;
}

int main()
{
    int height = 0;
    struct node *root = newNode(1);  
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);
    
    if(isBalanced(root, &height))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    return 0;
}