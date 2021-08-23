import val3ditypy
import json
import numpy as np

'''
open from local path
'''
print("======open from local path======")

# validate_cityjson
path1 = "/home/ziyanwu/data/cityjson/cube.json"
print("use [" + path1 + "] as example:")
with open(path1, 'r') as f:
    cityjson = json.load(f)
print("1.validate cityjson file")
print(val3ditypy.validate_cityjson(cityjson, 0.001, 0.01, 20.0, -1.0))
# with report
cityjson_report = {}
print(val3ditypy.validate_cityjson_jr(cityjson, cityjson_report, 0.001, 0.01, 20.0, -1.0))



# validate_tu3djson
path2 = "/home/ziyanwu/data/cube.json"
print("use [" + path2 + "] as example:")
with open(path2, 'r') as f:
    tu3djson = json.load(f)
print("2.validate tu3djson file")
print(val3ditypy.validate_tu3djson(tu3djson, 0.001, 0.01, 20.0, -1.0))
# with report
tu3djson_report = {}
print(val3ditypy.validate_tu3djson_jr(tu3djson, tu3djson_report, 0.001, 0.01, 20.0, -1.0))



# validate_one_geom
print("3.validate one_geom")
geometry = tu3djson["features"][0]["geometry"]
print(val3ditypy.validate_one_geom(geometry, 0.001, 0.01, 20.0, -1.0))
# with report
one_geom_report = {}
print(val3ditypy.validate_one_geom_jr(geometry, one_geom_report, 0.001, 0.01, 20.0, -1.0))



print('\n')
'''
use list and dictionary create cube_dic then transform to json format
call validate function from val3dity
'''
print("======created file by hand======")
# create file
ls_boundaries = [[[[0, 3, 2, 1]], [[4, 5, 6, 7]], [[0, 1, 5, 4]], [[1, 2, 6, 5]], [[2, 3, 7, 6]], [[3, 0, 4, 7]]]]
ls_vertices = [[0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0], [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]]
cube_dic = {"version": "1.0", "type": "CityJSON", "vertices": ls_vertices,
            "CityObjects": {"id-1": {"type": "GenericCityObject",
                                     "geometry": [{"boundaries": ls_boundaries, "type": "Solid", "lod": 1}]}}}

# validate_cityjson
print("4.validate cityjson file")
print(val3ditypy.validate_cityjson(cube_dic, 0.001, 0.01, 20.0, -1.0))

# lsv_dic = {"vertices": ls_vertices}
# lsb_dic = {"boundaries": ls_boundaries}
# print("validate one_geom (vertices) create by dictionary and list")
# print(val3ditypy.validate_one_geom(lsv_dic, 0.001, 0.01, 20.0, -1.0))
# print("validate one_geom (boundaries) create by dictionary and list")
# print(val3ditypy.validate_one_geom(lsb_dic, 0.001, 0.01, 20.0, -1.0))


# print("jreport",jreport)
# print("type:jreport",type(jreport))