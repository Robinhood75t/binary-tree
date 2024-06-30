#include<iostream>
#include<vector>
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
void morrispreorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    vector<int> result;
    node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            result.push_back(curr->val);
            curr = curr->right;
        }
        else{
            node* leftchild = curr->left;
            while(leftchild->right != NULL && leftchild->right != curr)
            {
                leftchild = leftchild->right;
            }
            if(leftchild->right == NULL)
            {
                result.push_back(curr->val);
                leftchild->right = curr;
                curr = curr->left;
            }
            else
            {
                leftchild->right = NULL;
                curr = curr->right;
            }
        }
    }
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}
void morrisinorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    vector<int> result;
    node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            result.push_back(curr->val);
            curr = curr->right;
        }
        else 
        {
            node* leftchild = curr->left;
            while(leftchild->right != NULL && leftchild->right != curr)
            {
                leftchild = leftchild->right;
            }
            if(leftchild->right == NULL)
            {
                leftchild->right = curr;
                curr = curr->left;
            }
            else{
                result.push_back(curr->val);
                leftchild->right = NULL;
                curr = curr->right;
            }
        }
    }
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
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
    //morrisinorder(root);
    morrispreorder(root);
    return 0;
}