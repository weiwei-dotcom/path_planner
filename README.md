# Quick Start
Compiling tests passed on ubuntu 20.04** with ros2 installed.
You can just execute the following commands one by one.
```
git clone https://github.com/weiwei-dotcom/path_planner.git
cd path_planner
colcon build
source install/setup.bash
ros2 launch path_planner.launch.py
```
If you find this work useful or interesting, please kindly give us a star :star:, thanks!:grinning:

# Acknowledgements
- The framework of this repository is based on [Ego-Planner](https://github.com/weiwei-dotcom/ego-planner) by Xin Zhou who achieves impressive proformance on quadrotor local planning.

- The Ceres solver we use is from [Ceres Solver](http://ceres-solver.org/installation.html), which is lightweight and easy to use.


# This is an ESDF-free Gradient-based Local Planner for CDCR path follow motion.
The core code is in the path_planner package, which is the src code of the path planner node. By calling the path planning service to the node and passing in the start point and end point position and speed information of the path planning, the function package plans the obstacle avoidance path information and returns all control points, order and time node vectors of the quasi-uniform B-spline curve path.

![2024-03-15_20-54](https://github.com/weiwei-dotcom/path_planner/assets/62756096/40e6bd04-7196-4e3c-b4ae-51b39dc93b83) 
![实验平台路径规划图片](https://github.com/weiwei-dotcom/path_planner/assets/62756096/ed72b3c4-462c-4f53-968f-49e9ef3a287b)
