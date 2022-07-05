# This code was written by Nandkshor Motiram Dhawale, PhD and his intern students on Jan 22nd 2021.
# This code is written to display hello on the LCD screen on the lego ev3 platform
# The problem statement was given by my self as the R&D Cell Incharge at P.V.P.I.T Budhgaon, Sangli

from pybricks import ev3brick as brick 
from pybricks.ev3devices import Motor
from pybricks.parameters import Port 
from pybricks.tools import wait 
from pybricks.robotics import DriveBase

# Clear the display
brick.display.clear() # Clear the display
# Print ``Hello`` near the middle of the screen
brick.display.text("Hello", (60, 50))# assign the value and text
# Print ``World`` directly underneath it
brick.display.text("World") #display text
