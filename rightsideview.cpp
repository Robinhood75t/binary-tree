#include<iostream>
#include<vector>
#include<queue>
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
void rightview(node* root)
{
    vector<int> ans;
    queue<node*> que;
    que.push(root);
    que.push(NULL);
    while(!que.empty())
        {
            node* curr = que.front();
            ans.push_back(root->val);
            que.pop();
            if(curr!=NULL)
            {
                if(curr->left)
                {
                    que.push(curr->left);
                }
                if(curr->right)
                {
                    que.push(curr->right);
                    ans.push_back(curr->right->val);
                }
            }
            else if(!que.empty())
            {
                que.push(NULL);
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
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->left = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    rightview(root);
    return 0;
}