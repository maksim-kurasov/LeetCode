#include <bits/stdc++.h>

using namespace std;

/**
    Design a data structure that supports adding new words and finding if a string
    matches any previously added string.

    Implement the WordDictionary class:

    - WordDictionary() Initializes the object.

    - void addWord(word) Adds word to the data structure, it can be matched later.

    - bool search(word) Returns true if there is any string in the data structure that
      matches word or false otherwise. word may contain dots '.' where dots can be
      matched with any letter.

    Input
    ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
    [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
    Output
    [null,null,null,null,false,true,true,true]

    Solution:
    Basically, the same as 0208-implement-trie, but when we search for the word with
    the dot in it, we substitute the dot with every possible character
*/

class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node *dummy = root;
        for(char chr : word) {
            if(!dummy->children.contains(chr))
                dummy->children[chr] = new Node();

            dummy = dummy->children[chr];
        }

        dummy->isWord = true;
    }

    bool search(string word) {
        return search(root, word.begin());
    }

private:
    class Node {
    public:
        map<char, Node*> children;
        bool isWord = false;
    };

    bool search(Node *node, string::iterator it) {
        Node *dummy = node;

        char chr;
        while(*it) {
            chr = *it++;
            if(chr == '.') {
                for(auto [key, value] : dummy->children) {
                    if(search(dummy->children[key], it))
                        return true;
                }
                return false;
            }

            if(!dummy->children.contains(chr))
                return false;

            dummy = dummy->children[chr];
        }

        return dummy->isWord;
    }

    Node *root;
};

/**
int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("a");
    wordDictionary.addWord("a");

    cout << wordDictionary.search(".") << endl; // 1
    cout << wordDictionary.search("a") << endl; // 1
    cout << wordDictionary.search("aa") << endl; // 0
    cout << wordDictionary.search("a") << endl; // 1
    cout << wordDictionary.search(".a") << endl; // 0
    cout << wordDictionary.search("a.") << endl;

}
**/