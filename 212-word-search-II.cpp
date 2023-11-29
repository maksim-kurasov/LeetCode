#include <bits/stdc++.h>

using namespace std;

/**
    Given an m x n board of characters and a list of strings words, return all words on the board.

    Each word must be constructed from letters of sequentially adjacent cells, where
    adjacent cells are horizontally or vertically neighboring. The same letter cell may
    not be used more than once in a word.

    Input: board = [['o','a','a','n'},['e','t','a','e'],['i','h','k','r'],['i','f','l','v']],
           words = ['oath','pea','eat','rain']
    Output: ['eat','oath']

    Solution:
    Trie for [words], then dfs for [board]
*/

class Trie {
public:
    Trie* children[26] = {nullptr};
    bool isWord = false;
};

class Solution {
private:
    Trie trie;
    string currentString;
    vector<string> result;

public:
    void addWord(const string &word) {
        Trie *dummy = &trie;
        for(int i = 0; i < word.length(); ++i) {
            char chr = word[i] - 'a';
            if(!dummy->children[chr])
                dummy->children[chr] = new Trie();

            dummy = dummy->children[chr];
        }

        dummy->isWord = true;
    }

    void search(vector<vector<char>>& board, Trie* node, int i, int j) {
        if(node->isWord) {
            node->isWord = false;
            result.push_back(currentString);
        }

        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] == '0' || !node->children[board[i][j] - 'a'])
            return;

        char chr = board[i][j];
        currentString += chr;

        board[i][j] = '0'; // traversed cell
        search(board, node->children[chr - 'a'], i + 1, j);
        search(board, node->children[chr - 'a'], i - 1, j);
        search(board, node->children[chr - 'a'], i, j + 1);
        search(board, node->children[chr - 'a'], i, j - 1);
        board[i][j] = chr;

        currentString.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Add words to trie
        for(const string &word : words)
            addWord(word);

        // Check if the words are on the board
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                search(board, &trie, i, j);
            }
        }

        return result;
    }
};

/**
int main() {
    vector<vector<char>> board = {{'a','b'},{'c','d'}};
    vector<string> words = {"abcb"};
    Solution solution;
    vector<string> ans = solution.findWords(board, words);
}
**/
