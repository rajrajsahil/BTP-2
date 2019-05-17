void get_maps(Mat &map1_x,Mat &map2_x,Mat &map1_y,Mat &map2_y)
{
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
}