#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;
struct TrieNode { 
     struct TrieNode *children[ALPHABET_SIZE];
     bool isEndOfWord; 
}; 

struct TrieNode *getNode(void)
{
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
 
    return node;
}
 
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *temp = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!temp->children[index])
            temp->children[index] = getNode();
 
        temp = temp->children[index];
    }
 
    temp->isEndOfWord = true;
}


int countChildren(TrieNode *root,int &index)
{
    int count = 0;
    for(int i=0;i<26;i++)
    {
        if(root->children[i] != NULL)
        {
            count++;
            index = i;
        }
    }
    
    return count;
}

string findLongestCommonPrefix(TrieNode* root)
{
    TrieNode *temp = root; 
    int index; 
    string longestCommonPrefix; 
  
    while (countChildren(temp, index) == 1 && temp->isEndOfWord == false) 
    { 
        temp = temp->children[index]; 
        longestCommonPrefix.push_back('a'+index); 
    } 
    
    return longestCommonPrefix;
}

int main()
{
    string keys[] = {"the", "there",
                    "their", "theee"};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    cout << findLongestCommonPrefix(root);
 
    return 0;
}