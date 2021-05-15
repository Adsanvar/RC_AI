#Visualization Package

##Overview
This package will contain all needed vehicle models and RVIZ configuration files needed to visualize the vehicle driving as well as applicable sensor data.

###URDF
URDF models are contained in a file that follows the XML format.
In this file you can specify link elements that describe a rigid body with an inertia, visual features, and collision properties. Link and joint kinematic properties can be grouped together into a robot model.

In <link> section, we have visual, inertial, and collision sections.

###Xacros
This package utilizes urdf xacros to create a visual model of a vehicle for simulation.

This is an extension for urdf

###TF Frames

The vehicle model will have the following links below:

* base_link
  First link of the vehicle. Its the most visual component. All other links will use base_link as reference. It is set to origin of the world.

* wheel_rr
* wheel_rl
* wheel_fr
* wheel_fl
* wheel_rr
