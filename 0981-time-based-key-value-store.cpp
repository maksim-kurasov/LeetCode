#include <bits/stdc++.h>

using namespace std;

/*
    Design a time-based key-value data structure that can store multiple values
    for the same key at different time stamps and retrieve the key's value at a
    certain timestamp.

    Implement the TimeMap class:
        - TimeMap() Initializes the object of the data structure.

        - void set(String key, String value, int timestamp) Stores the key with
          the value at the given time timestamp.

        - String get(String key, int timestamp) Returns a value such that set was called
          previously, with timestamp_prev <= timestamp. If there are multiple such values,
          it returns the value associated with the largest timestamp_prev. If there are no
          values, it returns "".

    Solution:
    Use unordered map where each key corresponds to vector of pairs {value, timestamp}. When a new record is
    added, we push it back into the vector. When the record is being retrieved, we binary search timestamps in
    the vector, which corresponds to the given key.
*/

class TimeMap {
public:
    TimeMap() {
        std::ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp) {
        vector<pair<string, int>> &vec = mp[key];

        int l = 0,
            r = vec.size() - 1;

        string value = "";
        while(l <= r) {
            int mid = (l + r) / 2;
            auto &p = vec[mid];

            if(p.second <= timestamp) {
                value = vec[mid].first;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return value;
    }

private:
    unordered_map<string, vector<pair<string, int>>> mp;
};