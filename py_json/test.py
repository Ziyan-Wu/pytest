import val3ditypy
import json

# val3dity
path = "/home/ziyanwu/data/cityjson/cube.json"
with open(path, 'r') as f:
    cityjson = json.load(f)
print('type(cityjson): ', type(cityjson))

take = val3ditypy.take_json(cityjson)
print('type(take): ', type(take))

j = val3ditypy.return_json(cityjson)
print('j:', j)
print('type(j): ', type(j))

print(val3ditypy.validate_cityjson(j,0.001,0.01,20.0,-1.0))