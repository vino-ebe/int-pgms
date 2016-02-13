
#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

int rsize(node *root);
int rmaxDepth(node *root);

class bsearchtree
{
    private:
        node *root;
        node* newNode(int data);
        node* buildTree(node* root,int data);
    public:
        bsearchtree();
        void addNode(int data);
        int size();
        int maxDepth();
        int minValue();
};

int main()
{
    bsearchtree tree;
    tree.addNode(5);
    tree.addNode(3);
    tree.addNode(10);
    tree.addNode(15);

    cout<<"Size"<<tree.size()<<endl;
    cout<<"Depth"<<tree.maxDepth()<<endl;
    cout<<"Min value"<<tree.minValue()<<endl;
}

bsearchtree::bsearchtree()
{
    root = NULL;
}

node* bsearchtree::newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void bsearchtree::addNode(int data)
{
   node *temp = newNode(data);
   node *cur = root;
   if(cur == NULL)
   {
       root = temp;
   }
   else
   {
        if(data > cur->data)
        {
            while(cur->right != NULL)
                cur = cur->right;
            
            cur->right = temp;
        }
        else
        {
            while(cur->left != NULL)
                cur = cur->left;

            cur->left = temp;
        } 
   } 
}

int bsearchtree::size()
{
    return rsize(root);
}

int rsize(node *root)
{
    if(root == NULL)
        return 0;
    return rsize(root->left) + 1 + rsize(root->right) ;
}

int bsearchtree::maxDepth()
{
    node *temp = root;
    return rmaxDepth(temp);
}

int rmaxDepth(node *root)
{
    int rdepth;
    int ldepth;

    if(root == NULL)
        return 0;

    rdepth = rmaxDepth(root->right);
    ldepth = rmaxDepth(root->left);

    if(ldepth > rdepth)
        return ldepth+1;
    else
        return rdepth+1;
}

int bsearchtree::minValue()
{
    node *temp = root;

    while(temp->left)
    {
        temp = temp->left;    
    }

    return temp->data;
}
