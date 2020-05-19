"""
Author: Gerald Addo-Tetteh
The code recieves dat from an arduino
and uses it to control the length of
the virtual cylinder
"""

import serial
from vpython import *

#change the port to be the same as yours
arduino_data = serial.Serial("com4",9600)
measuring_rod = cylinder(length = 6, color = color.yellow, raduis = .001,
	pos = vector(-3,-2,0))
label_length = label(text = "The length of the rod is: ", 
	pos = vector(2,3,3), height = 15, box = None)
target = box(color = color.green,length = 0.2,width = 4,
	 pos = vector(0,0,0),height = 6)

#changes the length of the cylinder based
#on the input from the arduino.
while True :
	rate(20)
	if arduino_data.in_waiting > 0 :
		distance = eval(arduino_data.readline())
		text = "The length of the rod is: " + str(distance)
		print(distance)
		measuring_rod.length = distance
		label_length.text = text
		target.pos.x = -3 + distance
