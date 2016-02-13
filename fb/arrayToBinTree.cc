#include<iostream>

using namespace std;

struct tree
{
    struct tree *left;
    struct tree *right;
    int data;
};

struct tree* createTree(int arr[],int start, int end);
void addNode(int data,tree **root);
void
inorder(tree *root);
struct tree* newNode(int data);

int main()
{
    int arr[] = {1,2,3,4,5,6};

    tree *root = createTree(arr,0,5);
    inorder(root);

}

void createTree(int arr[],int start, int end)
{
    if(start > end)
    {
        return ;
    }
        int mid = (end + start)/2;
        //addNode(arr[mid],root);
        struct tree *node = newNode(arr[mid]);
        node->left = createTree(arr,start,mid - 1 );
        node->right = createTree(arr,mid + 1, end);
        return node;
}

struct tree* newNode(int data)
{

    tree *node = new tree();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void addNode(int data,tree **root)
{
    tree *node = new tree();
    node->data = data;

    if((*root) == NULL)
    {
        (*root) = node;
        node->left = NULL;
        node->right = NULL;
    }
    else
    {
        tree *temp = (*root);
        while(temp)
        {
            if(data > temp->data)
            {
                if(temp->right == NULL)
                {
                    temp->right = new tree();
                    temp->right->data = data;
                    temp->right->right = NULL;
                    temp->right->left = NULL;
                    break;
                }
                temp = temp->right;
            }
            else
            {
                if(temp->left == NULL)
                {
                    temp->left = new tree();
                    temp->left->data = data;
                    temp->left->right = NULL;
                    temp->left->left = NULL;
                    break;
                }
                temp = temp->left;
            }
        }
    }
}

void
inorder(tree *root)
{
    /* visit left 
     * visit root
     * visit right
     */
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
