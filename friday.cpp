#include<iostream>
using namespace std;
struct node{
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

    if(root->left!=NULL)
    {
        root->val += root->left->val;
    }
    if(root->right!=NULL)
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

int height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return max(height(root->left),height(root->right)) + 1;
}
bool isbalance(node* root)
{
    if(root==NULL)
    {
        return true;
    }

    if(isbalance(root->left)==false)
    {
        return false;
    }
    if(isbalance(root->right)==false)
    {
        return false;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    if(abs(lheight-rheight) <= 1)
    {
        return true;
    }
    else{
        return false;
    }
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
    // sumreplacement(root);
    // preorder(root);
    cout<<isbalance(root);
    return 0;
}