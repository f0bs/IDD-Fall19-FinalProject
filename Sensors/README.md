# Sensor Codes

The two types of sensors that we used are two ultrasonic sensors as well as two different models of temperature sensors.

**Temperature Sensors (initial):** DHT 11   x2

**Temperature Sensors (final):** DHT 22   x2

**Ultrasonic Sensors:** HC-SR04   x2

### Temperature Sensors

The temperature sensors were used to determine the temperature and humidity of the room. They were strategically placed to cover the whole room to make our algorithm more accurate. The sensors were initally a lower quality sensor that was used for proof of concept. After the testing was completed the temperature sensors were upgraded to significantly more accurate and precise ones. They were directly tested on the raspberry pi so no recoding was needed. The code used for these sensors is below. 

[Raspberry Pi Final Code](https://github.com/ababushkin6/IDD-Fall19-FinalProject/blob/master/Server/idd-master/examples/simpletest.py)

### Ultrasonic Sensors

The ultrasonic sensors were used to determine the personel count inside the room. Using the two ultrasonic sensors in tandem we were able to determine if someone is entering or exiting the room; in so keeping track of the number of people inside. Depending on which ultrasonic is tripped first, the second enters a while-loop of readings untill someone crosses its path at which point, depending on the order, the count of people in the room is either raised or lowered.

The sensors were initially tested on an Arduino Uno. After many iterations and testing the final developed code was as follows.

[Final Arduino Code after Development](https://github.com/ababushkin6/IDD-Fall19-FinalProject/blob/master/Sensors/UltrasonicCounter_to_Pi.ino)

After this, the code was recoded and transferred to a raspberry pi. The code used for this final stage is below.

[Raspberry Pi Final Code]()


