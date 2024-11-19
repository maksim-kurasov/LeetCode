#include <bits/stdc++.h>

using namespace std;

/**
    You have a bomb to defuse, and your time is running out!
    Your informer will provide you with a circular array code of
    length of n and a key k.

    To decrypt the code, you must replace every number. All the
    numbers are replaced simultaneously.

    If k > 0, replace the ith number with the sum of the next k numbers.
    If k < 0, replace the ith number with the sum of the previous k numbers.
    If k == 0, replace the ith number with 0.

    As code is circular, the next element of code[n-1] is code[0],
    and the previous element of code[0] is code[n-1].

    Given the circular array code and an integer key k, return
    the decrypted code to defuse the bomb!

    Solution:
    Sliding window.
**/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size());

        if (k >= 0) {
            int sum = 0;
            for (int i = 0; i < k; ++i) sum += code[i];

            for (int i = 0; i < code.size(); ++i) {
                sum -= code[i];
                sum += code[(i + k) % code.size()];
                result[i] = sum;
            }
        } else {
            int sum = 0;
            for (int i = code.size() - 1; i >= code.size() + k; --i) sum += code[i];

            for (int i = code.size() - 1; i >= 0; --i) {
                sum -= code[i];
                sum += code[(i + k < 0 ? code.size() + (i + k) : (i + k))];
                result[i] = sum;
            }
        }

        return result;
    }
};


int main() {
    Solution sol;

    vector<int> code = {2,4,9,3};
    auto res = sol.decrypt(code, -2);
    for (auto t : res) cout << t << " ";
}