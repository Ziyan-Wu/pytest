- [<span id="head1">Develop python extensions for val3dity</span>](#develop-python-extensions-for-val3dity)
  - [<span id="head2"> Tools</span>](#-tools)
  - [<span id="head3">How to use</span>](#how-to-use)
  - [<span id="head4">The fucntions in `pybind11_json.hpp`</span>](#the-fucntions-in-pybind11_jsonhpp)
  - [<span id="head5">Explain `test.py`</span>](#explain-testpy)
- [<span id="head6">Develop flask server</span>](#develop-flask-server)
  - [<span id="head7"> Tool</span>](#-tool)
  - [<span id="head8">How to use</span>](#how-to-use-1)
# <span id="head1">Develop python extensions for val3dity</span>

## <span id="head2"> Tools</span>
use `pybind11 module` https://github.com/pybind/pybind11 

use `pybind11_json.json` make conversion between nlohmann::json and pybind11 Python objects

## <span id="head3">How to use</span>
`mkdir build && cd build`

`cmake .. -DLIBRARY=true` compile val3dity static library

`make`


## <span id="head4">The fucntions in `pybind11_json.hpp`</span>

All functions have default values:
`tol_snap=0.001, planarity_d2p_tol=0.01, planarity_n_tol=20.0, overlap_tol=-1.0`
if needed, can be changed as the way like `tol_snap=0.002`

1. `val3ditypy.validate_cityjson(cityjson)`A function validate cityjson file
2. `val3ditypy.validate_cityjson_jr(cityjson,cityjson_report)`A function validate cityjson file return with report

3. `val3ditypy.validate_one_geom(geometry)` A function validate one geom.
4. `val3ditypy.validate_one_geom_jr(geometry,report)`A function validate one geom return with report.

5. `val3ditypy.validate_tu3djson(tu3djson)`A function validate tu3djson file
6. `val3ditypy.validate_tu3djson_jr(tu3djson,tu3djson_report)`A function validate tu3djson file return with report

7. `val3ditypy.validate_arrays(geom_name, boundaries, vertices)`A function validate boundaries and vertices directly.


## <span id="head5">Explain `test.py`</span>
`test.py` need to be moved to build file and run in terminal with `python3 test.py`

* The python package name is `val3ditypy`, use like `import val3ditypy`
* You can pass json file from local path(example 1-2-3) or create dictionary object(example 4) and pass it.
* You can also create boundaries and vertices list(example 5) and validate them with `val3ditypy.validate_arrays()`.
* Example 1-2-3 also generate and store a validation report in json format, call with `val3ditypy.validate_cityjson_jr()`.

# <span id="head6">Develop flask server</span>

## <span id="head7"> Tool</span>
use `flask` python package


## <span id="head8">How to use</span>
inside `build` file, run with terminal 1 and terminal 2
1. `python3 val3api.py`
2. `python3 flask_test.py`

The data in `flask_test.py` will be sent to flask server with `POST` method, then do the validation.
And the result will show in terminal 1.
