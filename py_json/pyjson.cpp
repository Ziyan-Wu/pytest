#include <val3dity.h>
#include "nlohmann-json/json.hpp"
using json = nlohmann::json;
#include <fstream>

#include <pybind11/pybind11.h>
#include "pybind11_json.hpp"
namespace py = pybind11;

void take_json(const json& s) {
    std::cout << "This function took an nlohmann::json instance as argument: " << s << std::endl;
}

json return_json(py::dict obj) {
    json j = obj;

//    std::cout << "This function returns an nlohmann::json instance: "  << j << std::endl;
//    std::cout << "This function returns an nlohmann::json instance: " << std::endl;
    return j;
}

bool validate_cityjson(json& j,
        double tol_snap=0.001,
        double planarity_d2p_tol=0.01,
        double planarity_n_tol=20.0,
        double overlap_tol=-1.0){
    return val3dity::validate_cityjson(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
}

PYBIND11_MODULE(val3ditypy, m) {
    m.doc() = "My awesome module";

    m.def("take_json", &take_json, "pass py::object to a C++ function that takes an nlohmann::json");
    m.def("return_json", &return_json, "return py::object from a C++ function that returns an nlohmann::json");
    //val3dity
    m.def("validate_cityjson", &validate_cityjson, "A function validate cityjson",
          py::arg("j"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0
                  );
}