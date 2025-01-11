class Twitter {
    int count;// use as a timeline of a tweet.
    unordered_map<int,set<int>> followerMap; // UsertID -> [Follower1, follower...]
    unordered_map<int,vector<vector<int>>> tweetMap; // UserId -> [[count,tweetId]]
public:
   

    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans; 

        auto compare = [](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);

        followerMap[userId].insert(userId); // consider tweets by the user himself

        for(int followeeId:followerMap[userId]) // consider each follower
        {
            if(tweetMap.count(followeeId)){ // check if tweet exists for that user
                vector<vector<int>> tweets = tweetMap[followeeId]; // Fetch all the tweets
                int index = tweets.size() - 1; // fetch the last tweet.
                vector<int> lastTweet = tweets[index];
                maxHeap.push({lastTweet[0], lastTweet[1], followeeId, index}); // {timeline(count), tweetid, followeeid, index}
            }
        }

        while(!maxHeap.empty() && ans.size()<10)
        {
            vector<int> curr = maxHeap.top();
            maxHeap.pop();
            ans.push_back(curr[1]); // Insert the tweetId
            int index = curr[3]; // fetch the index;
            if(index>0)
            {
                int followeeId = curr[2];
                vector<int> tweet = tweetMap[followeeId][index-1];
                maxHeap.push({tweet[0],tweet[1],followeeId,index-1});
            }
        }
        return ans;

    }

    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
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