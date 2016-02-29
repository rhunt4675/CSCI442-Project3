#include "logger.h"

// If verbose is true, prints a state-transition message
void Logger::print_state_transition(const Event* event, Thread::State before_state, Thread::State after_state) {
	std::cout << "At time " << event->get_time() << ":" << std::endl
		 << event->get_type() << std::endl
		 << "\t" << "Thread " << event->thread->get_id() << " in process " << event->thread->process->get_pid() << " [?]" << std::endl
		 << "\t" << "Transitioned from " << (int) before_state << " to " << (int) after_state << std::endl;
}

// if per_thread is true, prints information about a process and its threads
void Logger::print_process_details(Process* process) const {

}

// Prints overall simulation statistics
//void print_statistics(SystemStats stats) const {

//}