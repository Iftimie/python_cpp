#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include "MyLibFacade.h"
namespace py = pybind11;

std::tuple<Metadata, Metadata> interact(py::array_t<unsigned char> image){
    Metadata m1;
    Packet packet;
    packet.data.push_back(1);
    m1.packets.push_back(packet);

    MyLibFacade* my_lib_facade_ptr = new MyLibFacade(1);
    my_lib_facade_ptr->sendDataBuffer((char*)image.data(), image.size(), m1);
    Metadata m2 = my_lib_facade_ptr->getDataBuffer((char*)image.data(), image.size());
    delete my_lib_facade_ptr;

    return {m1, m2};
}

auto dumpPacket = [](const Packet& p) {
    return py::make_tuple(p.data, p.value);
};
auto loadPacket = [](py::tuple t) {
    return Packet{t[0].cast<std::vector<int>>(), t[1].cast<int>()};
};

auto dumpVectorPackets = [](const std::vector<Packet>& vp) {
    std::vector<py::tuple> v;
    for(auto p: vp) {
        v.push_back(dumpPacket(p));
    }
    return py::make_tuple(v);
};

auto loadVectorPackets = [](py::tuple t) {
    std::vector<Packet> v;
    for (py::tuple pt: t[0].cast<std::vector<py::tuple>>()){
        v.push_back(loadPacket(pt));
    }
    return v;
};

auto dumpMetadata = [](const Metadata& m) {
    return py::make_tuple(
        dumpVectorPackets(m.packets)
        );
};
auto loadMetadata = [](py::tuple t) {
    return Metadata{
        loadVectorPackets(t[0].cast<py::tuple>())
    };
};

PYBIND11_MODULE(my_extension, m) {
    m.doc() = R"pbdoc(
        -----------------------
        .. currentmodule:: pybind11_extension
        .. autosummary::
           :toctree: _generate
    )pbdoc";
    m.def("interact", &interact);
    py::class_<Packet>(m, "Packet")
      .def_readwrite("data", &Packet::data)
      .def_readwrite("value", &Packet::value);
    py::class_<Metadata>(m, "Metadata")
      .def_readwrite("packets", &Metadata::packets)
      .def(py::pickle(dumpMetadata, loadMetadata));
}

