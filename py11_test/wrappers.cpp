#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
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
}