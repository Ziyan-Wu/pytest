#include <val3dity.h>
#include "nlohmann-json/json.hpp"
using json = nlohmann::json;
#include <fstream>

#include <pybind11/pybind11.h>
#include "pybind11_json.hpp"
#include <pybind11/numpy.h>
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

void sum_array(py::array_t<double> array){
    py::buffer_info buf = array.request();
    double sum = 0;
    double *ptr = static_cast<double *>(buf.ptr);
    for (size_t idx = 0; idx < buf.shape[0] * buf.shape[1]; idx++){
        sum += ptr[idx];
    }
    std::cout << sum <<'\n';
};


void np2json(py::array_t<double> array, std::string type){
//    json j;
//    j[type] = array;  // Error: json not accept this type
    json j2 = {
            {"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {
                {"everything", 42}
            }},
            {"list", {1, 0, 2}},
//            {"array",{array}},  // Error:
            {"object", {
                {"currency", "USD"},
                {"value", 42.99}
            }}
            };
    std::cout<<j2<<'\n';
}

//bool validate_with_numpy(numpy&np; std::string s1
//                        double tol_snap=0.001,
//                        double planarity_d2p_tol=0.01,
//                        double planarity_n_tol=20.0,
//                        double overlap_tol=-1.0){
//    json j;
//    j[s1] = np;
//    return val3dity::validate_one_geom(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
//}

bool validate_one_geom(json& j,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    return val3dity::validate_one_geom(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
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
    //py::dictionary to json
    m.def("return_json", &return_json, "return py::object from a C++ function that returns an nlohmann::json");
    //transform numpy to json
    m.def("np2json", &np2json, "return py::numpy from a C++ function that returns an nlohmann::json");
    //val3dity
    m.def("validate_cityjson", &validate_cityjson, "A function validate cityjson",
          py::arg("j"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0
                  );
    m.def("validate_one_geom", &validate_one_geom, "A function validate cityjson",
          py::arg("j"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0
                  );
}