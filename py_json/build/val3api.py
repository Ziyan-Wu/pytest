import json
import os
import subprocess
import time
import uuid


from flask import Flask, render_template, redirect
from flask import request
from werkzeug.utils import secure_filename

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
        return "{}".format(language)
        # return 'True'
    return "<p>Welcome to the val3dity server!</p>" \
           "<p> This is /create_json</p>"


@app.route('/validate_cityjson', methods=['POST', 'GET'])
def validate_cityjson():
    if request.method == 'POST':
        request_data = request.get_json()
        print(val3ditypy.validate_cityjson(request_data))
        if val3ditypy.validate_cityjson(request_data):
            return 'True'
        else:
            return 'False'
    else:
        return 'this is /validate_cityjson GET method'


@app.route('/validate_tu3djson', methods=['POST', 'GET'])
def validate_tu3djson():
    if request.method == 'POST':
        request_data = request.get_json()
        t = val3ditypy.validate_tu3djson(request_data)
        print(type(t))
        print(val3ditypy.validate_tu3djson(request_data))
        return 'True'
        # if val3ditypy.validate_tu3djson(request_data) == []:
        #     print('Hello')
        #     return 'True'
        # else:
        #     print('Hello jokkokok')
        #     return 'False'
    else:
        return 'this is /validate_tu3djson GET method'


if __name__ == '__main__':
    app.run()
