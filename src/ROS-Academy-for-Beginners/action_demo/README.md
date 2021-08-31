# action_demo

### introduce

本demo在课程仿真场景下,演示一个简单的action通讯.运行action之后,会看到xbot在场景中简单的"折返跑".同时,终端打印实时进度,反馈通信进程状态.

### run

1.  打开一个终端:`$ roslaunch robot_sim_demo robot_spawn.launch`

2. 打开一个新终端:`$ rosrun action_demo linewalk_server.py`

3. 打开一个新终端 :`$ rosrun action_demo linewalk_client.py`

这个例子只有python版本，而且不太好，没有展示feedback还有result收到之后应该怎么用，更好的教程参考[古月居博客](https://www.guyuehome.com/908)，和本仓库另个一个[action demo](../common_tutorials/actionlib_tutorials)



action的server client执行时，会产生下面五个话题,说明action机制是通过topic的形式来实现的

/linewalk/cancel：取消信号
/linewalk/feedback：实时的反馈
/linewalk/goal：目标
/linewalk/result：结果，也是一个状态，会随feedback更新
/linewalk/status