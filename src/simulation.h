#ifndef SIMULATION_H
#define SIMULATION_H

#include <map>
#include <queue>
#include <fstream>
#include "logger.h"
#include "decision.h"
#include "scheduler.h"


class Simulation {
public:
	// Constructor
	Simulation(Scheduler *scheduler, Logger *logger) {
		this->scheduler = scheduler;
		this->logger = logger;
	}

	// Runs main event loop given a simulation filename
	void run(std::string &file);

private:
	// Map of PIDs to Processes
	std::map<int, Process> pidMap;

	// Event Priority Queue
	std::priority_queue<Event*, std::vector<const Event*>, EventComparator> events;

	// Chosen scheduler
	Scheduler *scheduler;

	// Logger instance
	Logger *logger;

	// Overheads for thread and process switches
	unsigned int thread_switch_overhead;
	unsigned int process_switch_overhead;

	// Parses simulation file and population event queue
	void parseFile(std::string &file);

	// Event Handlers
	void handle_thread_arrived(const Event *event);

	// Prints simulation statistics
	void printStatistics();
};

#endif