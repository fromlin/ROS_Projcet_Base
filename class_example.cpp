#include "class_example.h"

example::example(ros::NodeHandle* nh):nh_(nh)
{
  initPublisher();
  initSubscriber();
}

void example::initPublisher()
{
  _pub = _nh.advertise<std_msgs::Float32>("/topic/pub", 1, true);
}

void example::initSubscriber()
{
  _sub = _nh.subscribe("/topic/sub", 1, &example::CallBack, this);
}

void example::CallBack(const std_msgs::Float32& msg)
{
  temp = msg.data;
  _pub.publish(temp);
}
