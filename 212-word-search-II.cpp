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
    string word;

    void insert(string &word) {
        Trie *dummy = this;
        for(char chr : word) {
            if(!dummy->children[chr - 'a'])
                dummy->children[chr - 'a'] = new Trie();

            dummy = dummy->children[chr - 'a'];
        }

        dummy->isWord = true;
        dummy->word = word;
    }
};

class Solution {
public:
    bool traversed[12][12];
    void dfs(vector<string> &words, vector<vector<char>>& board, Trie* node, int i, int j) {
        if(node->isWord) {
            node->isWord = false;
            words.push_back(node->word);
        }

        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || !node->children[board[i][j] - 'a'] || traversed[i][j])
            return;

        traversed[i][j] = true;
        dfs(words, board, node->children[board[i][j] - 'a'], i + 1, j);
        dfs(words, board, node->children[board[i][j] - 'a'], i - 1, j);
        dfs(words, board, node->children[board[i][j] - 'a'], i, j + 1);
        dfs(words, board, node->children[board[i][j] - 'a'], i, j - 1);
        traversed[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Add words to trie
        Trie *trie = new Trie();
        for(string &word : words)
            trie->insert(word);

        // Check if the words are on the board
        vector<string> ans;
        set<pair<int, int>> traversed;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                dfs(ans, board, trie, i, j);
            }
        }

        return ans;
    }
};


int main() {
    vector<vector<char>> board = {{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'}};
    vector<string> words = {"aababababa","abbabababa","acbabababa","adbabababa","aebabababa","afbabababa","agbabababa","ahbabababa","aibabababa","ajbabababa","akbabababa","albabababa","ambabababa","anbabababa","aobabababa","apbabababa","aqbabababa","arbabababa","asbabababa","atbabababa","aubabababa","avbabababa","awbabababa","axbabababa","aybabababa","azbabababa","bababababa","bbbabababa","bcbabababa","bdbabababa","bebabababa","bfbabababa","bgbabababa","bhbabababa","bibabababa","bjbabababa","bkbabababa","blbabababa","bmbabababa","bnbabababa","bobabababa","bpbabababa","bqbabababa","brbabababa","bsbabababa","btbabababa","bubabababa","bvbabababa","bwbabababa","bxbabababa","bybabababa","bzbabababa","cababababa","cbbabababa","ccbabababa","cdbabababa","cebabababa","cfbabababa","cgbabababa","chbabababa","cibabababa","cjbabababa","ckbabababa","clbabababa","cmbabababa","cnbabababa","cobabababa","cpbabababa","cqbabababa","crbabababa","csbabababa","ctbabababa","cubabababa","cvbabababa","cwbabababa","cxbabababa","cybabababa","czbabababa","dababababa","dbbabababa","dcbabababa","ddbabababa","debabababa","dfbabababa","dgbabababa","dhbabababa","dibabababa","djbabababa","dkbabababa","dlbabababa","dmbabababa","dnbabababa","dobabababa","dpbabababa","dqbabababa","drbabababa","dsbabababa","dtbabababa","dubabababa","dvbabababa","dwbabababa","dxbabababa","dybabababa","dzbabababa","eababababa","ebbabababa","ecbabababa","edbabababa","eebabababa","efbabababa","egbabababa","ehbabababa","eibabababa","ejbabababa","ekbabababa","elbabababa","embabababa","enbabababa","eobabababa","epbabababa","eqbabababa","erbabababa","esbabababa","etbabababa","eubabababa","evbabababa","ewbabababa","exbabababa","eybabababa","ezbabababa","fababababa","fbbabababa","fcbabababa","fdbabababa","febabababa","ffbabababa","fgbabababa","fhbabababa","fibabababa","fjbabababa","fkbabababa","flbabababa","fmbabababa","fnbabababa","fobabababa","fpbabababa","fqbabababa","frbabababa","fsbabababa","ftbabababa","fubabababa","fvbabababa","fwbabababa","fxbabababa","fybabababa","fzbabababa","gababababa","gbbabababa","gcbabababa","gdbabababa","gebabababa","gfbabababa","ggbabababa","ghbabababa","gibabababa","gjbabababa","gkbabababa","glbabababa","gmbabababa","gnbabababa","gobabababa","gpbabababa","gqbabababa","grbabababa","gsbabababa","gtbabababa","gubabababa","gvbabababa","gwbabababa","gxbabababa","gybabababa","gzbabababa","hababababa","hbbabababa","hcbabababa","hdbabababa","hebabababa","hfbabababa","hgbabababa","hhbabababa","hibabababa","hjbabababa","hkbabababa","hlbabababa","hmbabababa","hnbabababa","hobabababa","hpbabababa","hqbabababa","hrbabababa","hsbabababa","htbabababa","hubabababa","hvbabababa","hwbabababa","hxbabababa","hybabababa","hzbabababa","iababababa","ibbabababa","icbabababa","idbabababa","iebabababa","ifbabababa","igbabababa","ihbabababa","iibabababa","ijbabababa","ikbabababa","ilbabababa","imbabababa","inbabababa","iobabababa","ipbabababa","iqbabababa","irbabababa","isbabababa","itbabababa","iubabababa","ivbabababa","iwbabababa","ixbabababa","iybabababa","izbabababa","jababababa","jbbabababa","jcbabababa","jdbabababa","jebabababa","jfbabababa","jgbabababa","jhbabababa","jibabababa","jjbabababa","jkbabababa","jlbabababa","jmbabababa","jnbabababa","jobabababa","jpbabababa","jqbabababa","jrbabababa","jsbabababa","jtbabababa","jubabababa","jvbabababa","jwbabababa","jxbabababa","jybabababa","jzbabababa","kababababa","kbbabababa","kcbabababa","kdbabababa","kebabababa","kfbabababa","kgbabababa","khbabababa","kibabababa","kjbabababa","kkbabababa","klbabababa","kmbabababa","knbabababa","kobabababa","kpbabababa","kqbabababa","krbabababa","ksbabababa","ktbabababa","kubabababa","kvbabababa","kwbabababa","kxbabababa","kybabababa","kzbabababa","lababababa","lbbabababa","lcbabababa","ldbabababa","lebabababa","lfbabababa","lgbabababa","lhbabababa","libabababa","ljbabababa","lkbabababa","llbabababa","lmbabababa","lnbabababa","lobabababa","lpbabababa","lqbabababa","lrbabababa","lsbabababa","ltbabababa","lubabababa","lvbabababa","lwbabababa","lxbabababa","lybabababa","lzbabababa","mababababa","mbbabababa","mcbabababa","mdbabababa","mebabababa","mfbabababa","mgbabababa","mhbabababa","mibabababa","mjbabababa","mkbabababa","mlbabababa","mmbabababa","mnbabababa","mobabababa","mpbabababa","mqbabababa","mrbabababa","msbabababa","mtbabababa","mubabababa","mvbabababa","mwbabababa","mxbabababa","mybabababa","mzbabababa","nababababa","nbbabababa","ncbabababa","ndbabababa","nebabababa","nfbabababa","ngbabababa","nhbabababa","nibabababa","njbabababa","nkbabababa","nlbabababa","nmbabababa","nnbabababa","nobabababa","npbabababa","nqbabababa","nrbabababa","nsbabababa","ntbabababa","nubabababa","nvbabababa","nwbabababa","nxbabababa","nybabababa","nzbabababa","oababababa","obbabababa","ocbabababa","odbabababa","oebabababa","ofbabababa","ogbabababa","ohbabababa","oibabababa","ojbabababa","okbabababa","olbabababa","ombabababa","onbabababa","oobabababa","opbabababa","oqbabababa","orbabababa","osbabababa","otbabababa","oubabababa","ovbabababa","owbabababa","oxbabababa","oybabababa","ozbabababa","pababababa","pbbabababa","pcbabababa","pdbabababa","pebabababa","pfbabababa","pgbabababa","phbabababa","pibabababa","pjbabababa","pkbabababa","plbabababa","pmbabababa","pnbabababa","pobabababa","ppbabababa","pqbabababa","prbabababa","psbabababa","ptbabababa","pubabababa","pvbabababa","pwbabababa","pxbabababa","pybabababa","pzbabababa","qababababa","qbbabababa","qcbabababa","qdbabababa","qebabababa","qfbabababa","qgbabababa","qhbabababa","qibabababa","qjbabababa","qkbabababa","qlbabababa","qmbabababa","qnbabababa","qobabababa","qpbabababa","qqbabababa","qrbabababa","qsbabababa","qtbabababa","qubabababa","qvbabababa","qwbabababa","qxbabababa","qybabababa","qzbabababa","rababababa","rbbabababa","rcbabababa","rdbabababa","rebabababa","rfbabababa","rgbabababa","rhbabababa","ribabababa","rjbabababa","rkbabababa","rlbabababa","rmbabababa","rnbabababa","robabababa","rpbabababa","rqbabababa","rrbabababa","rsbabababa","rtbabababa","rubabababa","rvbabababa","rwbabababa","rxbabababa","rybabababa","rzbabababa","sababababa","sbbabababa","scbabababa","sdbabababa","sebabababa","sfbabababa","sgbabababa","shbabababa","sibabababa","sjbabababa","skbabababa","slbabababa","smbabababa","snbabababa","sobabababa","spbabababa","sqbabababa","srbabababa","ssbabababa","stbabababa","subabababa","svbabababa","swbabababa","sxbabababa","sybabababa","szbabababa","tababababa","tbbabababa","tcbabababa","tdbabababa","tebabababa","tfbabababa","tgbabababa","thbabababa","tibabababa","tjbabababa","tkbabababa","tlbabababa","tmbabababa","tnbabababa","tobabababa","tpbabababa","tqbabababa","trbabababa","tsbabababa","ttbabababa","tubabababa","tvbabababa","twbabababa","txbabababa","tybabababa","tzbabababa","uababababa","ubbabababa","ucbabababa","udbabababa","uebabababa","ufbabababa","ugbabababa","uhbabababa","uibabababa","ujbabababa","ukbabababa","ulbabababa","umbabababa","unbabababa","uobabababa","upbabababa","uqbabababa","urbabababa","usbabababa","utbabababa","uubabababa","uvbabababa","uwbabababa","uxbabababa","uybabababa","uzbabababa","vababababa","vbbabababa","vcbabababa","vdbabababa","vebabababa","vfbabababa","vgbabababa","vhbabababa","vibabababa","vjbabababa","vkbabababa","vlbabababa","vmbabababa","vnbabababa","vobabababa","vpbabababa","vqbabababa","vrbabababa","vsbabababa","vtbabababa","vubabababa","vvbabababa","vwbabababa","vxbabababa","vybabababa","vzbabababa","wababababa","wbbabababa","wcbabababa","wdbabababa","webabababa","wfbabababa","wgbabababa","whbabababa","wibabababa","wjbabababa","wkbabababa","wlbabababa","wmbabababa","wnbabababa","wobabababa","wpbabababa","wqbabababa","wrbabababa","wsbabababa","wtbabababa","wubabababa","wvbabababa","wwbabababa","wxbabababa","wybabababa","wzbabababa","xababababa","xbbabababa","xcbabababa","xdbabababa","xebabababa","xfbabababa","xgbabababa","xhbabababa","xibabababa","xjbabababa","xkbabababa","xlbabababa","xmbabababa","xnbabababa","xobabababa","xpbabababa","xqbabababa","xrbabababa","xsbabababa","xtbabababa","xubabababa","xvbabababa","xwbabababa","xxbabababa","xybabababa","xzbabababa","yababababa","ybbabababa","ycbabababa","ydbabababa","yebabababa","yfbabababa","ygbabababa","yhbabababa","yibabababa","yjbabababa","ykbabababa","ylbabababa","ymbabababa","ynbabababa","yobabababa","ypbabababa","yqbabababa","yrbabababa","ysbabababa","ytbabababa","yubabababa","yvbabababa","ywbabababa","yxbabababa","yybabababa","yzbabababa","zababababa","zbbabababa","zcbabababa","zdbabababa","zebabababa","zfbabababa","zgbabababa","zhbabababa","zibabababa","zjbabababa","zkbabababa","zlbabababa","zmbabababa","znbabababa","zobabababa","zpbabababa","zqbabababa","zrbabababa","zsbabababa","ztbabababa","zubabababa","zvbabababa","zwbabababa","zxbabababa","zybabababa","zzbabababa"};
    Solution solution;
    vector<string> ans = solution.findWords(board, words);
}
