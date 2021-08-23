#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
namespace py = pybind11;

int add(int i, int j) {
//    printf("C++ being called!! %d %d\n",i,j);
    return i + j;
}

int add_arg(int i, int j) {
    //    printf("C++ being called!! %d %d\n",i,j);
    return i + j;
}

int add_default(int i, int j) {
    //    printf("C++ being called!! %d %d\n",i,j);
    return i + j;
}

int sub(int i, int j) {
    return i - j;
}

bool judge(int num1, int num2){
    if (num1 > num2){
        return true;
    }
    else{ return false;}
}

double dou_add(double a, double b){
    return a+b;
}

// std::string --> can be passed to python
void pass_str(double num, std::string s){
    if (num > 0){
        std::cout << s <<"bigger than 0"<<'\n';
    }
    else{
        std::cout << s <<"smaller than 0"<<'\n';
    }
}

//sum Numpy array --> array can be passed
void sum_array(py::array_t<double> array){
    py::buffer_info buf = array.request();
    double sum = 0;
    double *ptr = static_cast<double *>(buf.ptr);
    for (size_t idx = 0; idx < buf.shape[0] * buf.shape[1]; idx++){
        sum += ptr[idx];
    }
    std::cout << sum <<'\n';
};

//test Numpy-nD

std::vector<int> test_vector(){
    std::vector<int> mod;
    mod.push_back(3);
    mod.push_back(4);
    mod.push_back(5);
    return mod;
}

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



PYBIND11_MODULE(kf_cpp, m) {
    m.doc() = "C++ implementation wrappers"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
    m.def("add_arg", &add_arg, "A function which adds two numbers with args",py::arg("i"), py::arg("j"));
    m.def("add_default", &add_default, "A function which adds two numbers with default",py::arg("i")=8, py::arg("j")=7);
    m.def("new",&dou_add,"test add double type");

    m.def("sub", &sub, "A function which sub two numbers");

    m.attr("age") = 18;
    py::object gender = py::cast("male");
    m.attr("gender") = gender;

    m.def("judge",&judge,"if first number greater the second return True else False");
    m.def("pass_str",&pass_str,"if first number greater the second return True else False");
    m.def("sum_array",&sum_array,"test numpy can be passed?");
    m.def("test_vector",&test_vector,"test vector can be passed?");

    //    m.def("take_json", &take_json, "pass py::object to a C++ function that takes an nlohmann::json");
    //    //py::dictionary to json
    //    m.def("return_json", &return_json, "return py::object from a C++ function that returns an nlohmann::json");
}