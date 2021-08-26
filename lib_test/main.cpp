#include "val3dity.h"
#include "nlohmann-json/json.hpp"
#include <fstream>

using json = nlohmann::json;


int main(int argc, char *argv[]) {

    std::vector<std::vector<double >> vertices;
    std::vector<double> v1;
    v1.push_back(0.0);
    v1.push_back(0.0);
    v1.push_back(0.0);
    std::vector<double> v2;
    v2.push_back(1.0);
    v2.push_back(0.0);
    v2.push_back(0.0);
    std::vector<double> v3;
    v3.push_back(1.0);
    v3.push_back(1.0);
    v3.push_back(0.0);
    std::vector<double> v4;
    v4.push_back(0.0);
    v4.push_back(1.0);
    v4.push_back(0.0);
    std::vector<double> v5;
    v5.push_back(0.0);
    v5.push_back(0.0);
    v5.push_back(1.0);
    std::vector<double> v6;
    v6.push_back(1.0);
    v6.push_back(0.0);
    v6.push_back(1.0);
    std::vector<double> v7;
    v7.push_back(1.0);
    v7.push_back(1.0);
    v7.push_back(1.0);
    std::vector<double> v8;
    v8.push_back(0.0);
    v8.push_back(1.0);
    v8.push_back(1.0);
    vertices.push_back(v1);vertices.push_back(v2);vertices.push_back(v3);vertices.push_back(v4);
    vertices.push_back(v5);vertices.push_back(v6);vertices.push_back(v7);vertices.push_back(v8);

    std::vector<std::vector<std::vector<int>>> boundaries;
    std::vector<int> b1 {0,3,2,1};std::vector<std::vector<int>> b11;b11.push_back(b1);
    std::vector<int> b2 {4,5,6,7};std::vector<std::vector<int>> b22;b22.push_back(b2);
    std::vector<int> b3 {0,1,5,4};std::vector<std::vector<int>> b33;b33.push_back(b3);
    std::vector<int> b4 {1,2,6,5};std::vector<std::vector<int>> b44;b44.push_back(b4);
    std::vector<int> b5 {2,3,7,6};std::vector<std::vector<int>> b55;b55.push_back(b5);
    std::vector<int> b6 {3,0,4,7};std::vector<std::vector<int>> b66;b66.push_back(b6);
    boundaries.push_back(b11);boundaries.push_back(b22);boundaries.push_back(b33);
    boundaries.push_back(b44);boundaries.push_back(b55);boundaries.push_back(b66);

    bool re = val3dity::validate_arrays("Solid",boundaries,vertices);

    // std::ifstream input("/Users/hugo/data/tu3djson/cube.json");
//    std::ifstream input("/home/ziyanwu/data/cube.json");
//    // std::ifstream input("/Users/hugo/data/cityjson/examples/delft/v100/a2.json");
//    json j;
//    try {
//        input >> j;
//    }
//    catch (nlohmann::detail::parse_error e) {
//        std::cerr << "Input file not a valid JSON file." << std::endl;
//        return 0;
//    }

    // if (j["type"] != "CityJSON") {
    //   std::cerr << "Input file not a valid JSON file." << std::endl;
    //   return 0;
    // }

//    json jr;
//     bool re = val3dity::validate_one_geom(j["features"][0]["geometry"], jr);
//     std::cout << jr << std::endl;

//     bool re = val3dity::validate_one_geom(j["features"][0]["geometry"]);
//     std::vector<bool> re = val3dity::validate_tu3djson(j);
    // std::vector<bool> re = val3dity::validate_tu3djson(j, jr);
    // std::cout << jr << std::endl;
    // std::ofstream o("/Users/hugo/temp/r.json");
    // o << jr.dump(2) << std::endl;
    // bool re = val3dity::validate_cityjson(j);
//    bool re = val3dity::validate_cityjson(j, jr);

//     std::for_each(re.begin(), re.end(), [](const bool n) { std::cout << n << std::endl; });
    if (re == true)
        std::cout << "VALID" << std::endl;
    else
        std::cout << "INVALID :(" << std::endl;


    return 0;
}
