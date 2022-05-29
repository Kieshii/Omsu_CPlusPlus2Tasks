#pragma once
#include "RingBuffer.h"

class Iterator {
	RingBuffer _ringBuffer;
	int index;
public:
	Iterator(const RingBuffer&);
	void start(); //Начать перебор
	void next(); //Перейти к след.элементу
	bool finish(); //проверить все ли проитерировано
	int getValue(); //получить элемент очереди
};
