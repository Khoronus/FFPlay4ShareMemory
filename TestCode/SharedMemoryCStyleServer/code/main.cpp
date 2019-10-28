#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#ifdef testthis
int main(int argc, char *argv[])
{
	using namespace boost::interprocess;

	std::cout << "Main process" << std::endl;
	//Remove shared memory on construction and destruction
	struct shm_remove
	{
		shm_remove() { shared_memory_object::remove("ShmCStyle"); }
		~shm_remove() { shared_memory_object::remove("ShmCStyle"); }
	} remover;

	//Create a shared memory object.
	shared_memory_object shm(create_only, "ShmCStyle", read_write);

	cv::Mat img(1600, 1600, CV_8UC3, cv::Scalar::all(0));

	//Set size
	boost::interprocess::offset_t size = img.cols * img.rows * img.channels();
	shm.truncate(size);

	//Map the whole shared memory in this process
	mapped_region region(shm, read_write);

	//Write all the memory to 1
	std::memset(region.get_address(), 1, region.get_size());

	while (true) {
		cv::Mat img_tmp(img.size(), CV_8UC3, region.get_address());
		cv::imshow("imgserver", img);
		if (cv::waitKey(1) == 27) break;
	}

	std::cout << "Server Bye bye" << std::endl;
	return 0;
}
#endif // testthis


int main(int argc, char *argv[])
{
	using namespace boost::interprocess;

	std::cout << "Main process" << std::endl;
	//Remove shared memory on construction and destruction
	struct shm_remove
	{
		shm_remove() { shared_memory_object::remove("ShmCStyle"); }
		~shm_remove() { shared_memory_object::remove("ShmCStyle"); }
	} remover;

	//Create a shared memory object.
	shared_memory_object shm(create_only, "ShmCStyle", read_write);

	cv::Mat img(1600, 1600, CV_8UC3, cv::Scalar::all(0));

	//Set size
	boost::interprocess::offset_t size = img.cols * img.rows * img.channels();
	shm.truncate(size);

	//Map the whole shared memory in this process
	mapped_region region(shm, read_write);

	//Write all the memory to 1
	std::memset(region.get_address(), 1, region.get_size());

	// Get an image which memory data point to the shared memory
	cv::Mat img_tmp(img.size(), img.type(), region.get_address());

	//for (int i = 0; i < 100; ++i)
	//{
	//	std::cout << "Server: " << i << std::endl;
	//	//std::memset(region.get_address(), i % 2, region.get_size());
	//	img = cv::Scalar(rand() % 255, rand() % 255, rand() % 255);
	//	std::memcpy(region.get_address(), img.data, region.get_size());
	//	cv::imshow("img", img);
	//	cv::waitKey(1);
	//}

	// it continues to cycle until q is pressed
	int i = 0;
	while (true)
	{
		cv::imshow("img", img_tmp);
		if (cv::waitKey(1) == 27) break;
		++i;
	}


	std::cout << "Server Bye bye" << std::endl;
	return 0;
}