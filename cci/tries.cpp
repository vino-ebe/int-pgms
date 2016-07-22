#include<iostream>
#include<string>
#include<vector>

using namespace std;
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]);

struct trieNode {
    struct trieNode *children[26];
    bool isLeaf;
};
static void sortLength(string words[], int len[], int size);
bool sortfunction(int i, int j);

class tries {
    private:
        trieNode *root;

        trieNode* initializeNode(trieNode *node) {
            if (node == NULL) {
                node = new trieNode();
            }
            node->isLeaf = false;

            for (int i = 0; i < 26; i++) {
                node->children[i] = NULL;
            }
            return node;
        }

        int convertToIndex(char c) {
            return (c - 'a');
        }

    public:
        tries() {
            root = NULL;
            root = initializeNode(root);
        }

        void insert(string word) {
            trieNode *pCrawl = root;
            char curChar;
            for (int i = 0; i < word.size(); i++) {
                curChar = convertToIndex(word[i]);
                if (!pCrawl->children[curChar]) {
                    pCrawl->children[curChar] = initializeNode(pCrawl->children[curChar]);
                }

                pCrawl = pCrawl->children[curChar];
            }
            pCrawl->isLeaf = true;
        }

        bool search(string word) {
            trieNode *pCrawl = root;
            char curChar;
            for (int i = 0; i < word.size(); i++) {
                curChar = convertToIndex(word[i]);
                if (!pCrawl->children[curChar]) {
                    return false;
                }

                pCrawl = pCrawl->children[curChar];
            }

            if (pCrawl->isLeaf == false) {
                return false;
            }
            
            return true;
        }

        bool searchWordFromOthers(string words[], int size) {
            int len[size];
            sortLength(words, len, size);

            trieNode *pCrawl;
            char curChar;
            int max = 0, sum = 0;
            for (int k = 0; k < size; k++) {
                pCrawl = root;
                string word = words[k];
                sum = 0;
                for (int i = 0; i < word.size(); i++) {
                    curChar = convertToIndex(word[i]);
                    if (!pCrawl->children[curChar]) {
                        break;
                    }

                    pCrawl = pCrawl->children[curChar];
                    if (pCrawl->isLeaf) {
                        sum++;
                        if (sum > max) {
                            max = sum;
                        }
                        pCrawl = root;
                    }
                }
            }

           if (max > 0) { 
                cout<<"Max words is "<<max<<endl;
                return true;
           } else {
                return false;
           }

        }
};

static void sortLength(string words[], int len[], int size)
{

    for (int i = 0; i < size; i++) {
        len[i] = words[i].size();
    }

    vector<int> v_len(len, len + size);
    sort(v_len.begin(), v_len.end(), sortfunction);
}

bool sortfunction(int i, int j)
{
    return (i > j);
}

int main()
{
    tries t;
    char keys[][8] = {"the", "a", "there", "answer", "any",
        "by", "bye", "their"};

    string words[] = {"cat", "banana", "dog", "nana", "walker","boy", "dogwalkerboy"};

    char output[][32] = {"Not present in trie", "Present in trie"};
         
         
             
    // Construct trie
    int i;
    int size = sizeof(words)/sizeof(words[0]);
    for (i = 0; i < size; i++)
      //  t.insert(keys[i]);
        t.insert(words[i]);

    t.searchWordFromOthers(words, size);
    // Search for different keys
    /*
    cout<<"the--->"<<output[t.search("the")] <<endl;
    cout<<"these--->"<<output[t.search("these")]<<endl;;
    cout<<"their---->"<<output[t.search("their")]<<endl;;
    cout<<"thaw---->"<<output[t.search("thaw")]<<endl;
    */

    return 0;
}
