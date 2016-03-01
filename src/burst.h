#ifndef BURST_H
#define BURST_H

class Burst {
public:
	// Type of Burst Enumeration
	enum Type {
		CPU, IO
	};

	// Constructor
	Burst(Type type, unsigned int length) {
		this->type = type;
		this->length = length;
	}

private:
	// Type of Burst
	Type type;

	// Length of Burst
	unsigned int length;
};

#endif
