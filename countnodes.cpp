#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
void countnodes(TreeNode* root)
{
    if(root == NULL)
        {
            return ;
        }
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        int count = 0;
        while(!que.empty())
        {
            TreeNode* curr = que.front();
            que.pop();
            count++;
            if(root!=NULL)
            {
                if(root->left)
                {
                    que.push(root->left);
                }
                if(root->right)
                {
                    que.push(root->right);
                }
            }
            else if(!que.empty())
            {
                que.push(NULL);
            }
        }
        cout<<count<<" ";
}
int main()
{
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    countnodes(root);
    return 0;
}