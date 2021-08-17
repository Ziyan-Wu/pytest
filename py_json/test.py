import kf_cpp
import json

# val3dity
path = "/home/ziyanwu/data/cityjson/cube.json"
with open(path, 'r') as f:
    cityjson = json.load(f)
print('type(cityjson): ', type(cityjson))

take = kf_cpp.take_json(cityjson)
print('type(take): ', type(take))

j = kf_cpp.return_json(cityjson)
print('j:', j)
print('type(j): ', type(j))

print(kf_cpp.vc(j,0.001,0.01,20.0,-1.0))