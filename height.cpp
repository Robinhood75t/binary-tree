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
int calculateheight(node* root)
{
    if(root== NULL)
    {
        return 0;
    }
    int lheight = calculateheight(root->left);
    int rheight = calculateheight(root->right);

    return max(lheight,rheight)+1;
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
    cout<<calculateheight(root);
    return 0;
}