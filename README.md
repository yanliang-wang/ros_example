# ROS example
ROS是一个功能很强大的工具，这个仓库包含了ROS的一些常用功能的使用demo，还有一些进阶功能的使用demo，便于快速进行ROS开发。除此之外，还包括一些ROS工具的介绍便于进行ROS工程的调试，enjoy it!



## Adcanced 

### 1. [roscpp Timer](http://wiki.ros.org/roscpp/Overview/Timers)(定时器)

- roscpp的定时器会计划以某一频率执行自定义的回调操作。
- 计时器不是实时线程/内核替代品，而是对没有硬实时要求的事物很有用。

**创建定时器：**

- 一般用法：

  ```c++
  ros::Timer ros::NodeHandle::createTimer(ros::Duration period, <callback>, bool oneshot = false);
  ```

  - period ，这是调用定时器回调函数时间间隔。例如，ros::Duration(0.1)，即每十分之一秒执行一次
  - callback，回调函数，支持所有[boost::bind](http://www.boost.org/doc/libs/1_37_0/libs/bind/bind.html)类型可以是函数，类方法，函数对象，输入参数要是ros::TimerEvent类型。
  - oneshot ，表示是否只执行一次，如果已经执行过，还可以通过stop()、setPeriod(ros::Duration)和start()来再执行一次。

**回调函数用法**

- 用法：

  ```c++
  void callback(const ros::TimerEvent&);// ros::TimerEvent结构体作为参数传入，它提供时间的相关信息，对于调试和配置非常有用
  ```

  - ros::TimerEvent结构体说明：
    - ros::Time last_expected 上次回调期望发生的时间
    - ros::Time last_real 上次回调实际发生的时间
    - ros::Time current_expected 本次回调期待发生的时间
    - ros::Time current_real 本次回调实际发生的时间
    - ros::WallTime profile.last_duration 上次回调的时间间隔（结束时间-开始时间），是wall-clock时间。

> 参考：https://www.ncnynl.com/archives/201702/1296.html

## Tricks

1. 减少topic带宽的方式

   - 没有订阅时不发布

     ```c++
     if (topic_name.getNumSubscribers() < 1) return;
     ```

2. rviz显示点（位置，frontier等等）

   可以使用点云pcl::PointXYZI的来表示一个点，另外intensity可以表示想给的颜色，在rviz中的intensity显示模式可以自己的进行颜色的映射。

## Convenient ROS packages

1. topic_tools

   [topic_tools/throttle](http://wiki.ros.org/topic_tools/throttle)可以用来方便地限制话题的发布

   - 限制频率到指定频率

       ```bash
       rosrun topic_tools throttle messages <intopic> <msgs_per_sec> [outtopic]
       ```

       前面的rosrun topic_tools throttle messages 是指使用的是throttle下面的messages模式，其中 intopic是指你想要改变频率的那个topic msgs_per_sec是指你想要它发布的频率，而outtopic是指改变发布频率后的topic的名称，可以省略，如果省略则自动在原来topic的名字上后缀throttle

   - 限制字节
   
     ```bash
     rosrun topic_tools throttle bytes <intopic> <bytes_per_sec> <window> [outtopic]
     ```
   
   除了上面的限制方法，还可以添加lazy参数，来减少不必要的消息发布.
   
   topic_tools除了throttle这个node之外，还有一些其他的节点提供了其他功能，参考http://wiki.ros.org/topic_tools