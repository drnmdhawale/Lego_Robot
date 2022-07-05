# This code was written by Nandkshor Motiram Dhawale, PhD and his intern students on Jan 22nd 2021.
# This code is written to display smily eye on the display of the lego ev3 platform
# The problem statement was given by my self as the R&D Cell Incharge at P.V.P.I.T Budhgaon, Sangli

from pybricks import ev3brick as brick 
from pybricks.ev3devices import Motor, UltrasonicSensor 
from pybricks.parameters import Port 
from pybricks.tools import wait 
from pybricks.robotics import DriveBase

# Show a built-in image of two eyes looking upward
brick.display.image(ImageFile.UP)# create a two eyes looking upward image 
# Display a custom image from your project folder
brick.display.image('pybricks.png')
# Display a custom image at the top right of the screen, without clearing
# the screen first
brick.display.image('arrow.png', Align.TOP_RIGHT, clear=False)# Display a custom image and align to the top right custom image
