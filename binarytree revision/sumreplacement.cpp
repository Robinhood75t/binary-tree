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
void sumreplacement(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    sumreplacement(root->left);
    sumreplacement(root->right);
    if(root->left != NULL)
    {
        root->val += root->left->val;
    }
    if(root->right != NULL)
    {
        root->val += root->right->val;
    }
}
void preorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
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
    sumreplacement(root);
    preorder(root);
    return 0;
}