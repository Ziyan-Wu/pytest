import val3ditypy
import json
import numpy as np

'''
use c++ function in python
'''
# val3dity
path = "/home/ziyanwu/data/cityjson/cube.json"
with open(path, 'r') as f:
    cityjson = json.load(f)
print('type(cityjson): ', type(cityjson))
# print('cityjson: ', cityjson)
# take = val3ditypy.take_json(cityjson)
# print('type(take): ', type(take))
j = val3ditypy.return_json(cityjson)
# print('j:', j)
# print('type(j): ', type(j))
print("open file from local path as json")
print(val3ditypy.validate_cityjson(j, 0.001, 0.01, 20.0, -1.0))

# val3ditypy.np2json ---> failed
# vertices = np.array([[0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0], [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]])
# print('vertices:\n', vertices)
# v_dic = {"vertices": vertices}
# print('v_dic:\n', v_dic)
# val3ditypy.np2json(vertices,"vertices")



'''
use list and dictionary create cube_dic then transform to json format
call validate function from val3dity
'''
ls_boundaries = [[[[0, 3, 2, 1]], [[4, 5, 6, 7]], [[0, 1, 5, 4]], [[1, 2, 6, 5]], [[2, 3, 7, 6]], [[3, 0, 4, 7]]]]
ls_vertices = [[0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0], [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]]
# lsv_dic = {"vertices": ls_vertices}
# lsb_dic = {"boundaries":ls_boundaries}
cube_dic = {"version": "1.0", "type": "CityJSON", "vertices": ls_vertices,
            "CityObjects": {"id-1": {"type": "GenericCityObject",
                                     "geometry": [{"boundaries": ls_boundaries, "type": "Solid", "lod": 1}]}}}
# print("cube_dic:\n", cube_dic)
j_cude = val3ditypy.return_json(cube_dic)
# print(j_cude)
print("create json with dictionary and list")
print(val3ditypy.validate_cityjson(j_cude, 0.001, 0.01, 20.0, -1.0))

# j_lsv = val3ditypy.return_json(lsv_dic)
# print('j_lsv: \n', j_lsv)
# print(val3ditypy.validate_one_geom(j_lsv, 0.001, 0.01, 20.0, -1.0))
