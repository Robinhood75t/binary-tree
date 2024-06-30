#include<iostream>
#include<queue>
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
void levelorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }

    queue<node*> que;
    que.push(root);
    que.push(NULL);

    while(!que.empty())
    {
        node* curr = que.front();
        que.pop();
        if(curr != NULL)
        {
            cout<<curr->val<<" ";
            if(curr->left)
            {
                que.push(curr->left);
            }
            if(curr->right)
            {
                que.push(curr->right);
            }
        }
        if(!que.empty())
        {
            que.push(NULL);
        }
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
    levelorder(root);
    return 0;
}