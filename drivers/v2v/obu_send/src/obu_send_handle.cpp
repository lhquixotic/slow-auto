#include <ros/ros.h>
#include "obu_send_handle.hpp"
#include "register.h"
#include <chrono>

int SockFd;
struct sockaddr_in AddrServ;
int Len;

namespace ns_obu_send {

// Constructor
ObuSendHandle::ObuSendHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    obu_send_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  obu_send_.socketComSetup();
  sock_fd_ = obu_send_.getSockfd();
  addr_serv_ = obu_send_.getSockaddr();
  len_ = obu_send_.getSocklen();
  SockFd = sock_fd_;
  sockaddr_in AddrServ = addr_serv_;
  Len = len_;
  msg_flag1 = false;
  msg_flag2 = false;
  msg_flag3 = false;
  subscribeToTopics();
  publishToTopics();
}

// Getters
int ObuSendHandle::getNodeRate() const { return node_rate_; }

// Methods
void ObuSendHandle::loadParameters() {
  ROS_INFO("loading handle parameters");

  nodeHandle_.param<std::string>("chassis_status_topic_name",chassis_status_topic_name_,"/chassis/status");
  nodeHandle_.param<std::string>("utm_pose_topic_name",utm_pose_topic_name_,"/localization/utmpose");
  nodeHandle_.param<std::string>("vehicle_dynamic_state_topic_name",vehicle_dynamic_state_topic_name_,"/chassis/vehicle_dynamic_state");
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
}

void ObuSendHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  // message_filters::Subscriber <common_msgs::ChassisStatus> subscriber_chassis(nodeHandle_,chassis_status_topic_name_,1000,
  //                             ros::TransportHints().tcpNoDelay());
  // message_filters::Subscriber <common_msgs::GpsInfo> subscriber_gps(nodeHandle_,gps_info_topic_name_,1000,
  //                             ros::TransportHints().tcpNoDelay());
  // message_filters::Subscriber <common_msgs::VehicleDynamicState> subscriber_vehicle(nodeHandle_,vehicle_dynamic_state_topic_name_,1000,
  //                             ros::TransportHints().tcpNoDelay());
  // typedef message_filters::sync_policies::ApproximateTime <common_msgs::ChassisStatus, common_msgs::GpsInfo, common_msgs::VehicleDynamicState> syncPolicy;
  // message_filters::Synchronizer<syncPolicy> sync(syncPolicy(10), subscriber_chassis, subscriber_gps, subscriber_vehicle);  
  // sync.registerCallback(boost::bind(&multiCallback, _1, _2, _3));
  vehicleDynamicStateSubscriber_ = 
      nodeHandle_.subscribe(vehicle_dynamic_state_topic_name_,1000,&ObuSendHandle::vehicleDynamicStateCallback,this);
  chassisStatusSubscriber_ = 
      nodeHandle_.subscribe(chassis_status_topic_name_,1000, &ObuSendHandle::chassisStatusCallback,this);
  utmPoseSubscriber_ = 
      nodeHandle_.subscribe(utm_pose_topic_name_, 1000, &ObuSendHandle::utmPoseCallback,this);
}

void ObuSendHandle::publishToTopics() {
}

void ObuSendHandle::run() {
  if (msg_flag1 & msg_flag2 & msg_flag3){
    obu_send_.runAlgorithm();
  }
  else{
    ROS_WARN("[ObuSend]Waiting for subscribed topic...");
  }
}


// void multiCallback(const common_msgs::ChassisStatus::ConstPtr& chassis, 
// 		nav_msgs::Odometry::ConstPtr& pose,
// 		const common_msgs::VehicleDynamicState::ConstPtr& vehicle) {
//   std::string s = "";
//   s += std::to_string(gpsinfo->fix.latitude);
//   s += " ";
//   s += std::to_string(gpsinfo->fix.longitude);
//   s += " ";
//   s += std::to_string(gpsinfo->fix.altitude);
//   s += " ";
//   s += std::to_string(gpsinfo->rpy.x);
//   s += " ";
//   s += std::to_string(gpsinfo->rpy.y);
//   s += " ";
//   s += std::to_string(gpsinfo->rpy.z);
//   s += " ";
//   s += std::to_string(vehicle->vehicle_speed);
//   s += " ";
//   s += std::to_string(vehicle->vehicle_lon_acceleration);
//   s += " ";
//   s += std::to_string(vehicle->vehicle_lon_acceleration);
//   s += " ";
//   s += std::to_string(chassis->real_brake_pressure);
//   s += " ";
//   s += std::to_string(chassis->real_steer_angle);
//   char c[s.size() + 1];
//   strcpy(c, s.c_str());
//   int send_num = sendto(SockFd, c, strlen(c), 0, (struct sockaddr *)&AddrServ, Len);

//   if(send_num < 0)
//   {
//     perror("sendto error:");
//     exit(1);
//   }
// }

void ObuSendHandle::chassisStatusCallback(const common_msgs::ChassisStatus &msg){
  msg_flag1 = true;
  obu_send_.setChassisStatus(msg);
}

void ObuSendHandle::vehicleDynamicStateCallback(const common_msgs::VehicleDynamicState &msg){
  msg_flag2 = true;
  obu_send_.setVehicleDynamicState(msg);
}

void ObuSendHandle::utmPoseCallback(const nav_msgs::Odometry &msg){
  msg_flag3 = true;
  obu_send_.setUtmPose(msg);
}

}