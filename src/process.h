#ifndef PROCESS_H
#define PROCESS_H

#include "thread.h"
#include <vector>

// Forward Declaration for Thread Class
class Thread;

class Process {
public:
	// Process Type Enumeration (including priority)
	enum Type {
		SYSTEM, INTERACTIVE, NORMAL, BATCH
	};

	// Constructor
	Process(int pid, Type type) {
		this->pid = pid;
		this->type = type;
	}

	// Returns pid
	int get_pid() {
		return pid;
	}

	// Push a thread into the thread vector
	void pushThread(Thread* thread) {
		threads.push_back(thread);
	}

private:
	// PID
	int pid;

	// Process Type and Priority
	Type type;

	// Associated Threads
	std::vector<Thread*> threads;
};

#endif