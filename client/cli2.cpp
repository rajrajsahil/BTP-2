// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <errno.h>

#include <bits/stdc++.h>
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <fstream>
#include "opencv2/contrib/contrib.hpp"
#include <cctype>
// #include <stdio.h>
#include <string.h>
#include <time.h>
//using namespace std;
using namespace cv;

using namespace std;
#define PORT 8234
  
const Size chessboard_dimentions =Size(9,6);
int receive_image(int socket)
{ // Start function 
FILE *image;
char * filename = new char[50];
int count=14;
int tot_images = 0;
namedWindow("windows",WINDOW_NORMAL);
while(1)
{
int buffersize = 0, recv_size = 0,size = 0, read_size, write_size, packet_index =1,stat;

char imagearray[163841],verify = '1';//10241;



//Find the size of the image

do{
stat = read(socket, &size, sizeof(int));
//cout<<"size:"<<&size<<endl;
}while(stat<0);


/*printf("Packet received.\n");
printf("Packet size: %i\n",stat);
printf("Image size: %i\n",size);
printf(" \n");*/

char buffer[] = "Gotit";

//Send our verification signal
do{
stat = write(socket, &buffer, sizeof(int));
}while(stat<0);

//printf("Reply sent\n");
printf(" \n");
sprintf(filename,"get_image_%i.ppm",count);
count++;
image = fopen(filename, "w");

if( image == NULL) {
printf("Error has occurred. Image file could not be opened\n");
return -1; }

//Loop while we have not received the entire file yet


 int need_exit = 0;
struct timeval timeout = {10,0};

fd_set fds;
int buffer_fd, buffer_out;

while(recv_size < size) {
//while(packet_index < 2){

    FD_ZERO(&fds);
    FD_SET(socket,&fds);

    buffer_fd = select(FD_SETSIZE,&fds,NULL,NULL,&timeout);

    if (buffer_fd < 0)
       printf("error: bad file descriptor set.\n");

    if (buffer_fd == 0)
       printf("error: buffer read timeout expired.\n");

    if (buffer_fd > 0)
    {
        do{
               read_size = read(socket,imagearray, 10241);
            }while(read_size <0);

            /*printf("Packet number received: %i\n",packet_index);
        printf("Packet size: %i\n",read_size);*/


        //Write the currently read data into our image file
         write_size = fwrite(imagearray,1,read_size, image);
         // printf("Written image size: %i\n",write_size); 

             if(read_size !=write_size) {
                printf("error in read write\n");    }


             //Increment the total number of bytes read
             recv_size += read_size;
             packet_index++;
             /*printf("Total received image size: %i\n",recv_size);
             printf(" \n");
             printf(" \n");*/
    }

}
  
		Mat stereo =imread(filename,1);
    imshow("windows",stereo);
    waitKey(10);
		// Mat left(stereo.rows,stereo.cols/2,CV_8UC3,Scalar(0,0,0));
		// stereo(Rect(0,0,stereo.cols/2,stereo.rows)).copyTo(left);
		// Mat right(stereo.rows,stereo.cols/2,CV_8UC3,Scalar(0,0,0));
		// stereo(Rect(stereo.cols/2,0,stereo.cols/2,stereo.rows)).copyTo(right);
		// vector<Point2f> corners_left;
		// bool found_left =cv::findChessboardCorners(left,chessboard_dimentions,corners_left);
		// vector<Point2f> corners_right;
		// bool found_right =cv::findChessboardCorners(right,chessboard_dimentions,corners_right);
		// if(found_right&&found_left)
		// {
		// 	cout<<"chess board recognised"<<endl;
		// 	count++;
		// 	tot_images++;
		// }
		// else
		// {	
		// 	tot_images++;
		// 	cout<<"bad image"<<endl;
		// }
		// cout<<"count:"<<count<<endl;
		// cout<<"Total images:"<<tot_images<<endl;
}
  fclose(image);
  printf("Image successfully Received!\n");
  return 1;
  }
int main(int argc, char const *argv[])
{
    int socket_desc;
  struct sockaddr_in server;
  char *parray;


  //Create socket
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);

  if (socket_desc == -1) {
  printf("Could not create socket");
  }

  memset(&server,0,sizeof(server));
  server.sin_addr.s_addr = inet_addr("10.11.40.153");
  server.sin_family = AF_INET;
  server.sin_port = htons( 8234 );

  //Connect to remote server
  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
  cout<<strerror(errno);
  close(socket_desc);
  puts("Connect Error");
  return 1;
  }

  puts("Connected\n");

  receive_image(socket_desc);

  close(socket_desc);

  return 0;
  
}
