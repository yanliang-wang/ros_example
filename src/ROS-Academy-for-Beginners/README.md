# <center>《机器人操作系统入门》课程代码示例</center>

---

## 前前言

非常好的ROS入门及中级教程，初学者可以学习基本操作，中级选手可以学习如何使用ROS从仿真开始搭建一个机器人，到使用slam算法建图，再到使用navigation进行导航的过程。

fork from:https://github.com/DroidAITech/ROS-Academy-for-Beginners，我自己加了一些学习时的注释

有配套的讲义：

​	github版：https://github.com/DroidAITech/ROS-Academy-for-Beginners-Book-Melodic

​	gitbook版：https://sychaichangkun.gitbooks.io/ros-tutorial-icourse163/content/

网上也有相对应视频教程

## 前言

欢迎来到中国大学MOOC---[**《机器人操作系统入门》**](https://www.icourse163.org/)课程，本ROS软件包是课程的代码示例，课程中使用的例子均出自本代码包。除了代码包，课程还提供[讲义](https://sychaichangkun.gitbooks.io/ros-tutorial-icourse163/content/)，欢迎各位朋友下载、学习和分享。

本示例包含了XBot机器人和中科院软件博物馆仿真、ROS通信示例程序、导航与SLAM功能演示，在每个软件包下都有相应的功能介绍。

![Gazebo仿真效果](./robot_sim_demo.gif)

如果你遇到任何问题，可以在Github上方的issues栏目中提问，我们课程团队会耐心回答。本示例将**长期维护**，**不断更新**，如果你认可我们的工作，请点击右上角的**star**按钮，您的鼓励是我们的动力。


---
## 示例介绍
本仓库为ROS入门教程的代码示例，包括以下ROS软件包:

| 软件包 | 内容 |
| :--- | :----: |
| **robot_sim_demo** | 机器人仿真程序，大部分示例会用到这个软件包 |
| **topic_demo** | topic通信，自定义msg，包括C++和python两个版本实现 |
| **service_demo** | service通信，自定义srv，分别以C++和python两种语言实现 |
| **action_demo** | action通信，自定义action，C++语言实现 |
| **param_demo** | param操作，分别以C++和python两种语言实现 |
| **msgs_demo** | 演示msg、srv、action文件的格式规范 |
| **tf_demo** | tf相关API操作演示，tf示例包括C++和python两个版本 |
| **name_demo** | 演示全局命名空间和局部命名空间下参数的提取 |
| **tf_follower** | 制作mybot机器人 实现mybot跟随xbot的功能 |
| **urdf_demo** |  创建机器人urdf模型，在RViz中显示  |
| **navigation_sim_demo** | 导航演示工具包，包括AMCL, Odometry Navigation等演示 |
| **slam_sim_demo** | 同步定位与建图演示，包括Gmapping, Karto, Hector等SLAM演示 |
| **orbslam2_demo** | ORB_SLAM2的演示 |
| **rtabmap_demo** | rtabmap的演示 |
| **cartographer_demo** | cartographer安装演示包|
| **dependlib** | ubuntu18所依赖的包(melodic不自带) |
| **ros_academy_for_beginners** | Metapacakge示例，依赖了本仓库所有的pacakge |


---

## 下载编译和运行

1. 克隆或下载ROS-Academy-for-Beginners教学包到工作空间的`/src`目录下，例如 `~/catkin_ws/src`
```sh
$ cd ~/catkin_ws/src
$ git clone -b melodic https://github.com/DroidAITech/ROS-Academy-for-Beginners.git
```

2. 安装教学包所需的依赖
```sh
$ cd ~/catkin_ws
$ rosdep install --from-paths src --ignore-src --rosdistro=melodic -y
```

3. 编译并刷新环境
```sh
$ catkin_make
$ source ~/catkin_ws/devel/setup.bash
```

4. 升级gazebo

(1). 建议在**本地Ubuntu 18.04**下运行仿真程序。目前Gazebo模拟器的**兼容性**是一大问题，在虚拟机或配置较低的电脑上可能无法运行。**如果你的显卡是N卡，建议安装Ubuntu下的显卡驱动**。

(2). 运行Gazebo仿真程序`robot_sim_demo`前，请将Gazebo升级到9.x版本以上（**推荐9.14版本**）。


  查看Gazebo版本方法
  ```sh
  $ gazebo -v   #确认9.0以上，推荐9.14
  ```

  升级方法

  ```sh
  $ sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
  $ wget http://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -
  $ sudo apt-get update
  $ sudo apt-get install gazebo9
  ```

系统更新

  ```sh
  $ sudo apt-get update && upgrade #需要执行，否则环境启动可能存在问题
  ```

(3). 确保所有依赖都已安装，如`gazebo_ros`, `gmapping`, `slam_karto`, `amcl`。

5. 启动仿真环境

```
roslaunch robot_sim_demo robot_spawn.launch
```

---
## Copyright

![Logo](./joint_logo.png)
