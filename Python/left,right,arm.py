# Initialize a motor (by default this means clockwise, without any gears). 
example_motor = Motor(Port.A) #initialize left motor Form Port A
# Initialize a motor where positive speed values should go counterclockwise 
right_motor = Motor(Port.B, Direction.COUNTERCLOCKWISE) #initialize right motor Form Port B with CounterClockwise Direction
# Initialize a motor with a gear train 
robot_arm = Motor(Port.C, Direction.CLOCKWISE, [12, 36])#initialize robot arm Form Port C with Clockwise Direction


# Set the maximum speed to 200 deg/s and acceleration to 400 deg/s/s.
 example_motor.set_run_settings(200, 400) 
# Make the motor run for 5 seconds. Even though the speed argument is 300 # deg/s in this example, the motor will move at only 200 deg/s because of # the settings above. 
example_motor.run_time(300, 5000)