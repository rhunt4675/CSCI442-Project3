#ifndef DECISION_H
#define DECISION_H

#include "thread.h"
#include <string>

// Defines a Single Scheduling Decision
class Decision {
	// Next thread (or null if none left) to run
	Thread* thread = NULL;

	// Amount of time before thread should be preempted (or -1 for no preemption)
	unsigned int time_slice = -1;

	// Message comtaining scheduling choice
	std::string explanation;
};

#endif