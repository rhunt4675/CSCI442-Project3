#ifndef THREAD_H
#define THREAD_H

#include "burst.h"
#include "process.h"
#include <queue>
#include <cassert>

#define NUM_STATES 5

// Forward Declaration for Process class
class Process;

class Thread {
public:
	// Thread/Process State Enumeration
	enum State {
		NEW, READY, RUNNING, BLOCKED, EXIT
	};

	// Constructor
	Thread(int id, Process* parent, unsigned int arrival_time);

	// Returns id
	int get_id();

	// Returns response time
	unsigned int response_time();

	// Returns turnaround time
	unsigned int turnaround_time();

	// Returns previous state
	State get_previous_state();

	// Returns current state
	State get_current_state();

	// Returns a state name
	static std::string get_state_name(State state);

	// Sets a thread to ready
	void set_ready(unsigned int time);

	// Sets a thread to running
	void set_running(unsigned int time);

	// Sets a thread to blocked
	void set_blocked(unsigned int time);

	// Sets a thread to finished
	void set_finished(unsigned int time);

	// Push a burst onto the burst queue
	void pushBurst(Burst* burst);

	// Pop a burst off the burst queue
	Burst* popBurst();

	// Parent process of thread
	Process* process;

private:
	// PID
	int id;

	// Burst associated with thread
	std::queue<Burst*> bursts;

	// Current state of thread
	State current_state = NEW;

	// Previous state of thread
	State previous_state = NEW;

	// Thread arrival time
	int arrival_time = -1;

	// Time of first execution
	int start_time = -1;

	// Time of last execution
	int end_time = -1;

	// Time spent executing
	unsigned int service_time = 0;

	// Time spent doing I/O
	unsigned int io_time = 0;

	// Time of last state change
	 int last_state_change = -1;

    // Corresponding Name Array for States
    static std::string StateArray[NUM_STATES];
};

#endif
