# This code was written by Nandkshor Motiram Dhawale, PhD and his intern students on Jan 22nd 2021.
# This code is written create sound "beep" on the lego ev3 platform
# The problem statement was given by my self as the R&D Cell Incharge at P.V.P.I.T Budhgaon, Sangli

from pybricks import ev3brick as brick # import pybricks library 
from pybricks.ev3devices import Motor # import motor 
from pybricks.parameters import Port # import port
# Play a sound.
brick.sound.beep()# hear a sound
# Initialize a motor at port B.
test_motor = Motor(Port.B)# motor is initialized
# Run the motor up to 500 degrees per second. To a target angle of 90 degrees.
test_motor.run_target(500, 90)
# Play another beep sound.
# This time with a higher pitch (1000 Hz) and longer duration (500 ms).
brick.sound.beep(1000, 500)# hear a another longer beep 
