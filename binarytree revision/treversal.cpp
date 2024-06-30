#include<iostream>
using namespace std;
struct node{
    public:
    int val;
    struct node* left;
    struct node* right;

    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    // inorder(root);
    // preorder(root);
    postorder(root);
    return 0;
}