#include <bits/stdc++.h>

using namespace std;

/**
    Given a characters array tasks, representing the tasks a CPU needs to do,
    where each letter represents a different task. Tasks could be done in any
    order. Each task is done in one unit of time. For each unit of time, the
    CPU could complete either one task or just be idle.

    However, there is a non-negative integer n that represents the cooldown
    period between two same tasks (the same letter in the array), that is
    that there must be at least n units of time between any two same tasks.

    Return the least number of units of times that the CPU will take to
    finish all the given tasks.

    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation:
    A -> B -> idle -> A -> B -> idle -> A -> B
    There is at least 2 units of time between any two same tasks.

    Solution:
    So, first we choose the character with the most repetitions.

    Let's say we've been given an input like this:
        Input: tasks = ["A","A","A","B","B","C","C","D","D"], n = 2

    Firstly, we have to accommodate the most frequent task. In that case
    it is 'A'
        A ? ? A ? ? A
    Then, if we have any tasks with the same frequency as 'A', we place them
    also. If we had tasks = ["A","A","A","B","B","B","C","C","D","D"], we would
    have placed them as
        A B ? A B ? A B
    We can notice that for each task with max frequency we do ++ans

    When we've placed all the most frequent tasks, we DEFINITELY can accommodate
    other letters. Because the parts can be of any length. In the example that
    is given above:
        Input: tasks = ["A","A","A","B","B","C","C","D","D"], n = 2

        1. | A ? ? | A ? ? | A |
        2. | A B ? | A B ? | A |
        3. | A B C | A B C | A |
        4. | A B C D | A B C D | A |

    So the ans is just the length of tasks.

    In any case the answer is such expression
        max(tasks.size(), (maxFrequency - 1) * (n + 1) + countMaxFrequency)
**/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter[26] = {};
        int maxValue = 0;
        int maxCount = 0;

        for(char task : tasks) {
            ++counter[task - 'A'];
            maxValue = max(maxValue, counter[task - 'A']);
        }

        for(int i = 0; i < 26; ++i) {
            if(counter[i] == maxValue) ++maxCount;
        }

        return max((int)tasks.size(), (maxValue - 1) * (n + 1) + maxCount);
    }
};
