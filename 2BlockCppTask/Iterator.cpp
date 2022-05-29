#include "Iterator.h"

using namespace std;
void Iterator::start()
{
    index = 0;
}
void Iterator::next()
{
    if (this->finish()) {
        throw invalid_argument("finish");
    }

    index = index + 1;
    _ringBuffer.pop();
}
bool Iterator::finish()
{
    return _ringBuffer.getOccupiedSpace() == 0;
}
int Iterator::getValue()
{
    return _ringBuffer.read();
}
Iterator::Iterator(const RingBuffer& ringBuffer)
{
    if (ringBuffer.isEmpty()) {
        throw invalid_argument("Empty");
    }
    _ringBuffer = ringBuffer;
    index = -1;
}
