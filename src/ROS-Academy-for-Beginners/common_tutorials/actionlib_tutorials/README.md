

参考[古月居博客](https://www.guyuehome.com/908)

## 介绍

Action机制本质是通过五个topic来实现的，client向server发送 goal，cancel，server向client发送status，result（结束时发送一次），feedback（在动作执行时可以一直发送）

1. goal：任务目标
2. cancel：请求取消任务
3. status：通知client当前的状态
4. feedback：周期反馈任务运行的监控数据
5. result：向client发送任务的执行结果，这个topic只会发布一次。

## API

client再向server发送goal时，可以设置三个回调函数

```c++
// 当action完成后会调用次回调函数一次
void doneCb(const actionlib::SimpleClientGoalState& state,
        const action_tutorials::DoDishesResultConstPtr& result);

// 当action激活后会调用次回调函数一次
void activeCb();

// 收到feedback后调用的回调函数
void feedbackCb(const action_tutorials::DoDishesFeedbackConstPtr& feedback)；
    
client.sendGoal(goal,  &doneCb, &activeCb, &feedbackCb);
```






