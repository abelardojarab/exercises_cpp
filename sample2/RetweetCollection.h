#pragma once
#include "Tweet.h"
#include <list>

class RetweetCollection
{
public:
	RetweetCollection()
		: empty_(true) {
	}

	~RetweetCollection() = default;

	bool isEmpty() const {
		return tweet_list_.empty();
	}
	void add(const Tweet& tweet) {
		tweet_list_.push_back(tweet);
	}
	void remove(Tweet& tweet) {
		tweet = tweet_list_.front();
		tweet_list_.pop_front();
	}


	unsigned int size() const {
		return tweet_list_.size();

	}
private:
	list<Tweet> tweet_list_;
	bool empty_;
};
