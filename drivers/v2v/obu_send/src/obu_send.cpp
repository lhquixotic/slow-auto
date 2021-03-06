#include <ros/ros.h>
#include "obu_send.hpp"
#include <sstream>

namespace ns_obu_send {

static void _split(const std::string& s, char delim, std::vector<std::string>& elems) {
  std::stringstream ss(s);
  std::string item;
  while(std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> elems;
  _split(s, delim, elems);
  return elems;
}


// Constructor
ObuSend::ObuSend(ros::NodeHandle &nh) : nh_(nh) {

};

// Getters
int ObuSend::getSockfd() {return sock_fd;}
int ObuSend::getSocklen() {return len;}
struct sockaddr_in ObuSend::getSockaddr() {return addr_serv;}

// Setters
// void ObuSend::setConeDetections(fsd_common_msgs::ConeDetections cones) {
//   cone_current = cones;
// }


void ObuSend::socketComSetup(){
/* 建立udp socket */
  sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  ROS_INFO_STREAM("Sock fd: " << sock_fd);
  if(sock_fd < 0)
  {
    perror("socket");
    exit(1);
  }
  /* 设置address */
  memset(&addr_serv, 0, sizeof(addr_serv));
  addr_serv.sin_family = AF_INET;
  addr_serv.sin_addr.s_addr = inet_addr(DSET_IP_ADDRESS);
  addr_serv.sin_port = htons(DEST_PORT);
  len = sizeof(addr_serv);

  // 发送接收数据时数组结尾加\0
  int send_num;
  char send_buf[2] = {'1', '\0'};
  std::string ssss = send_buf;
  ROS_INFO("client send: %s\n", ssss.c_str());
  send_num = sendto(sock_fd, send_buf, strlen(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
    perror("sendto error:");
    exit(1);
  }else{
    ROS_INFO("Sent success");
  }
}

void ObuSend::runAlgorithm() {
  std::string s = "";
  s += std::to_string(utm_pose.pose.pose.position.x);
  s += " ";
  s += std::to_string(utm_pose.pose.pose.position.y);
  s += " ";
  s += std::to_string(utm_pose.pose.pose.orientation.x);
  s += " ";
  s += std::to_string(utm_pose.pose.pose.orientation.y);
  s += " ";
  s += std::to_string(utm_pose.pose.pose.orientation.z);
  s += " ";
  s += std::to_string(utm_pose.pose.pose.orientation.w);
  s += " ";
  s += std::to_string(vehicle_dynamic_state.vehicle_speed);
  s += " ";
  s += std::to_string(vehicle_dynamic_state.vehicle_lon_acceleration);
  s += " ";
  s += std::to_string(vehicle_dynamic_state.vehicle_lon_acceleration);
  s += " ";
  s += std::to_string(chassis_status.real_brake_pressure);
  s += " ";
  s += std::to_string(chassis_status.real_steer_angle);
  char c[s.size() + 1];
  strcpy(c, s.c_str());
  int send_num = sendto(sock_fd, c, strlen(c), 0, (struct sockaddr *)&addr_serv, len);

  if(send_num < 0)
  {
    perror("sendto error:");
    exit(1);
  }
}

void ObuSend::setChassisStatus(common_msgs::ChassisStatus msg){
  chassis_status = msg;
}
void ObuSend::setUtmPose(nav_msgs::Odometry msg){
  utm_pose = msg;
}
void ObuSend::setVehicleDynamicState(common_msgs::VehicleDynamicState msg){
  vehicle_dynamic_state = msg;
}

}
