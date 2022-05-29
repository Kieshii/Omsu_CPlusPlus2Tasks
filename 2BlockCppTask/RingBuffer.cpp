#include "RingBuffer.h"

using namespace std;
size_t RingBuffer::getFreeSpace() const
{
    return _freeSpace;
}
size_t RingBuffer::getOccupiedSpace() const
{
    return _occupiedSpace;
}

RingBuffer::RingBuffer()
{
    _size = 1024;
    _data = new int[_size];
    _freeSpace = _size;
    _occupiedSpace = 0;
}

RingBuffer::RingBuffer(size_t size) {
    _size = size;
    _data = new int[_size];
    _freeSpace = _size;
    _occupiedSpace = 0;
}


RingBuffer::~RingBuffer()
{
    delete[] _data;
}

void RingBuffer::add(int val)
{
    if (_freeSpace == 0) {
        throw invalid_argument("There are no more space");
    }
    _data[_occupiedSpace++ % _size] = val;
    _freeSpace--;
}

int RingBuffer::pop()
{
    if (_occupiedSpace == 0)
        throw invalid_argument("Buffer is empty");

    int res = _data[0];

    for (int i = 1; i < _occupiedSpace; ++i)
        _data[i - 1] = _data[i];

    _occupiedSpace--;
    _freeSpace++;
    return res;
}

int RingBuffer::read() {
    if (_occupiedSpace == 0) { throw invalid_argument("Buffer is empty"); }
    int res = _data[0];
    return res;
}

void RingBuffer::free() {
    delete _data;
    _data = new int[_size];
    _freeSpace = _size;
    _occupiedSpace = 0;
}

bool RingBuffer::isEmpty() const {
    if (_occupiedSpace == 0) {
        return true;
    }
    return false;
}


RingBuffer::RingBuffer(RingBuffer const& ringBuffer) {
    _data = ringBuffer._data;
    _occupiedSpace = ringBuffer._occupiedSpace;
    _size = ringBuffer._size;
    _freeSpace = ringBuffer._freeSpace;
}


