import json
import requests



print("=============================== local_path ====================================================")
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


# validate_one_geom
one_geom = tu3djson["features"][0]["geometry"]
o = requests.post('http://127.0.0.1:5000/validate_one_geom', json=cityjson)
print(o.url)
print(o.status_code)


# ===================================================================================
print("=========================== created file by hand =============================")
# create file
ls_boundaries = [[[[0, 3, 2, 1]], [[4, 5, 6, 7]], [[0, 1, 5, 4]], [[1, 2, 6, 5]], [[2, 3, 7, 6]], [[3, 0, 4, 7]]]]
ls_vertices = [[0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0], [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]]
cube_dic = {"version": "1.0", "type": "CityJSON", "vertices": ls_vertices,
            "CityObjects": {"id-1": {"type": "GenericCityObject",
                                     "geometry": [{"boundaries": ls_boundaries, "type": "Solid", "lod": 1}]}}}

# validate_cityjson
cu = requests.post('http://127.0.0.1:5000/validate_cityjson', json=cityjson)
print(cu.url)
print(cu.status_code)


# ===================================================================================
print("======================== created boundaries and vertices by hand ==========================")
boundaries = [[[0,3,2,1]],[[4,5,6,7]],[[0,1,5,4]],[[1,2,6,5]],[[2,3,7,6]],[[3,0,4,7]]]
vertices = [[0.0,0.0,0.0],[1.0,0.0,0.0],[1.0,1.0,0.0],[0.0,1.0,0.0],
            [0.0,0.0,1.0],[1.0,0.0,1.0],[1.0,1.0,1.0],[0.0,1.0,1.0]]
temp = {'type':"Solid",'boundaries':boundaries,'vertices':vertices}
# validate only with boundaries and vertices
a = requests.post('http://127.0.0.1:5000/validate_arrays', json=temp)
print(a.url)
print(a.status_code)


print("============================= end ======================================================")
