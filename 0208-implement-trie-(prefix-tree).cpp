#include <bits/stdc++.h>

using namespace std;

/**
    A trie (pronounced as "try") or prefix tree is a tree data structure used
    to efficiently store and retrieve keys in a dataset of strings. There are
    various applications of this data structure, such as autocomplete and spellchecker.

    Implement the Trie class:

    - [Trie()] Initializes the trie object.

    - [void insert(String word)] Inserts the string word into the trie.

    - [boolean search(String word)] Returns true if the string word is in the trie
      (i.e., was inserted before), and false otherwise.

    - [boolean startsWith(String prefix)] Returns true if there is a previously inserted
      string word that has the prefix prefix, and false otherwise.

    Input
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    Output
    [null, null, true, false, true, null, true]

    Solution:
    Trie data structure
    Words consist only of lowercase eng letters so we can use array instead of map
*/

class Trie {
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *dummy = root;
        for(char chr : word) {
            if(!dummy->children[chr - 'a'])
                dummy->children[chr - 'a'] = new Node();

            dummy = dummy->children[chr - 'a'];
        }

        dummy->isWord = true;
    }

    bool search(string word) {
        Node *dummy = root;
        for(char chr : word) {
            if(!dummy->children[chr - 'a'])
                return false;

            dummy = dummy->children[chr - 'a'];
        }

        return dummy->isWord;
    }

    bool startsWith(string prefix) {
        Node *dummy = root;
        for(char chr : prefix) {
            if(!dummy->children[chr - 'a'])
                return false;

            dummy = dummy->children[chr - 'a'];
        }

        return true;
    }

private:
    class Node {
    public:
        Node* children[26] = {nullptr};
        bool isWord = false;
    };

    Node *root;
};

/** [TEST]
int main() {
    string word = "ssa";
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith("sa");
}
**/