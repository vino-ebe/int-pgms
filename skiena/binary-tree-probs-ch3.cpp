#include<iostream>
#include<stack>

using namespace std;

typedef struct btree
{
    int data;
    struct btree *lchild;
    struct btree *rchild;
}Btree;

class binarytree
{
    private:
        Btree *root;

        Btree* newNode(int data)
        {
            Btree *node = new Btree();
            node->lchild = NULL;
            node->rchild = NULL;
            node->data = data;
            return node;
        }

    public:
        binarytree()
        {
            root = NULL;
        }

        void insert(int data)
        {
            Btree *node = newNode(data);

            if ( root == NULL)
            {
                root = node;
            }
            else
            {
                Btree *current = root;

                while (1)
                {
                    if (data < current->data)
                    {
                        if (current->lchild)
                        {
                            current = current->lchild;
                        }
                        else
                        {
                            current->lchild = node;
                            break;
                        }
                    }
                    else if (data > current->data)
                    {
                        if (current->rchild)
                        {
                            current = current->rchild;
                        }
                        else
                        {
                            current->rchild = node;
                            break;
                        }
                    }
                }
            }
        }

        void printTree()
        {
            Btree *current = root;
            stack<Btree*> st;
            while (1)
            {
                if (current != NULL)
                {
                    st.push(current);
                    current = current->lchild;
                }
                else
                {

                    if (!st.empty())
                    {
                        current = st.top();
                        st.pop();
                        cout<<current->data<<endl;
                        current = current->rchild;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        bool compareTrees(Btree *t1, Btree *t2)
        {
            bool ret = false, ret1 = false, ret2 = false;

            if ((t1 == NULL) && (t2 == NULL))
                    return true;

            if ((t1 != NULL) && (t2 != NULL))
            {
                /*
                    cout<<"t1 and t2:"<<t1->data<<":"<<t2->data<<endl;
                return ((t1->data == t2->data) &&
                    compareTrees(t1->lchild, t2->lchild) &&
                    compareTrees(t1->rchild, t2->rchild));
                    
                    */
                if (t1->data != t2->data)
                    ret = false;
                else 
                    ret = true;
                //ret = (t1->data == t2->data);
                ret1 =  compareTrees( t1->lchild, t2->lchild);
                ret2 = compareTrees( t1->rchild, t2->rchild);

                {
                    cout<<"t1 and t2:"<<t1->data<<":"<<t2->data<<endl;
                }

                return (ret && ret1 && ret2);
                
            }
            else
            {
                return false;
            }

        }

        Btree* deleteNode(int data, Btree *root)
        {
            if ( root == NULL)
                return root;

            if (data < root->data)
            {
                root->lchild = deleteNode(data, root->lchild);
            }
            else if (data > root->data)
            {
                root->rchild = deleteNode(data, root->rchild);
            }
            else
            {
                if (root->lchild == NULL) 
                {
                    Btree *temp = root->rchild;
                    return temp;
                }

                else if (root->rchild == NULL) 
                {
                    Btree *temp = root->lchild;
                    return temp;
                }

                Btree *temp = root->rchild;

                while (temp->lchild)
                {
                    temp = temp->lchild;
                }

                root->data = temp->data;

                root->rchild = deleteNode(temp->data, root->rchild);

            }
            return root;
        }

        Btree* getRoot()
        {
            return root;
        }
};

int main()
{
    binarytree tree;
    tree.insert(7);
    tree.insert(5);
    tree.insert(2);
    tree.insert(6);
    tree.insert(10);
    tree.insert(9);
    tree.insert(12);

    binarytree tree2;
    tree2.insert(2);
    tree2.insert(1);
    tree2.insert(3);
    tree2.insert(4);

    //tree.printTree();
//    if (tree.compareTrees(tree.getRoot(), tree2.getRoot()))
 //       cout<<"Tree is same"<<endl;
  //  else
  //      cout<<"Tree is different"<<endl;
    tree2.deleteNode(2, tree2.getRoot()); 
    tree2.printTree();
}
