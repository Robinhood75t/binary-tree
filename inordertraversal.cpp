#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(node* root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->right->left = new node(7);
    preorder(root);
    return 0;
}