// https://leetcode.com/problems/design-twitter/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <algorithm>
using namespace std;

// n = # of follwees for each user
// k = # of users
// time: O(1) for postTweet(), follow() and unfollow(), O(n) for getNewsFeed()
// space: O(k)

class Twitter {
private:
  struct Tweet {
    int postTime, tweetId;
    
    Tweet(int time, int id) : postTime(time), tweetId(id) {};
  };
  
  struct User {
    vector<Tweet> tweets;
    unordered_set<int> following;
  };
  
  unordered_map<int, User> m_UserInfo;
  
  int m_Time;
  
public:
  Twitter() : m_Time(0) {
    
  }
  
  void postTweet(int userId, int tweetId) {
    m_UserInfo[userId].tweets.emplace_back(m_Time, tweetId);
    m_Time++;
  }
  
  vector<int> getNewsFeed(int userId) {
    vector<int> newsFeed;
    vector<tuple<int, int, int, int>> maxHeap; // postTime, tweetId, followeeId, prev tweet index
    
    // add latest self-tweet
    if (m_UserInfo[userId].tweets.size()) {
      int lastIndex = m_UserInfo[userId].tweets.size() - 1;
      const auto& [ postTime, tweetId ] = m_UserInfo[userId].tweets.back();
      maxHeap.emplace_back(postTime, tweetId, userId, lastIndex - 1);
    }    
    
    // add latest followees' tweets
    for (const int& followeeId : m_UserInfo[userId].following) {
      if (m_UserInfo[followeeId].tweets.size()) {
        int lastIndex = m_UserInfo[followeeId].tweets.size() - 1;
        const auto& [ postTime, tweetId ] = m_UserInfo[followeeId].tweets.back();
        maxHeap.emplace_back(postTime, tweetId, followeeId, lastIndex - 1);
      }
    }
    
    make_heap(maxHeap.begin(), maxHeap.end());
    
    while (maxHeap.size() && newsFeed.size() < 10) {
      const auto [ postTime, tweetId, followeeId, index ] = maxHeap.front();
      pop_heap(maxHeap.begin(), maxHeap.end());
      maxHeap.pop_back();
      
      newsFeed.emplace_back(tweetId);
      
      if (index >= 0) {
        const auto& [ postTime, tweetId ] = m_UserInfo[followeeId].tweets[index];
        maxHeap.emplace_back(postTime, tweetId, followeeId, index - 1);
        push_heap(maxHeap.begin(), maxHeap.end());
      }
    }
    
    return newsFeed;
  }
  
  void follow(int followerId, int followeeId) {
    m_UserInfo[followerId].following.emplace(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    m_UserInfo[followerId].following.erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */