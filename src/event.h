#ifndef EVENT_H
#define EVENT_H

#include "decision.h"
#include "thread.h"

class Event {
public:
	// Event Type Enumeration
	enum Type {
		THREAD_ARRIVED, THREAD_DISPATCH_COMPLETED, PROCESS_DISPATCH_COMPLETED, CPU_BURST_COMPLETED,
		IO_BURST_COMPLETED, THREAD_COMPLETED, THREAD_PREEMEPTED, DISPATCHER_INVOKED
	};

	// Constructor
	Event(Type type, int time, Thread* thread, Decision* decision) {
		this->type = type;
		this->time = time;
		this->thread = thread;
		this->decision = decision;
	}

	// Returns time of event
	int get_time() const {
		return time;
	}

	Type get_type() const {
		return type;
	}

	// Associated thread (if applicable)
	Thread* thread;

private:
	// Type of Event
	Type type;

	// Time at which event occurs
	int time;

	// Associated scheduling decision (if applicable)
	const Decision* decision;
};

struct EventComparator {
	bool operator()(const Event* e1, const Event* e2) {
		return e1->get_time() >= e2->get_time();
	}
};

#endif