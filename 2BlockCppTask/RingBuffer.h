#pragma once

#include <iostream>

class RingBuffer {
private:
	int* _data;
	size_t _size;
	size_t _freeSpace;
	size_t _occupiedSpace;
public:
	RingBuffer();
	RingBuffer(size_t size);
	RingBuffer(RingBuffer const& ringBuffer);
	~RingBuffer();

	size_t getFreeSpace() const;
	size_t getOccupiedSpace() const;
	void add(int val);
	int pop();
	int read();
	void free();
	bool isEmpty() const;
	friend class Iteratorl;
};
