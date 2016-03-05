#ifndef FCFSSCHEDULER_H
#define FCFSSCHEDULER_H
#include "scheduler.h"
#include <queue>

// FCFCComparator is a callback that orders events based on their time of arrival
struct FCFSComparator {
	bool operator()(const Event* e1, const Event* e2) {
		return e1->get_time() >= e2->get_time();
	}
};

// FCFSScheduler implements the first-come-first-served scheduler described in the textbook
class FCFSScheduler : public Scheduler {

public:
	// Returns next thread (or null if none left) that should be executed
	Decision* get_next_thread(const Event* event);

	// Adds a thread to the scheduler's ready queue
	void enqueue(const Event* event, Thread* thread);

private:
	// Priority queue that orders threads based on arrival time
	
	//std::priority_queue<Event*, std::vector<const Event*>, FCFSComparator> threads;
	std::queue<Thread*> threads;
};

#endif