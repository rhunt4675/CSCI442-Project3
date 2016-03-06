#include "logger.h"

// If verbose is true, prints a state-transition message
void Logger::print_state_transition(const Event* event, Thread::State before_state, Thread::State after_state) {
	if (verbose) {
		std::cout << "At time " << event->get_time() << ":" << std::endl
			 << "\t" << Event::get_type_name(event->get_type()) << std::endl
			 << "\t" << "Thread " << event->thread->get_id() << " in process " << event->thread->process->get_pid() << " [" << Process::get_type_name(event->thread->process->get_type()) << "]" << std::endl
			 << "\t" << "Transitioned from " << Thread::get_state_name(before_state) << " to " << Thread::get_state_name(after_state) << std::endl << std::endl;
	}
}

// If verbose is true, prints a dispatcher invoked custom message
void Logger::print_dispatch_invoked_message(const Event* event, Thread *thread, std::string message) {
	if (verbose) {
		std::cout << "At time " << event->get_time() << ":" << std::endl
			 << "\t" << Event::get_type_name(event->get_type()) << std::endl
			 << "\t" << "Thread " << thread->get_id() << " in process " << thread->process->get_pid() << " [" << Process::get_type_name(thread->process->get_type()) << "]" << std::endl
			 << "\t" << message << std::endl << std::endl;
	}
}

// if per_thread is true, prints information about a process and its threads
void Logger::print_process_details(Process* process) const {
	if (per_thread) {
		std::cout << "Process " << process->get_pid() << " [" << Process::get_type_name(process->get_type()) << "]:" << std::endl;

		// Get a const reference to the process' child threads
		const std::vector<Thread*> threads = process->getThreads();
		for (int i = 0; i < (int) threads.size(); i++) {
			std::cout << std::left << "\tThread " << threads[i]->get_id() << ": " << "  ARR: " << std::setw(6) << threads[i]->get_arrival_time() << "CPU: " << std::setw(6) << threads[i]->get_service_time()
					  << "I/O: " << std::setw(6) << threads[i]->get_io_time() << "TRT: " << std::setw(6) << threads[i]->get_turnaround_time() << "END: " << std::setw(6) << threads[i]->get_end_time() << std::endl;
		} 

		std::cout << std::endl;
	}
}

// Prints overall simulation statistics
void Logger::print_statistics(SystemStats stats) const {
	std::cout << "SIMULATION COMPLETED!" << std::endl << std::endl;

	// Iterate through each type of thread (SYSTEM, INTERACTIVE, NORMAL, BATCH) and print statistics
	for (int i = 0; i < 4; i++) {
		std::cout << Process::get_type_name( (Process::Type) i) << " THREADS:" << std::endl
				  << "\t" << "Total count: " << "\t\t" << std::right << std::setw(6) << stats.count[i] << std::endl
				  << "\t" << "Avg response time:" << "\t" << std::right << std::setw(6) << std::fixed << std::setprecision(2) << stats.response[i] << std::endl
				  << "\t" << "Avg turnaround time:" << "\t" << std::right << std::setw(6) << std::fixed << std::setprecision(2) << stats.turnaround[i] << std::endl << std::endl;
	}

	std::cout << "Total elapsed time:" << "\t\t" << std::right << std::setw(6) << stats.elapsed << std::endl
			  << "Total service time:" << "\t\t" << std::right << std::setw(6) << stats.service << std::endl
			  << "Total I/O time:" << "\t\t\t" << std::right << std::setw(6) << stats.io << std::endl
			  << "Total dispatch time:" << "\t\t" << std::right << std::setw(6) << stats.dispatch << std::endl
			  << "Total idle time:" << "\t\t" << std::right << std::setw(6) << stats.idle << std::endl << std::endl

			  << "CPU Utilization:" << "\t\t" << std::right << std::setw(5) << stats.utilization << "%" << std::endl
			  << "CPU efficiency:" << "\t\t\t" << std::right << std::setw(5) << stats.efficiency << "%" << std::endl;
}