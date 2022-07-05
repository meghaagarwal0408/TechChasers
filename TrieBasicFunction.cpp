
#include <iostream>
using namespace std;
#include <stdio.h>
#include <unordered_map>


const int ALPHABET_SIZE = 26;
struct TrieNode
{
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

int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their", "th", "theee", "app", "ape" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    return 0;
}
