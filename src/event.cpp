#include "event.h"

// Out-of-class Static Initializer
std::string Event::TypeArray[] = {
	"THREAD_ARRIVED", "THREAD_DISPATCH_COMPLETED", "PROCESS_DISPATCH_COMPLETED", "CPU_BURST_COMPLETED",
    "IO_BURST_COMPLETED", "THREAD_COMPLETED", "THREAD_PREEMEPTED", "DISPATCHER_INVOKED"
};

// Parameterized Constructor
Event::Event(Type type, int time, Thread* thread, Decision* decision) {
	this->type = type;
	this->time = time;
	this->thread = thread;
	this->decision = decision;
}

// Returns time of event
int Event::get_time() const {
	return time;
}

// Returns type of event
Event::Type Event::get_type() const {
	return type;
}

// Returns name of a given event
std::string Event::get_type_name(Event::Type type) {
	return TypeArray[type];
}