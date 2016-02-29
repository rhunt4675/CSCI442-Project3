#include "simulation.h"

void Simulation::run(std::string &file) {
	// Populate the event queue
	parseFile(file);

	// Run event loop while event queue isn't empty
	while (!events.empty()) {
		// Get top element of queue
		const Event* event = events.top();
		events.pop();

		// Invoke appropriate method for each event
		switch(event->get_type()) {
			case Event::THREAD_ARRIVED:
				handle_thread_arrived(event); break;
			case Event::THREAD_DISPATCH_COMPLETED:
			case Event::PROCESS_DISPATCH_COMPLETED:
			case Event::CPU_BURST_COMPLETED:
			case Event::IO_BURST_COMPLETED:
			case Event::THREAD_COMPLETED:
			case Event::THREAD_PREEMEPTED:
			case Event::DISPATCHER_INVOKED:
				break;
		}
	}

	// Print simulation statistics
	printStatistics();
}

void Simulation::parseFile(std::string &file) {
	std::ifstream simFile(file);

	// ifstream error
	if (!simFile) {
		std::cerr << "Cannot open: " << file << std::endl;
		exit(-2);
	}

	// Temporary variables
	int num_processes(-1), pid(0), type(0), num_threads(0), arrival_time(0), num_bursts(0), burst_length(0);

	// First line of simulation file
	simFile >> num_processes >> thread_switch_overhead >> process_switch_overhead;

	// Iterate through processes
	for (int i = 0; i < num_processes; i++) {
		simFile >> pid >> type >> num_threads;

		// Create a process object
		Process* process = new Process(pid, static_cast<Process::Type>(type));

		// Iterate through threads
		for (int j = 0; j < num_threads; j++) {
			simFile >> arrival_time >> num_bursts;

			// Create a thread, passing the constructor the parent process
			Thread* thread = new Thread(j, process, arrival_time);

			// Iterate through bursts
			for (int k = 0; k < num_bursts; k++) {

				// Iterate through alternating CPU and IO bursts
				for (int l = 0; l < 2 && k + l < num_bursts; l++) {
					// Create a CPU burst object
					simFile >> burst_length;
					Burst *burst = new Burst(static_cast<Burst::Type>(l), burst_length);

					// Add the burst to the thread's queue
					thread->pushBurst(burst);
				}
			}
			
			// Add the thread to the parent's thread vector
			process->pushThread(thread);

			// Create an event, passing the constructor the thread
			Event* event = new Event(Event::Type::THREAD_ARRIVED, arrival_time, thread, NULL);

			// Add the event to the event queue
			events.push(event);
		}
	}
}

// handle_thread_arrived handles the THREAD_ARRIVED event in the event queue
void Simulation::handle_thread_arrived(const Event *event) {
	logger->print_state_transition(event, Thread::State::NEW, Thread::State::READY);
}

// printStatistics prints required statistics from the simulation
void Simulation::printStatistics() {

}