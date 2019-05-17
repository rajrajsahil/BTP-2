#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
// #include "get_all4_maps.cpp"

using namespace cv;
using namespace std;

Mat img11;
Mat img22;
stack<Point2d> s;
void myfun()
{
long double cx;
long double cy;
long double W;  
long double f;
long double X;
long double Y;
long double Z;

int xr=s.top().y;
int yr=s.top().x;
s.pop();
int xl=s.top().y;
int yl=s.top().x;
s.pop();

int d = xl-xr; 
if(d<0)
{
	cout<<"ERROR"<<endl;
	return;
}
else
{
	cx = 482.4403133392334;
	cy = 463.4894180297852;
	W = 8.253454376352238*d;  
	f = 969.47795756895;
	X = ((xl-cx)/W)*1.48;
	Y =  ((yl-cy)/W)*1.48;
	Z = (f/W)*1.48;
	cout<<"X: "<<X<<endl;
	cout<<"Y: "<<Y<<endl;
	cout<<"Z: "<<Z<<endl;
}
}

void select_point(int event, int j, int i, int flags, void* userdata)
{	
	// int lx, ly, rx,ry;
	if(event==EVENT_LBUTTONDOWN)
	{	
		cout<<"point:("<<i<<","<<j<<")"<<endl;
		s.push(Point2d(i,j));
	}
	if(s.size()==2)
	{
		myfun();
	}
}
int main()
{	
	// Mat map1_x,map2_x,map1_y,map2_y;
	Mat img = imread("img.ppm",0);
	int var1;

	////to get four maps
//////////////////////////////////////////
	Mat map1_x(img.rows,img.cols,CV_16SC2,Scalar(0));
	Mat map2_x(img.rows,img.cols,CV_16SC2,Scalar(0));
	Mat map1_y(img.rows,img.cols,CV_16UC1,Scalar(0));
	Mat map2_y(img.rows,img.cols,CV_16UC1,Scalar(0));

	ifstream file;
	ofstream save;
	file.close();
	

	///////////////////
	file.open("my_maps/map1_1");
	if(file.good())
	{
		for(int i=0;i<map1_x.rows;i++)
		{
			for (int j = 0; j <map1_x.cols; j++)
			{	
				file>>var1;
				map1_x.at<Vec2s>(i,j)[0]=var1;
				file>>var1;
				map1_x.at<Vec2s>(i,j)[1]=var1;

			}
		}
	}
	else
	{
		cout<<"prob"<<endl;
	}
	file.close();

	/////////////
	file.open("my_maps/map2_1");
	if(file.good())
	{
		for(int i=0;i<map2_x.rows;i++)
		{
			for (int j = 0;j <map2_x.cols; j++)
			{	
				file>>var1;
				map2_x.at<Vec2s>(i,j)[0]=var1;
				file>>var1;
				map2_x.at<Vec2s>(i,j)[1]=var1;

			}
		}
	}
	else
	{
		cout<<"prob"<<endl;
	}
	file.close();
	
	///////
	file.open("my_maps/map1_2");
	if(file.good())
	{
		for(int i=0;i<map1_y.rows;i++)
		{
			for (int j = 0;j <map1_y.cols; j++)
			{	
				file>>var1;
				map1_y.at<unsigned short>(i,j)=var1;

			}
		}
	}
	else
	{
		cout<<"prob"<<endl;
	}
	file.close();

	//////
	file.open("my_maps/map2_2");
	if(file.good())
	{
		for(int i=0;i<map2_y.rows;i++)
		{
			for (int j = 0;j <map2_y.cols; j++)
			{	
				file>>var1;
				map2_y.at<unsigned short>(i,j)=var1;

			}
		}
	}
	else
	{
		cout<<"prob"<<endl;
	}
	file.close();

//////////////////////////////////////////

	Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	// stereo(Rect(0,0,stereo.cols/2,stereo.rows)).copyTo(img1);
	Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	// stereo(Rect(stereo.cols/2,0,stereo.cols/2,stereo.rows)).copyTo(img2);


	// VideoCapture live_stream("https://www.youtube.com/watch?v=6704d9DDwLo");
	VideoCapture live_stream("tcp://10.11.40.182:9696");
	Mat stereo;
	namedWindow("left-recified",WINDOW_AUTOSIZE);
	namedWindow("right-rectified",WINDOW_AUTOSIZE);
	while(live_stream.isOpened())
	{
		live_stream>>stereo;

		////// rectifying(remaping) the above two image seperately uisng maps
		stereo(Rect(0,0,stereo.cols/2,stereo.rows)).copyTo(img1);
		stereo(Rect(stereo.cols/2,0,stereo.cols/2,stereo.rows)).copyTo(img2);
		remap(img1, img11, map1_x, map1_y, CV_INTER_LINEAR,BORDER_CONSTANT);
		remap(img2, img22, map2_x, map2_y, CV_INTER_LINEAR,BORDER_CONSTANT);

		setMouseCallback("left-recified",select_point, NULL);
		setMouseCallback("right-rectified",select_point, NULL);

		imshow("left-recified",img11);
		imshow("right-rectified",img22);
		
		// imshow("original",stereo);
		waitKey(2);
	}

}