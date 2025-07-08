class Twitter {
public:
    long long time;
    map<int, vector<pair<int, int>>> userToTweet;
    map<int, set<int>> userToFollowing;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userToTweet[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int, int>> maxHeap;

        const auto& myTweets = userToTweet[userId];
        for(int i=0; i < myTweets.size(); i++) {
            maxHeap.push(myTweets[i]);
        }

        const auto& followSet = userToFollowing[userId];
        for(const int& followeeId: followSet) {
            const auto& tweets = userToTweet[followeeId];
            for(int i=0; i < tweets.size(); i++) {
                maxHeap.push(tweets[i]);
            }
        }

        vector<int> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            if(res.size() == 10) break;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        userToFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!userToFollowing[followerId].count(followeeId)) return;
        userToFollowing[followerId].erase(followeeId);
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