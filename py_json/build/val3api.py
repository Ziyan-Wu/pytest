from flask import Flask, render_template, redirect
from flask import request

import val3ditypy

app = Flask(__name__)
app.env = 'development'
app.debug = True

@app.route("/create_json", methods=['POST', 'GET'])
def create_json():
    if request.method == 'POST':
        request_data = request.get_json()
        # print(request_data)
        language = request_data['language']
        # return "{}".format(language)
        return 'this is post method'  # why return not works???????????
    return "<p>Welcome to the val3dity server!</p>" \
           "<p> This is /create_json</p>"

# =================================================================================================
@app.route('/validate_cityjson', methods=['POST', 'GET'])
def validate_cityjson():
    if request.method == 'POST':
        request_data = request.get_json()
        # print(val3ditypy.validate_cityjson(request_data))
        if val3ditypy.validate_cityjson(request_data):
            print('validate_cityjson: True')
            return 'True'
        else:
            print('False')
            return 'False'
    else:
        return 'this is /validate_cityjson GET method'


@app.route('/validate_tu3djson', methods=['POST', 'GET'])
def validate_tu3djson():
    if request.method == 'POST':
        request_data = request.get_json()
        res = val3ditypy.validate_tu3djson(request_data)
        # print(type(t))  # list
        # print(res)
        if val3ditypy.validate_tu3djson(request_data) == []:
            print('validate_tu3djson: True')
            return 'True'
        else:
            print('False')
            return 'False'
    else:
        return 'this is /validate_tu3djson GET method'


@app.route('/validate_one_geom', methods=['POST', 'GET'])
def validate_one_geom():
    if request.method == 'POST':
        request_data = request.get_json()
        res = val3ditypy.validate_one_geom(request_data)
        # print(type(t))  # list
        # print(res)
        if val3ditypy.validate_one_geom(request_data):
            print('validate_one_geom: True')
            return 'True'
        else:
            print('False')
            return 'False'
    else:
        return 'this is /validate_one_geom GET method'

# ======================================================================================
@app.route('/validate_arrays', methods=['POST', 'GET'])
def validate_arrays():
    if request.method == 'POST':
        request_data = request.get_json()
        res = val3ditypy.validate_arrays(request_data['type'],request_data['boundaries'],request_data['vertices'])
        if res:
            print('validate_arrays: True')
            return 'True'
        else:
            print('False')
            return 'False'
    else:
        return 'this is /validate_arrays GET method'


if __name__ == '__main__':
    app.run()
