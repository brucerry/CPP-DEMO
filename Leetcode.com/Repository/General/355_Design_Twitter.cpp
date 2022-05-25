// https://leetcode.com/problems/design-twitter/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
using namespace std;

// n = # of follwees for each user
// k = # of users
// time: O(1) for postTweet(), follow() and unfollow(), O(n) for getNewsFeed()
// space: O(k)

class Twitter {
public:
  Twitter() : m_CurTime(0) {
    
  }
  
  void postTweet(int userId, int tweetId) {
    m_UserInfo[userId].tweets.emplace_back(tweetId, m_CurTime++);
  }
  
  vector<int> getNewsFeed(int userId) {
    priority_queue<tuple<int, int, int, int>> maxHeap; // postTime, tweetID, userID, next tweet index
    
    // add self-tweet
    if (m_UserInfo[userId].tweets.size()) {
      auto& [ tweetID, postTime ] = m_UserInfo[userId].tweets.back();
      int lastIndex = m_UserInfo[userId].tweets.size() - 1;
      maxHeap.emplace(postTime, tweetID, userId, lastIndex - 1);
    }
    
    // add followees' tweets
    for (const int& followee : m_UserInfo[userId].followings) {
      if (m_UserInfo[followee].tweets.size()) {
        auto& [ tweetID, postTime ] = m_UserInfo[followee].tweets.back();
        int lastIndex = m_UserInfo[followee].tweets.size() - 1;
        maxHeap.emplace(postTime, tweetID, followee, lastIndex - 1);
      }
    }
    
    vector<int> newsFeed;
    while (maxHeap.size() and newsFeed.size() < 10) {
      auto [ _, tweetID, userID, tweetIndex ] = maxHeap.top();
      maxHeap.pop();
      
      newsFeed.emplace_back(tweetID);
      if (tweetIndex >= 0) {
        auto& [ tweetID, postTime ] = m_UserInfo[userID].tweets[tweetIndex];
        maxHeap.emplace(postTime, tweetID, userID, tweetIndex - 1);
      }
    }
    
    return newsFeed;
  }
  
  void follow(int followerId, int followeeId) {
    m_UserInfo[followerId].followings.emplace(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    m_UserInfo[followerId].followings.erase(followeeId);
  }
  
private:
  struct Tweet {
    int tweetID;
    int postTime;
    
    Tweet(int _tweetID, int _postTime) : tweetID(_tweetID), postTime(_postTime) {}
  };
  
  struct User {
    vector<Tweet> tweets; // tweet struct
    unordered_set<int> followings; // followee id
  };
  
  unordered_map<int, User> m_UserInfo; // user id, user struct
  int m_CurTime;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */