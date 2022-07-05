#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Trie
{
    bool isLeaf;
    unordered_map<char, Trie*> character;
};

string findLongestCommonPrefixUsingMap(vector<string> arr)
{
    Trie* head = new Trie();
    for (string s: arr) {
        insert(head, s);
    }
    
    string longestCommonPrefix;
    Trie* curr = head;
 
    while (curr && !curr->isLeaf && (curr->character.size() == 1))
    {
        auto it = curr->character.begin();
        longestCommonPrefix = longestCommonPrefix + it->first;
        curr = it->second;
    }
 
    return longestCommonPrefix;
}