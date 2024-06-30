#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
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
    q.push(root);
    q.push(NULL);
    vector<int> sum;
    while(!que.empty())
    {
        node* curr = que.front();
        que.pop();
        if(node != NULL)
        {
            
        }
    }
}

int main()
{
    struct node* root = new node(5);
    root->left = new node(8);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->left->left->left = new node(4);
    root->left->left->left->right = new node(6);
    root->right = new node(9);
    root->right->left = new node(3);
    root->right->right = new node(7);
    levelorder(root);
    
    return 0;
}