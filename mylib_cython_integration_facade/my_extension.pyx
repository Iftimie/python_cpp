from libcpp.vector cimport vector
cimport numpy as np

cdef extern from "MyLibFacade.cpp":
    pass

cdef extern from "MyLibFacade.h":

    ctypedef struct Packet:
        vector[int] data
        int value

    ctypedef struct Metadata:
        vector[Packet] packets

    cdef cppclass MyLibFacade:
        MyLibFacade(int) except +
        void sendDataBuffer(char* data, int length, Metadata metadata)
        Metadata getDataBuffer(char* data, int length)


def interact(image):
    cdef Metadata m1
    cdef Packet packet

    packet.data.push_back(1)
    m1.packets.push_back(packet)

    my_lib_facade_ptr = new MyLibFacade(1)
    cdef char* data = <char*>np.PyArray_DATA(image)
    my_lib_facade_ptr.sendDataBuffer(data, image.size, m1)
    m2 = my_lib_facade_ptr.getDataBuffer(data, image.size)
    del my_lib_facade_ptr

    return m1, m2
