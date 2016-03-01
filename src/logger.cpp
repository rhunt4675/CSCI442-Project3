#include "logger.h"

// If verbose is true, prints a state-transition message
void Logger::print_state_transition(const Event* event, Thread::State before_state, Thread::State after_state) {
	std::cout << "At time " << event->get_time() << ":" << std::endl
		 << "\t" << Event::get_type_name(event->get_type()) << std::endl
		 << "\t" << "Thread " << event->thread->get_id() << " in process " << event->thread->process->get_pid() << " [" << Process::get_type_name(event->thread->process->get_type()) << "]" << std::endl
		 << "\t" << "Transitioned from " << Thread::get_state_name(before_state) << " to " << Thread::get_state_name(after_state) << std::endl << std::endl;
}

// if per_thread is true, prints information about a process and its threads
void Logger::print_process_details(Process* process) const {

}

// Prints overall simulation statistics
//void print_statistics(SystemStats stats) const {

//}
