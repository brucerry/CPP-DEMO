// https://leetcode.com/problems/design-twitter/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
using namespace std;

// m = # of tweets of each user
// n = # of users
// time: O(n * log(n)) for getNewsFeed(), O(1) for others
// space: O(n * (n + m)) => O(n^2 + n * m)

class Twitter {
public:
  Twitter() : curTime(0) {
    
  }
  
  void postTweet(int userId, int tweetId) {
    userInfo[userId].tweets.emplace_back(tweetId, curTime++);
  }
  
  vector<int> getNewsFeed(int userId) {
    priority_queue<tuple<int, int, int, int>> maxHeap; // postTime, tweetId, ownerId, next index
    
    // add self-tweet
    if (userInfo[userId].tweets.size()) {
      auto& [ tweetID, postTime ] = userInfo[userId].tweets.back();
      int lastIndex = userInfo[userId].tweets.size() - 1;
      maxHeap.emplace(postTime, tweetID, userId, lastIndex - 1);
    }
    
    // add followees' tweets
    for (const int& followeeId : userInfo[userId].following) {
      if (userInfo[followeeId].tweets.size()) {
        auto& [ tweetID, postTime ] = userInfo[followeeId].tweets.back();
        int lastIndex = userInfo[followeeId].tweets.size() - 1;
        maxHeap.emplace(postTime, tweetID, followeeId, lastIndex - 1);
      }
    }
    
    vector<int> feed;
    while (maxHeap.size() and feed.size() < 10) {
      auto [ _, tweetId, ownerId, index ] = maxHeap.top();
      maxHeap.pop();
      
      feed.emplace_back(tweetId);
      
      if (index >= 0) {
        auto& [ tweetID, postTime ] = userInfo[ownerId].tweets[index];
        maxHeap.emplace(postTime, tweetID, ownerId, index - 1);
      }
    }
    
    return feed;
  }
  
  void follow(int followerId, int followeeId) {
    userInfo[followerId].following.insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    userInfo[followerId].following.erase(followeeId);
  }
  
private:
  struct Tweet {
    int tweetID, postTime;
    Tweet(int tweetID, int postTime) : tweetID(tweetID), postTime(postTime) {}
  };
  
  struct User {
    vector<Tweet> tweets;
    unordered_set<int> following; // followee id
  };
  
  unordered_map<int, User> userInfo; // user id, User struct
  int curTime;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */