#include <iostream>
#include "RingBuffer.h"
#include "Iterator.h"

using namespace std;

int main()
{
    size_t size = 100;
    RingBuffer ringBuffer(size);
    cout << "Occupied :" << ringBuffer.getOccupiedSpace() << endl;
    cout << "Free :" << ringBuffer.getFreeSpace() << endl;
    cout << "IsEmpty :" << ringBuffer.isEmpty() << endl;
    ringBuffer.add(10);
    cout << "Read : " << ringBuffer.read() << endl << endl;
    ringBuffer.add(15);
    cout << "Read : " << ringBuffer.read() << endl << endl;
    ringBuffer.add(10);
    cout << "Read : " << ringBuffer.read() << endl << endl;
    ringBuffer.add(24);
    cout << "Read : " << ringBuffer.read() << endl << endl;
    ringBuffer.add(10);
    cout << "Read : " << ringBuffer.read() << endl << endl;
    ringBuffer.add(7870);
    cout << "Read : " << ringBuffer.read() << endl << endl;
    ringBuffer.add(10123);
    cout << "Read : " << ringBuffer.read() << endl << endl;
    ringBuffer.add(123456);
    cout << "Read : " << ringBuffer.read() << endl << endl << endl;
    for (int i = 0; i <= 7; i++) {
        cout << "Pop  :" << ringBuffer.pop() << endl;
        cout << "Occupied :" << ringBuffer.getOccupiedSpace() << endl;
        cout << "Free :" << ringBuffer.getFreeSpace() << endl;
    }
    ringBuffer.free();

    ringBuffer.add(10);
    ringBuffer.add(15);
    ringBuffer.add(10);
    ringBuffer.add(24);
    ringBuffer.add(10);
    ringBuffer.add(7870);
    ringBuffer.add(10123);
    ringBuffer.add(123456);
    cout << ringBuffer.read() << endl;
    cout << ringBuffer.read() << endl;
    cout << ringBuffer.read() << endl;
    Iterator it(ringBuffer);
    it.start();

    while (!it.finish()) {
        cout << it.getValue() << " ";
        it.next();
    }
    try{
        it.next();
    }
    catch (invalid_argument& e) {
        cout << endl << e.what() << endl; //исключение отлавливается, все выводится как выше, но выскакивает ошибка, почему?
    }
    return 0;
}

