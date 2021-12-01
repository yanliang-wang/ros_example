# ROS example
ROS是一个功能很强大的工具，这个仓库包含了ROS的一些常用功能的使用demo，还有一些进阶功能的使用demo，便于快速进行ROS开发。除此之外，还包括一些ROS工具的介绍便于进行ROS工程的调试，enjoy it!


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