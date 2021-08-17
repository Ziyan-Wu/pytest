#include <pybind11/pybind11.h>
//#include <val3dity.h>
//#include "nlohmann-json/json.hpp"
//#include <fstream>

//using json = nlohmann::json;
//namespace py = pybind11;

int add(int i, int j) {
//    printf("C++ being called!! %d %d\n",i,j);
    return i + j;
}

int sub(int i, int j) {
    return i - j;
}

//bool vc(json& j,
//        double tol_snap=0.001,
//        double planarity_d2p_tol=0.01,
//        double planarity_n_tol=20.0,
//        double overlap_tol=-1.0){
//    return val3dity::validate_cityjson(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
//}

// first: module name
PYBIND11_MODULE(kf_cpp, m) {
    m.doc() = "C++ implementation wrappers"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
    m.def("sub", &sub, "A function which sub two numbers");

//    m.def("validate_cityjson", &vc, "A function validate cityjson",
//            py::arg("j"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
//            py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=1.0
//            );
}