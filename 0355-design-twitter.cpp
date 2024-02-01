#include <bits/stdc++.h>

using namespace std;

/**
    Design a simplified version of Twitter where users can post tweets,
    follow/unfollow another user, and is able to see the 10 most recent
    tweets in the user's news feed.

    Implement the Twitter class:

    Twitter() Initializes your twitter object.

    - void postTweet(int userId, int tweetId) Composes a new tweet with
    ID tweetId by the user userId. Each call to this function will be made
    with a unique tweetId.

    - List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent
    tweet IDs in the user's news feed. Each item in the news feed must be
    posted by users who the user followed or by the user themself. Tweets
    must be ordered from most recent to least recent.

    - void follow(int followerId, int followeeId) The user with ID followerId
    started following the user with ID followeeId.

    - void unfollow(int followerId, int followeeId) The user with ID
    followerId started unfollowing the user with ID followeeId.

    Input
    ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
    [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
    Output
    [null, null, [5], null, null, [6, 5], null, [5]]

    Solution:
    1. User
         - userID: int
         - followedUsers: unordered_set<int>

         + void follow(int userID)
         + void unfollow(int userID)
         + bool follows(int userID)

    2. NewsFeed
         - vector<int> tweetIDs
         - vector<int> userIDs

         + vector<int> getNewsFeed(userID)
         + void postTweet(userID, tweetID)

    3. Twitter
         - users: unordered_map<int, User>
         - newsFeed: NewsFeed
**/

class Twitter {
public:
    Twitter() {}

    void postTweet(int userID, int tweetID) {
        if(!users.contains(userID))
            users[userID] = {};

        newsFeed.postTweet(userID, tweetID);
    }

    vector<int> getNewsFeed(int userID) {
        return newsFeed.getNewsFeed(userID, users);
    }

    void follow(int followerID, int followeeID) {
        if(!users.contains(followerID))
            users[followerID] = {};

        users[followerID]->follow(followeeID);
    }

    void unfollow(int followerID, int followeeID) {
        if(!users.contains(followerID))
            users[followerID] = {};

        users[followerID]->unfollow(followeeID);
    }

private:
    class User {
    public:
        void follow(int userID) {
            followedUsers.insert(userID);
        }

        void unfollow(int userID) {
            if(followedUsers.contains(userID))
                followedUsers.erase(userID);
        }

        bool follows(int userID) {
            return followedUsers.contains(userID);
        }

    private:
        unordered_set<int> followedUsers;
    };

    class NewsFeed {
    public:
        void postTweet(int userID, int tweetID) {
            userIDs.push_back(userID);
            tweetIDs.push_back(tweetID);
        }

        vector<int> getNewsFeed(int userID, unordered_map<int, User*> &_users) {
            vector<int> _newsFeed;

            int index = 0;
            while((int)_newsFeed.size() < 10 && (int)userIDs.size() - index - 1 >= 0) {
                int currentUser = userIDs[userIDs.size() - 1 - index];
                int currentTweet = tweetIDs[tweetIDs.size() - 1 - index];

                if(currentUser == userID || _users[userID]->follows(currentUser)) {
                    _newsFeed.push_back(currentTweet);
                }

                ++index;
            }

            return _newsFeed;
        };

    private:
        vector<int> userIDs;
        vector<int> tweetIDs;
    };

    unordered_map<int, User*> users;
    NewsFeed newsFeed;
};
