#ifndef LOGGER_H
#define LOGGER_H

#include "event.h"
#include <iostream>

class Logger {
public:
	// Constructor
	Logger(bool verbose, bool per_thread) {
		this->verbose = verbose;
		this->per_thread = per_thread;
	}

	// If verbose is true, prints a state-transition message
	void print_state_transition(const Event* event, Thread::State before_state, Thread::State after_state);

	// if per_thread is true, prints information about a process and its threads
	void print_process_details(Process* process) const;

	// Prints overall simulation statistics
	//void print_statistics(SystemStats stats) const;

private:
	// Determines verbose/non-verbos mode
	bool verbose;

	// Determines whether or not to print per-process statistics
	bool per_thread;
};

#endif