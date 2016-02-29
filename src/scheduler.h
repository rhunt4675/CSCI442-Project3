#ifndef SCHEDULER_H
#define SCHEDULER_H

// Base Class for all Scheduling Algorithms
class Scheduler {
	// Returns next thread (or null if none left) that should be executed (virtual)
	virtual Decision* get_next_thead(const Event* event) = 0;

	// Adds a thread to the scheduler's ready queue (virtual)
	virtual void enqueue(const Event* event, Thread* thread) = 0;
};

#endif