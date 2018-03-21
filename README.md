# ROS_CV_Video

##Porpurpose
The project mainly uses ROS to compile an image processing program, using the bridge of cv_bridge  
##Compile environment
ubuntu 14.04  ROS-indigo  OpenCV3
##The compiling instruct as fellows  
catkin_make --pkg cv_bridge  
catkin_make  

source ./devel/setup.bash  
rosrun rospitvideo rosseqsub  

open anther terminal  
source ./devel/setup.bash  
rosrun rospitvideo rosseqpub  


