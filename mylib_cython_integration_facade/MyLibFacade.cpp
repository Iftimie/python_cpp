#include <iostream>
#include "MyLibFacade.h"

MyLibFacade::MyLibFacade (int device_index) {
    mylib_ptr = new MyLibClass();
    mylib_ptr->print_value(5);
}

void MyLibFacade::sendDataBuffer (char* data, int length, Metadata metadata) {
    mylib_ptr->sendDataBuffer(data);
}

Metadata MyLibFacade::getDataBuffer(char* data, int length){
    Metadata metadata;
    metadata.packets.push_back(Packet());
    data[1] = 10;
    data[2] = 20;
    return metadata;
}
