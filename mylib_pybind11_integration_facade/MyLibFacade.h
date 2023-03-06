#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <vector>
#include <mylib.hpp>

typedef struct {
	std::vector<int>    data;
	int                 value;
} Packet;

typedef struct {
	std::vector<Packet> packets;
} Metadata;

class MyLibFacade {
private:
    MyLibClass* mylib_ptr = NULL;

    public:
        MyLibFacade(int device_index);
        void sendDataBuffer(char* data, int length, Metadata metadata);
        Metadata getDataBuffer(char* data, int length);
};

#endif