# IDD Final Project

**Fabio Daiber** (*github: fpdaiber; discord: Fabio*)

**Ziyu(Ross) Liu** (*github: dlydb; dsicord: ross_lzy*)

**Alan Babushkin** (*github: ababushkin6; discord: alan.babushkin*)


## Ai.re - optimized room temperature in large spaces

### Description

The idea behind the project is the monitor the temperature inside a room using multiple temperature sensors across the room and track of the number of people going in and out of the room. This is then used to create a optimal value for the thermostat to set the temperature to. People in the room can log into a website and then enter whether they are too hot or too cold as well as what temperatures they are comfortable with. 

### Initial Design

![Design Schematic](https://github.com/ababushkin6/IDD-Fall19-FinalProject/blob/master/DDID%20Final%20Project%20Prototype%20Schematic.png)

### Codes Used

The following is a link to the explaination of the sensors used, how they were utilized and the codes that were written for each respective sensor. 

[Sensor Information](https://github.com/ababushkin6/IDD-Fall19-FinalProject/tree/master/Sensors)

### Calculate optimal room temperature

Using the heat emission per person and calculate room heat emission (people x human emission + people x laptop emission)
User input: room size
Calculate optimal temperature based on this

http://ergo.human.cornell.edu/studentdownloads/DEA3500notes/Thermal/thcondnotes.html

Website shows: 
- 2-3 temp sensors individual temperature 
- combined average temperature
- people in the room (interactive: in and out)
- currently set HVAC setting for the room


