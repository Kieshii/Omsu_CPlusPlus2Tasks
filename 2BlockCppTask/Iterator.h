#pragma once
#include "RingBuffer.h"

class Iterator {
	RingBuffer _ringBuffer;
	int index;
public:
	Iterator(const RingBuffer&);
	void start(); //������ �������
	void next(); //������� � ����.��������
	bool finish(); //��������� ��� �� ��������������
	int getValue(); //�������� ������� �������
};
