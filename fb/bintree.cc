#include<iostream>
#include<stack>

using namespace std;

struct tree
{
    struct tree *left;
    struct tree *right;
    int data;
};

enum TraverseType
{
    kPreOrder = 100,
    kPostOrder,
    kInOrder,
    kLevelOrder
};

void printGivenLevel(tree *root, int h);

bool m_isBST(tree *root);

class binTree
{
    private:
    tree *root;
    void preorder(tree*);
    void postorder(tree*);
    void inorder(tree*);
    void levelorder(tree*);
    int mHeight(tree*);
    bool pathSum(tree*,int sum);
    tree* invert(tree*);
    void kthsmallest(tree*,int);

    public:
    binTree()
    {
        root = NULL;
    }

    bool isBST();
    void addNode(int data)
    {
        tree *node = new tree();
        node->data = data;

        if(root == NULL)
        {
            root = node;
            node->left = NULL;
            node->right = NULL;
        }
        else
        {
            tree *temp = root;
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

    void traverseTree(TraverseType type)
    {
        if (type == kPreOrder)
        {
            preorder(root);
        }
        else if (type == kPostOrder)
        {
            postorder(root);
        }
        else if (type == kInOrder)
        {
            inorder(root);
        }
        else if (type == kLevelOrder)
        {
            levelorder(root);
        }
    }

    int height()
    {
        return mHeight(root);
    }

    bool hasPathSum()
    {
        int sum = 10;
        return pathSum(root,sum);
    }

    tree* invertTree()
    {
        return invert(root);
    }

    void kSmall(int k)
    {
        kthsmallest(root,k);
    }

    int count(tree* root)
    {
        if(root == NULL)
            return 0;

        return(count(root->left) + 1 + count(root->right))
    }

};

int main()
{
    binTree t;
    t.addNode(3);
    t.addNode(2);
    t.addNode(4);
    t.addNode(1);
    t.addNode(5);

    t.traverseTree(kLevelOrder);
    if(t.isBST())
        cout<<"YES BST"<<endl;
    else
        cout<<"NO"<<endl;

    //tree *root = t.invertTree();

    t.kSmall(2);
    
}

void
binTree::preorder(tree *root)
{
    /* visit root
     * visit left
     * visit right
     */
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void
binTree::postorder(tree *root)
{
    /* visit left 
     * visit right
     * visit root
     */
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<endl;
}

void
binTree::inorder(tree *root)
{
    /* visit left 
     * visit root
     * visit right
     */
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    cout<<root->data<<endl;
    preorder(root->right);
}

void
binTree::levelorder(tree *root)
{
    int h = height();

    for(int i = 1; i <= h; i++) 
        printGivenLevel(root,i);
}

int
binTree::mHeight(tree *root)
{
    int lh = 0;
    int rh = 0;

    if(root == NULL)
        return 0;
    else
    {
        lh += mHeight(root->left) + 1;

        rh += mHeight(root->right) + 1;
    }
    return (lh > rh ? lh : rh);
}

void printGivenLevel(tree *root, int h)
{
    if(root == NULL)
        return;

    if(h == 1)
    {
        cout<<root->data<<endl;
        return;
    }
    else
    {
        printGivenLevel(root->left,(h - 1));
        printGivenLevel(root->right,(h - 1));
    }
}

bool
binTree::isBST()
{
    return(m_isBST(root));
}

bool m_isBST(tree *root)
{
    if(root->left != NULL && root->right != NULL)
    {

        if(root->data < root->left->data)
        {
            return false;
        }

        if(root->data > root->right->data)
        {
            return false;
        }

        m_isBST(root->left);
        m_isBST(root->right);
        return true;
    }
}

bool
binTree::pathSum(tree *root,int sum)
{
    if(root == NULL)
    {
        if(sum == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
         int subsum =  sum - root->data;
         return(pathSum(root->left,subsum) || pathSum(root->right,subsum));
    }

}

tree*
binTree::invert(tree *root)
{
    if(root == NULL)
        return NULL;

    tree *left = root->left;
    tree *right = root->right;

    tree *newRoot = invert(root->left);

    if(left)
    {
        left->left = right;
        left->right = root;
    }

    root->left = NULL;
    root->right = NULL;

    if(newRoot)
        return newRoot;
    else
        return root;

}

void
binTree::kthsmallest(tree *root,int k)
{
    stack<tree*> list;
    tree *cur = root;

    while(!list.empty() || cur != NULL)
    {
        if(cur != NULL)
        {
            list.push(cur);
            cur = cur->left;
        }
        else
        {
            tree *temp = list.top();
            list.pop();

            k--;
            if(k == 0)
                cout<<"kth smallest item"<<temp->data<<endl;

            cur = temp->right;
        }
    }
}
