    #include <ros/ros.h>  
    #include <image_transport/image_transport.h>  
    #include <opencv2/highgui/highgui.hpp>  
    #include <cv_bridge/cv_bridge.h>  
    #include <sstream> // for converting the command line parameter to integer  
      
    int main(int argc, char** argv)  
    {  
       
      ros::init(argc, argv, "image_publisher");  
      ros::NodeHandle nh;  
      image_transport::ImageTransport it(nh);  
      image_transport::Publisher pub = it.advertise("picture/video", 1);  
      std::string first_file="/home/zrxlovedjl/ROS_CV_Video/video/David/%4d.jpg";
      cv::VideoCapture sequence(first_file);  
       
      cv::Mat frame;  
      sensor_msgs::ImagePtr msg;  
      ros::Rate loop_rate(25);  
      while (nh.ok()) {  
        sequence >> frame;  
        // Check if grabbed frame is actually full with some content  
        if(!frame.empty()) {  
          msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();  
          pub.publish(msg);  
        //cv::Wait(5);  
        }  
      
        ros::spinOnce();  
        loop_rate.sleep();  
      }  
    }  
