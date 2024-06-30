#include<iostream>
#include<vector>
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
void moristraversal(node* root)
{
    vector<int> ans;
    node* curr = root;
    while(curr!=NULL)
    {
        if(curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            node* leftchild = curr->left;
            while(leftchild->right!= NULL && leftchild->right != curr)
            {
                leftchild = leftchild->right;
            }
            if(leftchild->right == NULL)
            {
                
                leftchild->right = curr;
                curr = curr->left;
            }
            else{
                ans.push_back(curr->val);
                leftchild->right = NULL;
                curr = curr->right;
            }
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    moristraversal(root);
    return 0;
}