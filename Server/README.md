Server and sensor client for the web application
================================================

Installing
----------

### Python3:

sudo apt-get update

sudo apt-get install python3-pip

sudo python3 -m pip install --upgrade pip setuptools wheel

### Install with pip:

sudo pip install flask

sudo pip install flask_bootstrap

sudo pip install flask_api

Running
-------

### The server is running on a flask server with boostrap. Each sensors will act as a client to update sensor data of the server. The server will update and the client will "PUT" data in a period of 1 second. 
