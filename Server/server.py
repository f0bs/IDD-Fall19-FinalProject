from flask import Flask, render_template, request, jsonify
from flask_bootstrap import Bootstrap
import time
from flask_api import FlaskAPI

app = FlaskAPI(__name__)
Bootstrap(app)

data = {'tem1': '0',
		'hum1': '0',
		'tem2': '0',
		'hum2': '0',
		'num': '0',
		'room': '0', 
		'desired_tmp': '0', 
		'hour': '0',
		'l': '0', 
		'w': '0',
		't': '0',
		'act': '1'}

act = 0

@app.route('/', methods = ['GET'])
def index():
	return render_template('index.html', data = data)

@app.route('/<int:sensor_id>', methods = ['PUT'])
def update(sensor_id):
	sensor = sensor_id
	if sensor == 0:
		num = request.data.get('num', '')
		data['num'] = num
	else:
		if sensor == 1:
			tem = float(request.data.get('tem', '')) * 9/5 + 32
			hum = float(request.data.get('hum', ''))
			data['tem1'] = str(round(tem, 2))
			data['hum1'] = str(round(hum, 2))
		else:
			tem = float(request.data.get('tem', '')) * 9/5 + 32
			hum = float(request.data.get('hum', ''))
			data['tem2'] = str(round(tem, 2))
			data['hum2'] = str(round(hum, 2))
	return jsonify(data)

@app.route('/sensor1')
def refresh1():
	return '<a class=/"alert-link/" font size=/"6"> Sensor1: Temperature: ' + data['tem1'] + ' F, Humidity: ' + data['hum1'] + '% </a>' 

@app.route('/sensor2')
def refresh2():
		return '<a class=/"alert-link/"> Sensor2: Temperature: ' + data['tem2'] + ' F, Humidity: ' + data['hum2'] + '% </a>' 

@app.route('/sensor3')
def refresh3():
	return '<a class=/"alert-link/"> There are ' + data['num'] + ' of people inside the room </a>'

@app.route('/refresh')
def refresh():
	l = float(data['l'])
	w = float(data['w'])
	t = float(data['t'])
	act = float(data['act'])

	act = float(act) * 101.85 * (int(data['num']) + 1) / 1000.0 #in kJ per s
	cubic = float(l)*0.3048 * float(w)*0.3048 * 3.25
	heat_required = cubic * 1.2005 * 1.006 # kJ/kg K

	tem_dif = ((t - (float(data['tem1']) + float(data['tem2']))/2)) * 5/9

	min_time_need = heat_required * 4 / act / 60 * tem_dif #in mins
	hour = min_time_need / 60

	data['room'] = str(round(cubic, 2))
	data['desired_tmp'] = str(round(t, 2))
	data['hour'] = str(round(hour, 2))

	return '<a class=/"alert-link/""> Time needed for people to heat up room: ' + data['hour'] + ' hours </a>'

@app.route('/handle_data', methods=['POST'])
def handle_data():
	l = request.form['leng']
	w = request.form['width']
	t = float(request.form['tmp'])

	data['l'] = l
	data['w'] = w
	data['t'] = str(t)
	data['act'] = request.form['act']

	act = float(data['act']) * 101.85 * (int(data['num']) + 1) / 1000.0 #in kJ per s
	cubic = float(l)*0.3048 * float(w)*0.3048 * 3.25
	heat_required = cubic * 1.2005 * 1.006 # kJ/kg K

	tem_dif = ((t - (float(data['tem1']) + float(data['tem2']))/2)) * 5/9


	min_time_need = heat_required * 4 / act / 60 * tem_dif #in mins
	hour = min_time_need / 60

	print(hour, min_time_need)

	data['room'] = str(round(cubic, 2))
	data['desired_tmp'] = str(round(t, 2))
	data['hour'] = str(round(hour, 2))

	return render_template('index.html', data=data)


if __name__ == '__main__':
	app.run(debug=True)