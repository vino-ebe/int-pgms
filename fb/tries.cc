#include<iostream>

using namespace std;
class Tries;

struct node
{
    bool is_end;
    int prefix_count;
    struct node* child[26];
};


class Tries
{
    private:
        node *head;

    public:
        Tries()
        {
            head = newNode();
        }

        node* newNode()
        {
            node *n = new node();
            n->is_end = false;
            n->prefix_count = 0;
            for(int i = 0; i < 26;i++)
                n->child[i] = NULL;

            return n;
        }

        void insert(string word)
        {
            node *current = head;
            current->prefix_count++;
            int ch;

            for(int i = 0;i < word.size(); i++)
            {
                ch = (int)word[i] - (int)'a';
                
                if (current->child[ch] == NULL)
                    current->child[ch] = newNode();

                current->child[ch]->prefix_count++;
                current = current->child[ch];
            }

            current->is_end = true;
        }

        bool search(string word)
        {
            node *current = head;
            int ch;

            for (int i = 0; i < word.size(); i++)
            {
                ch = (int)word[i] - (int)'a';

                if(current->child[ch] == NULL)
                {
                    return false;
                }
                else
                {
                    current = current->child[ch];
                }
            }

            return current->is_end;
        }

};

int main()
{
    Tries t;

    t.insert("vinoj");
    t.insert("vinco");

    if(t.search("vincol"))
        cout<<"Word exist"<<endl;
    else
        cout<<"Word did not exist"<<endl;
}
