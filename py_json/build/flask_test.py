import json
import val3ditypy
import requests

print("=============================== create_json/j ====================================================")

j = {"language": "French", "hugo": [1, 2, 4]}
# print(j)

r = requests.post('http://127.0.0.1:5000/create_json', json=j)
print(r.url)
print(r.status_code)
# print(r.request)  # <PreparedRequest [POST]>
# print(r.text)  # French
# print(r.json)  # <bound method Response.json of <Response [200]>>

print("=============================== local_path/cityjson ====================================================")
# cityjson
cityjson_path = '/home/ziyanwu/data/cityjson/cube.json'
with open(cityjson_path, 'r') as f:
    cityjson = json.load(f)
c = requests.post('http://127.0.0.1:5000/validate_cityjson', json=cityjson)
print(c.url)
print(c.status_code)

# tu3djson
tu3djson_path = "/home/ziyanwu/data/cube.json"
with open(tu3djson_path, 'r') as f:
    tu3djson = json.load(f)
t = requests.post('http://127.0.0.1:5000/validate_tu3djson', json=cityjson)
print(t.url)
print(t.status_code)


# ===================================================================================
print("============================= /pybind11 ======================================================")

# boundaries = [[[0,3,2,1]],[[4,5,6,7]],[[0,1,5,4]],[[1,2,6,5]],[[2,3,7,6]],[[3,0,4,7]]]
# vertices = [[0.0,0.0,0.0],[1.0,0.0,0.0],[1.0,1.0,0.0],[0.0,1.0,0.0],
#             [0.0,0.0,1.0],[1.0,0.0,1.0],[1.0,1.0,1.0],[0.0,1.0,1.0]]
# print(val3ditypy.validate_arrays("Solid",boundaries,vertices))

# d = requests.post('http://127.0.0.1:5000/com', json=cityjson)
# print(d.url)
# print(d.text)
# print(d)
# print(d.status_code)

print("============================= end ======================================================")

# path = "/home/ziyanwu/data/cityjson/cube.json"
# with open(path, 'r') as f:
#     cityjson = json.load(f)