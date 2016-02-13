#include<iostream>
#include<string>

using namespace std;

struct Node
{
    int value;
    string key;
    struct Node *next;
};


class hashTable
{
    private:
    int tableSize;
    Node **hashlist;
    int hash(string key);

    public:
    hashTable();
    void putData(string key,int value);
    bool getData(string key,int& value);
};

hashTable::hashTable()
{
    tableSize = 10;
    hashlist = new Node*[tableSize];
    for(int i = 0;i < tableSize;i++)
    {
        hashlist[i] = NULL;
    }
}

int hashTable::hash(string key)
{
    int value = 0;
    for(int i = 0; i < key.size(); i++)
    {
        value += (int)key[i];
    }
    return value%tableSize;
}

void hashTable::putData(string key,int value)
{
    int index = hash(key);
    Node *temp = new Node;
    temp->value = value;
    temp->key = key;
    temp->next = hashlist[index];
    hashlist[index] = temp;
}

bool hashTable::getData(string key,int& value)
{
    int index = hash(key);
    int found = false;
    Node *temp = hashlist[index]; 
    while(temp != NULL)
    {
        if(temp->key == key)
        {
            value = temp->value;
            found = true;
            break;
        }
        temp = temp->next;
    }
    return found;
}

int main()
{
    hashTable h;
    int value ; 
    h.putData("Vinoj",5);
    cout<<"Came here"<<endl;
    bool ret = h.getData("Vinoj",value);
    h.putData("Vinoj",6);
    cout<<"Value is"<<value<<"Ret is"<<ret<<endl;
    ret = h.getData("Vinoj",value);
    cout<<"Value is"<<value<<"Ret is"<<ret<<endl;
}
