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

# take = val3ditypy.take_json(cityjson)
# print('type(take): ', type(take))

j = val3ditypy.return_json(cityjson)
# print('j:', j)
# print('type(j): ', type(j))

print(val3ditypy.validate_cityjson(j, 0.001, 0.01, 20.0, -1.0))




vertices = np.array([[0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0], [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]])
# print('vertices:\n', vertices)
v_dic = {"vertices": vertices}
print('v_dic:\n', v_dic)
val3ditypy.np2json(vertices,"vertices")


ls_vertices = [[0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0], [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]]
lsv_dic = {"vertices": ls_vertices}
print('lsv_dic:\n', lsv_dic)
# print('type(v_dic): ', type(v_dic))
j_lsv = val3ditypy.return_json(lsv_dic)
print('j_lsv: \n', j_lsv)
print(val3ditypy.validate_one_geom(j_lsv, 0.001, 0.01, 20.0, -1.0))
