#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct btree {
    int data;
    struct btree *left;
    struct btree *right;
};

enum Rotation {
    kLeftRotation,
    kRightRotation,
    kLeftRightRotation,
    kRightLeftRotation,
    kError = -1
};

class binarytree {
    private:
        btree *root;

        btree* createNode(int data) {
            btree *node = new btree();
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            return node;
        }

        btree* createNonBST()
        {
            btree* node = createNode(50);
            node->left = createNode(30);
            node->right = createNode(70);
            node->left->left = createNode(20);
            node->left->right = createNode(40);
            node->right->left = createNode(66);
            node->right->right = createNode(81);
            return node;
        }

        btree* insert_rec(btree *node, int data) {
            if (node == NULL) {
                return createNode(data);
            }

            if (data < node->data) {
                node->left = insert_rec(node->left, data);
            } else { 
                node->right = insert_rec(node->right, data);
            }
            return node;
        }

        void insert(btree **root, int data) {
            btree *node = *root;

            *root = insert_rec(node, data);
        }

        void printTree_rec(btree* node) {
            if (node == NULL) {
                return;
            }
            printTree_rec(node->left);
            cout<<node->data<<endl;
            printTree_rec(node->right);
        }

        int height_rec(btree* node) {
            if (node == NULL) {
                return 0;
            }

            int lheight = height_rec(node->left) + 1;
            int rheight = height_rec(node->right) + 1;
            
            if (lheight > rheight) {
                return lheight;
            }
            else {
                return rheight;
            }
        }

        int minValue_rec(btree* node) {
            if (node->left == NULL) {
                return node->data;
            }

            return minValue_rec(node->left);
        }

        bool hasPathSum_rec(btree *node, int sum) {
            if (node == NULL) {
                if (sum == 0) {
                    return true;
                }
                return false;
            }
            sum = sum - node->data;
            return ( hasPathSum_rec(node->left, sum) || hasPathSum_rec(node->right, sum));
        }

        void printPaths_rec(btree* node, int path[], int pathlen) {
            if (node == NULL) {
                return;
            }

            path[pathlen++] = node->data;

            if (node->left == NULL && node->right == NULL) {
                for (int i = 0; i < pathlen; i++) {
                    cout<<path[i]<<" ";
                }
                cout<<endl;
            } else {
                printPaths_rec(node->left, path, pathlen);
                printPaths_rec(node->right, path, pathlen);
            }
        }

        void mirror_rec(btree* node) {
            if (node == NULL) {
                return;
            }

            mirror_rec(node->left);
            mirror_rec(node->right);
            btree* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }

        bool sameTree_rec(btree* tree1, btree* tree2) {
            if (tree1 == NULL && tree2 == NULL) {
                return true;
            } else if (tree1 == NULL) {
                return false;
            } else if (tree2 == NULL) {
                return false;
            }

            if (tree1->data != tree2->data) {
                return false;
            }

            return sameTree_rec(tree1->left, tree2->left) && sameTree_rec(tree1->right, tree2->right);
        }

        void createBalancedTree(btree** root, int a[], int low, int high) {
            if (low < high) {
                int mid = (high + low) / 2;
                insert(root, a[mid]);
                createBalancedTree(root, a, low, mid);
                createBalancedTree(root, a, mid + 1, high);
            }
        }

        bool isBST_rec(btree* root) {

            if (root == NULL) {
                return true;
            }

            if (root->left != NULL && root->right != NULL) {
                if ((root->left->data > root->data) || (root->right->data < root->data)) {
                    return false;
                } else if (root->left != NULL) {
                    if (root->left->data > root->data) {
                        return false;
                    }
                } else if (root->right != NULL) {
                    if (root->right->data < root->data) {
                        return false;
                    }
                }
            }
            
            if (isBST_rec(root->left) && isBST_rec(root->right)) {
                return true;
            } else {
                return false;
            }
        }

        bool checkLeftTree(btree* root, int data)
        {
            if (root == NULL) {
                return true;
            }

            if (root->left != NULL) {
                if (root->left->data > data) {
                    return false;
                }
            }

            if (root->right != NULL) {
                if (root->right->data > data) {
                    return false;
                }
            }

            if (checkLeftTree(root->left, data) && checkLeftTree(root->right, data)) {
                return true;
            }

            return false;
        }

        bool checkRightTree(btree* root, int data)
        {
            if (root == NULL) {
                return true;
            }

            if (root->left != NULL) {
                if (root->left->data < data) {
                    return false;
                }
            }

            if (root->right != NULL) {
                if (root->right->data < data) {
                    return false;
                }
            }

            if (checkRightTree(root->left, data) && checkRightTree(root->right, data)) {
                return true;
            }

            return false;
        }

        bool isBST_rec2(btree* root, int data)
        {
            if (root == NULL) {
                return true;
            }

            if (checkLeftTree(root->left, data) && checkRightTree(root->right, data)) {
                return true;
            }

            return false;
        }

        btree* commonAncestor_rec(btree *root, btree *node1, btree *node2) {

            // First verify if two nodes can be found in the left subtree
            if (root == NULL) {
                return NULL;
            }

            if (root == node1 || root == node2)
                return root;

            bool in_left_node1 = findnodessubtree(root->left, node1); 
            bool in_left_node2 = findnodessubtree(root->left, node2); 

            if (in_left_node1 != in_left_node2) {
                return root;
            }

            return commonAncestor_rec(in_left_node1 ? root->left:root->right, node1, node2); 
        }

        bool findnodessubtree(btree *root, btree* node ) {
            if (root == NULL) {
                return false;
            }

            if (root == node) {
                return true;
            }

            bool found = false;
            found = findnodessubtree(root->left, node) || findnodessubtree(root->right, node);

            return found;
        }

        btree* convertTreetoLinkedList_rec(btree* node) {
            if (node == NULL) {
                return NULL;
            }

            if (node->left != NULL) {
                btree* left = convertTreetoLinkedList_rec(node->left);

                // Look for inorder predecessor which is the right most node of the left tree
                for (;left->right != NULL; left = left->right);

                left->right = node;
                node->left = left;
            }

            if (node->right != NULL) {
                btree* right = convertTreetoLinkedList_rec(node->right);

                // Look for inorder successor- which is the left mode node of the right subtree
                for (;right->left != NULL; right = right->left);

                node->right = right;
                right->left = node;
            }

            return node;
        }

        bool avlBalanced_rec(btree* node, btree** unode) {
            if (node == NULL) {
                return true;
            }

            bool lres = avlBalanced_rec(node->left, unode);
            if (!lres) {
                cout<<"AVL returned false while processing left"<<node->left->data<<endl;
                *unode = node->left;
                return lres;
            }
            bool rres = avlBalanced_rec(node->right, unode);
            if (!rres) {
                cout<<"AVL returned false while processing right "<<node->right->data<<endl;
                *unode = node->right;
                return rres;
            }

            int hl = height_avl(node->left);
            int hr = height_avl(node->right);

            if (abs( hl - hr) > 1) {
                return false;
            } else {
                return true;
            }
        }

        int height_avl(btree* node) {
            if (node == NULL) {
                return 0;
            }

            int lh = height_avl(node->left);
            int rh = height_avl(node->right);

            if (lh > rh) {
                return lh + 1;
            } else {
                return rh + 1;
            }
        }

        btree* avlRotate(btree *node, Rotation rot) {
                    btree *temp = NULL;
            switch(rot) {
                case kLeftRotation:
                    node->right->left = node;
                    temp = node->right;
                    node->right = NULL;
                    return temp;

                case kRightRotation:
                    node->left->right = node;
                    temp = node->left;
                    node->left = NULL;
                    return temp;
                    break;

                case kLeftRightRotation:
                    node->left->right->left = node->left;
                    node->left = node->left->right;
                    node->left->left->right = NULL;
                    return node;
                    break;

                case kRightLeftRotation:
                    node->right->left->right = node->right;
                    node->right = node->right->left;
                    node->right->right->left = NULL;
                    return node;
                    break;

                default:
                    break;
            }
            return NULL;
        }

#if 0
        int getRank_rec(btree* node, int x) {
            if (node == NULL) {
                return 0;
            }

            if (x > node->data) {
                cnt = getRank_rec(node->left) + 1;
            } else

        void addLevelToLinkedList_rec(btree* node, vector<list<int> > *lists, int level) const{
            if (node == NULL) {
                return;
            }

            if (lists->size() != level + 1) {
                list<int> llist;
                llist.push_back(node->data);
                lists->push_back(llist);
            } else {
                lists[level].push_back(node->data);
            }

            addLevelToLinkedList_rec(node->left, lists, level + 1);
            addLevelToLinkedList_rec(node->right, lists, level + 1);
        }
#endif
    public:
        binarytree() {
            root = NULL;
        }

        void insert(int data) {
            btree *node = root;
            btree *unode = NULL; 
            root = insert_rec(node, data);
            if (!avlBalanced_rec(root, &unode)) {
                cout<<"Tree lost its balance while inserting "<<data<<endl;
                Rotation rot = findRotation(unode);
                if (rot == 2) {
                    unode = avlRotate(unode, rot);
                    unode = avlRotate(unode, kRightRotation);
                } else if (rot == 0 || rot == 1) {
                    unode = avlRotate(unode, rot);
                }

                cout<<"Rotation required is:"<<rot<<endl;
                if (!avlBalanced_rec(root, &unode)) {
                    cout<<"Tree is still not balanced "<<data<<endl;
                } else {
                    cout<<"Tree is AVL balanced now"<<endl;
                }
            }
        }

        void printTree() {
            btree *node = root;
            printTree_rec(node);
        }

        void height() {
            btree *node = root;
            int h = height_rec(node);

            cout<<"Height tree"<<h<<endl;
        }

        void isBalanced() {
            btree *node = root;
            int lheight = height_rec(node->left);
            int rheight = height_rec(node->right);
            int diff = abs(lheight - rheight);

            if (diff > 1) {
                cout<<"Not balanced tree:"<<diff<<endl;
            } else {
                cout<<"Balanced tree:"<<diff<<endl;
            }
        }

        void minValue() {
            btree *node = root;

            cout<<"Min value is:"<<minValue_rec(node)<<endl;
        }

        void hasPathSum(int sum) {
            btree* node = root;
            if (hasPathSum_rec(node, sum)) {
                cout<<"Has path"<<endl;
            } else {
                cout<<"Does not have path"<<endl;
            }
        }

        void printPaths() {
            btree* node = root;
            int path[10];
            int pathlen = 0;
            printPaths_rec(node, path, pathlen);
        }

        void mirror() {
            btree* node = root;
            mirror_rec(node);
        }

        void sameTree() {
            btree* tree1 = root;
            printTree();
            insert(36);
            cout<<"After insertion"<<endl;
            printTree();
            btree* tree2 = root;
            if (sameTree_rec(tree1, tree2)) {
                cout<<"Identical tree"<<endl;
            } else {
                cout<<"Not identical trees"<<endl;
            }
        }

        void createTreeWithMinimalHeight()
        {
            int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            btree *node = NULL;
            createBalancedTree(&node, a, 0, 9);
            cout<<"New tree"<<endl;
            printTree_rec(node);
            int h = height_rec(node);
            cout<<"Height tree"<<h<<endl;
        }

        void isBinarySearchTree()
        {
            btree* node = root;
            if (isBST_rec(node)) {
                cout<<"Binary search tree"<<endl;
            } else {
                cout<<"Not BST tree"<<endl;
            }
        }

        void isBinarySearchTree2()
        {
            btree* node = createNonBST();
            if (isBST_rec2(node, node->data)) {
                cout<<"Binary search tree"<<endl;
            } else {
                cout<<"Not BST tree"<<endl;
            }
        }

        void commonAncestor()
        {
            btree *mroot = root;
            btree *node1 = root->left->left;
            btree *node2 = root->left->left->right;

            btree* res = commonAncestor_rec(root, node1, node2);
            cout<<"Common Ancestor node is:"<<res->data<<endl;
        }

        void convertTreetoLinkedList() {
            btree* node = root;

            btree* list = convertTreetoLinkedList_rec(root);
            while (list->left != NULL) {
                list = list->left;

            }
            while(list) {
                cout<<list->data<<endl;
                list = list->right;
            }
        }

        //http://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm
        void avlBalanced() {
            btree *node = root;
            btree *unode = NULL;
            bool res = avlBalanced_rec(root, &unode);
            if (!res) {
                cout<<"Not an AVL tree"<<endl;
            } else {
                cout<<"It is an AVL tree"<<endl;
            }
        }

        Rotation findRotation(btree *node) {
            if (node == NULL) {
                return kError;
            }

            // Can either be a right rotation or left right rotation
            if (node->left != NULL) {
                node = node->left;

                if (node->left != NULL) {
                    return kLeftRotation;
                }
                else {
                    return kLeftRightRotation;
                }
            }

            // Can either be a left rotation or right left rotation
            if (node->right != NULL) {
                node = node->right;

                if (node->right != NULL) {
                    return kRightRotation;
                }
                else {
                    return kRightLeftRotation;
                }
            }
            return kError;
        }

#if 0
        int getRank(int x) {
            btree* node = root;
            return getRank_rec(node, x);
        }
#endif
};

int main()
{
    binarytree tree;
    tree.insert(10);
    tree.insert(7);
    tree.insert(14);
    tree.insert(5);
    tree.insert(6);
    tree.insert(13);
    tree.insert(20);
    tree.insert(25);
    //tree.height();
    //tree.isBalanced();
    //tree.minValue();
    //tree.hasPathSum(44);
    //tree.printPaths();
    //tree.printTree();
    //tree.mirror();
    //cout<<"After mirror"<<endl;
    //tree.printTree();
    //tree.sameTree();
    //tree.createTreeWithMinimalHeight();
    tree.isBinarySearchTree2();
    tree.isBinarySearchTree();
    //tree.commonAncestor();
    //tree.convertTreetoLinkedList();
//    tree.avlBalanced();
//    tree.getRank(20);
}
