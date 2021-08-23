#include <val3dity.h>
#include "nlohmann-json/json.hpp"
using json = nlohmann::json;
#include <fstream>

#include <pybind11/pybind11.h>
#include "pybind11_json.hpp"
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
namespace py = pybind11;

//void take_json(const json& s) {
//    std::cout << "This function took an nlohmann::json instance as argument: " << s << std::endl;
//}

//json return_json(py::dict obj) {
//    json j = obj; // combine them
//
//    std::cout << "This function returns an nlohmann::json instance: "  << j << std::endl;
//    std::cout << "This function returns an nlohmann::json instance: " << std::endl;
//    return j;
//}

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

//validate_one_geom
bool validate_one_geom(py::dict obj,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    return val3dity::validate_one_geom(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
}

bool validate_one_geom_jr(py::dict obj, py::dict jr,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    json jreport = jr;
    bool re = val3dity::validate_one_geom(j,jreport,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
    std::cout << jreport << "\n";

    std::ofstream o("validate_one_geom_report.json");
    o << std::setw(4) << jreport << std::endl;

    return re;
}


//validate_cityjson
bool validate_cityjson(py::dict obj,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj; //create a nlohmann::json instance
    return val3dity::validate_cityjson(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
}

bool validate_cityjson_jr(py::dict obj, py::dict jr,
                          double tol_snap=0.001,
                          double planarity_d2p_tol=0.01,
                          double planarity_n_tol=20.0,
                          double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    json jreport = jr;
    bool re = val3dity::validate_cityjson(j,jreport,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
    std::cout << jreport << "\n";

    std::ofstream o("validate_cityjson_report.json");
    o << std::setw(4) << jreport << std::endl;

    return re;
}


//validate_tu3djson
std::vector<bool> validate_tu3djson(py::dict obj,
                       double tol_snap=0.001,
                       double planarity_d2p_tol=0.01,
                       double planarity_n_tol=20.0,
                       double overlap_tol=-1.0){
    json j = obj; //create a nlohmann::json instance
    return val3dity::validate_tu3djson(j,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
}

bool validate_tu3djson_jr(py::dict obj, py::dict jr,
                          double tol_snap=0.001,
                          double planarity_d2p_tol=0.01,
                          double planarity_n_tol=20.0,
                          double overlap_tol=-1.0){
    json j = obj;//create a nlohmann::json instance
    json jreport = jr;
    bool re = val3dity::validate_tu3djson(j,jreport,tol_snap,planarity_d2p_tol,planarity_n_tol,overlap_tol);
    std::cout << jreport << "\n";

    std::ofstream o("validate_tu3djson_report.json");
    o << std::setw(4) << jreport << std::endl;

    return re;
}




PYBIND11_MODULE(val3ditypy, m) {
    m.doc() = "My awesome module";

//    m.def("take_json", &take_json, "pass py::object to a C++ function that takes an nlohmann::json");
//    //py::dictionary to json
//    m.def("return_json", &return_json, "return py::object from a C++ function that returns an nlohmann::json");
//    //transform numpy to json
    m.def("np2json", &np2json, "return py::numpy from a C++ function that returns an nlohmann::json");

    //validate_cityjson
    m.def("validate_cityjson", &validate_cityjson, "A function validate cityjson",
          py::arg("cityjson"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);

    m.def("validate_cityjson_jr", &validate_cityjson_jr, "A function validate cityjson file back with report",
          py::arg("cityjson"),  py::arg("jreport"), py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);


    //validate_tu3djson
    m.def("validate_tu3djson", &validate_tu3djson, "A function validate tu3djson",
          py::arg("tu3djson"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);

    m.def("validate_tu3djson_jr", &validate_one_geom_jr, "A function validate tu3djson back with report",
          py::arg("geometry"),  py::arg("jreport"), py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);


    //validate_one_geom
    m.def("validate_one_geom", &validate_one_geom, "A function validate one geom",
          py::arg("geometry"),  py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);

    m.def("validate_one_geom_jr", &validate_one_geom_jr, "A function validate one geom back with report",
          py::arg("geometry"),  py::arg("jreport"), py::arg("tol_snap")=0.001,py::arg("planarity_d2p_tol")=0.01,
          py::arg("planarity_n_tol")=20.0,py::arg("overlap_tol")=-1.0);
}