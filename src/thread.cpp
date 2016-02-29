#include "thread.h"

void Thread::set_ready(unsigned int time) {
	// Update thread state
	previous_state = current_state;
	current_state = State::READY;

	// Update Service and IO time counters
	if (previous_state == State::RUNNING || previous_state == State::BLOCKED)
		service_time += time - last_state_change;

	// Update last_state_change time
	last_state_change = time;
}

void Thread::set_running(unsigned int time) {
	// Assert previously ready
	assert(current_state == State::READY);

	// Update thread state
	previous_state = current_state;
	current_state = State::RUNNING;

	// Update start_time if this is the first time the thread has executed
	if (start_time == -1)
		start_time = time;

	// Update last_state_change time
	last_state_change = time;
}

void Thread::set_blocked(unsigned int time) {
	// Assert previously running
	assert(current_state == State::RUNNING);

	// Update thread state
	previous_state = current_state;
	current_state = State::BLOCKED;

	// Update Service time counter
	if (previous_state == State::RUNNING)
		service_time += time - last_state_change;

	//Update last_state_change time
	last_state_change = time;
}

void Thread::set_finished(unsigned int time) {
	// Assert previously running
	assert(current_state == State::RUNNING);
	
	// Update thread state
	previous_state = current_state;
	current_state = State::EXIT;

	// Update Service time counter
	if (previous_state == State::RUNNING)
		service_time += time - last_state_change;

	// Update end_time
	end_time = time;

	//Update last_state_change time
	last_state_change = time;
}

void Thread::pushBurst(Burst* burst) {
	// Push the burst onto the queue
	bursts.push(burst);
}

Burst* Thread::popBurst() {
	// Get the first element, then pop it
	Burst* burst = bursts.front();
	bursts.pop();

	// Return the front element
	return burst;
}

// response_time returns response time
unsigned int Thread::response_time() {
	// Assert that thread has exited
	assert(current_state == State::EXIT);

	// Return response time
	return start_time - arrival_time;
}

// turnaround_time returns turnaround time
unsigned int Thread::turnaround_time() {
	// Assert that thread has exited
	assert(current_state == State::EXIT);

	// Return turnaround time
	return end_time - arrival_time;
}

// get_current_state returns the current state
Thread::State Thread::get_current_state() {
	return current_state;
}

// get_previous_state returns the previous state
Thread::State Thread::get_previous_state() {
	return previous_state;
}