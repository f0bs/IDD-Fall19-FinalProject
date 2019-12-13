# IDD Final Project

**Fabio Daiber** (*github: fpdaiber; discord: Fabio*)

**Ziyu(Ross) Liu** (*github: dlydb; dsicord: ross_lzy*)

**Alan Babushkin** (*github: ababushkin6; discord: alan.babushkin*)


## Ai.re - Monitor body heat emission in rooms and use it as natural heating

### Description

The idea behind the project is to monitor the temperature inside a room using multiple temperature sensors across the room and see how it changes based on body heat emission by tracking of the number of people going in and out of the room.

We use two ultra-sonic sensors at the entrance of an room to detect movement. Based on which sensor is triggered first, we know if people are walking in our out of the room. We have two high-accuracy temperature and humidity sensors spread across the room to track the average room temperature. Both the temperature sensors as well as the ultra-sonic sensors are each connected to a Raspberry Pi that sends the signal wirelessy to our server. 

Our website allows users to input the room size, human activity level in the room and desired temperature. Based on this information, the average temperature and the number of people in the room, we estimate the heat emission caused by the human bodies in the room and calculate the time it takes for the room to heat up to the desired temperature solely based on this emission.

### Initial Design and Paper Prototypes

This is our design schematic: 
![Design Schematic](https://github.com/ababushkin6/IDD-Fall19-FinalProject/blob/master/DDID%20Final%20Project%20Prototype%20Schematic.png)

These are our paper prototype cases for the temperature sensors:

### Microprocessor Devices Used 

The devices that we used to contain our server, run our sensors, and output the data to a website are Raspberry Pi Model 3 B+ boards as well as an Arduino Uno during the testing phase. The boards as well as where they can be obtained are shown below:

*Raspberry Pi Model 3 B+* [Link to Board](https://www.raspberrypi.org/products/raspberry-pi-3-model-b-plus/)

*Arduino Uno Rev3* [Link to Board](https://store.arduino.cc/usa/arduino-uno-rev3)


### Sensors Used & Relevant Codes

[Sensor Information](https://github.com/ababushkin6/IDD-Fall19-FinalProject/tree/master/Sensors)


### Calculate body heat emission

For simplicity, our temperature algorithm on our server  assumes that the room is a closed body of air with perfect insulation. We calculate the temperature difference in Kelvin using the average temperature and the user's desired temperature input. Based on the room size, we calculate the volume and weight of the air in the room and using the specific heat for air, we estimate the required energy need to heat up the room to the desired temperature. Finally, we use the metabolic rate of the selected activity in the room and an average body surface for humans (1.75 square meters) to estimate the body heat production in W and multiply it by the number of people in the room. We adjust for temperature diffusion and calculate the time it takes to heat up the room in hours and mins.

Calculations are based on: [Cornell Unviersity Ergonomics Web](http://ergo.human.cornell.edu/studentdownloads/DEA3500notes/Thermal/thcondnotes.html)


### Key Learnings


### Final presentation

![alt text](https://github.com/ababushkin6/IDD-Fall19-FinalProject/blob/master/IMG_2825%202.jpg)

[Video of the website](https://drive.google.com/open?id=1w4Owynh2kB8nk3H762CxsLngoVftQoUo)
