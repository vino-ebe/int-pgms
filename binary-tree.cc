#include<iostream>
#include<stack>
using namespace std;

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

class bsearchtree
{
    private:
        node *root;
        node* newNode(int data);
        node* createMinBST(int arr[],int start,int end);
    public:
        bsearchtree();
        void addNode(int data);
        void deleteNode(int data);
        node* search(int data);
        void balanced();
        void printTree();
        void rprintTree(node* root);
        void createBST();
        void size(node *root);
};

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
#if 1
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
#endif
#if 0
   node *cur = root;

   while(cur != NULL)
   {
       if(data > cur->data)
       {
           cur = cur->right;
       }
       else
       {
           cur = cur->left;
       }
   }

   cur = newNode(data);
#endif
}

node* bsearchtree::createMinBST(int arr[], int start, int end)
{
    if(end < start)
        return NULL;

    int mid = (start + end)/2;

    node* root = newNode(arr[mid]);

    root->left = createMinBST(arr,start,mid-1);
    root->right = createMinBST(arr,mid+1,end);
    return root;

}

/* Pre order traversal 
 * print root
 * traverse left
 * traverse right
 */

void bsearchtree::printTree()
{
    stack<node*> s;
    node *temp = root;
    //rprintTree(temp);
    s.push(temp);

    while(s.empty() != true)
    {
        node *t = s.top();
        if(t)
        {
            cout<<s.top()->data<<endl;
            s.pop();
        }
        else
        {
            cout<<"Empty stack"<<endl;
            return;
        }
      
        if(t->right)
            s.push(t->right);

        if(t->left)
            s.push(t->left);
    }
}

void bsearchtree::rprintTree(node *head)
{
    if(head == NULL)
        return;

    cout<<head->data<<endl;
    rprintTree(head->left);
    rprintTree(head->right);

}

void bsearchtree::balanced()
{
    stack<node*> s;
    bool rightPresent = false, leftPresent = false;
    node *temp = root;
    s.push(temp);

    while(s.empty() != true)
    {
        rightPresent = false;
        leftPresent = false;

        node *t = s.top();
        if(t)
        {
            cout<<s.top()->data<<endl;
            s.pop();
        }
        else
        {
            cout<<"Empty stack"<<endl;
            return;
        }
      
        if(t->right) 
        {
            rightPresent = true;
            s.push(t->right);
        }

        if(t->left) 
        {
            leftPresent = true;
            s.push(t->left);
        }

        if(t->right || t->left)
        {
            if(!t->right)
            {
                cout<<"Tree is not Balanced"<<endl;
                break;
            }
            if(!t->left)
            {
                cout<<"Tree is not Balanced"<<endl;
                break;
            }
        }
            
    }
}

void bsearchtree::createBST()
{
    int arr[] = {1,2,3,4,5,6};
    root = createMinBST(arr,0,5);
    printTree();
}

void bsearchtree::size(node* root)
{
    /*
    if(root == NULL)
        return;
    return size(root->left) + 1 + size(root->right) + 1;
    */
}

int main()
{

    bsearchtree tree;
    tree.addNode(5);
    tree.addNode(3);
    tree.addNode(10);
    tree.addNode(15);
//    tree.balanced();
    tree.printTree();

//    bsearchtree bsttree;
  //  bsttree.createBST();

}
