#include <iostream>

#include "SharedCStyle.h"

// call it BEFORE the boost library is declared
#define BOOST_ALL_NO_LIB
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

/** @brief This function get the pointer to the image.

	The caller provides to fill the memory with valid data.
	In case of FFPlay, it modifies the codify plane data
	in pack data.
*/
//Open already created shared memory object.
boost::interprocess::shared_memory_object shm;
//Map the whole shared memory in this process
boost::interprocess::mapped_region region;
unsigned char *mem = nullptr;
//cv::Mat global_m;
unsigned char*  get_cvmat_ptr(int w, int h) {
	return static_cast<unsigned char*>(region.get_address());
}

/** @brief Even if called at each time, it should not do anything
           It is an easy solution to reduces the points
		   where FFPlay is modified.
*/
bool shm_is_initialize = false;
void create_shm() {
	if (shm_is_initialize) return;

	//Open already created shared memory object.
	shm = boost::interprocess::shared_memory_object(
		boost::interprocess::open_only, "ShmCStyle",
		boost::interprocess::read_write);

	//Map the whole shared memory in this process
	region = boost::interprocess::mapped_region(shm,
		boost::interprocess::read_write);

	shm_is_initialize = true;
}





// Some additional code used for testing

//#include <opencv2/opencv.hpp>


class MyType
{
public:

	MyType() {}

	void doIt(int param) {
		std::cout << "param: " << param << std::endl;
	}
};

mylibrary_mytype_t mylibrary_mytype_init() {
	return new MyType;
}

void mylibrary_mytype_destroy(mylibrary_mytype_t untyped_ptr) {
	MyType* typed_ptr = static_cast<MyType*>(untyped_ptr);
	delete typed_ptr;
}

void mylibrary_mytype_doit(mylibrary_mytype_t untyped_self, int param) {
	MyType* typed_self = static_cast<MyType*>(untyped_self);
	typed_self->doIt(param);
}

/** @brief Keep this function. It is used to convert the YV12ToRgb
		   Reference lost...
*/
//cv::Mat Yv12ToRgb(uchar *pBuffer, long bufferSize, int width, int height)
//{
//	cv::Mat result(height, width, CV_8UC3);
//	uchar y, cb, cr;
//
//	long ySize = width * height;
//	long uSize;
//	uSize = ySize >> 2;
//
//	assert(bufferSize == ySize + uSize * 2);
//
//	uchar *output = result.data;
//	uchar *pY = pBuffer;
//	uchar *pU = pY + ySize;
//	uchar *pV = pU + uSize;
//
//	uchar r, g, b;
//	for (int i = 0; i < uSize; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			y = pY[i * 4 + j];
//			cb = pU[i];
//			cr = pV[i];
//
//			//ITU-R standard
//			b = cv::saturate_cast<uchar>(y + 1.772*(cb - 128));
//			g = cv::saturate_cast<uchar>(y - 0.344*(cb - 128) - 0.714*(cr - 128));
//			r = cv::saturate_cast<uchar>(y + 1.402*(cr - 128));
//
//			*output++ = b;
//			*output++ = g;
//			*output++ = r;
//		}
//	}
//	return result;
//}

void mylibrary_avframe2cvmat(int height, int width, char* data, int linesize) {
	//std::cout << ">> " << height << " " << width << " " << linesize << std::endl;

	//cv::Mat mat(height, width, CV_8UC3, data, linesize);
	//cv::imshow("frame", mat);
	//cv::waitKey(10);

	//cv::Mat picYV12 = cv::Mat(height * 3 / 2, width, CV_8UC1, data);
	//cv::Mat picBGR;
	//cv::cvtColor(picYV12, picBGR, CV_YUV2BGRA_Y422);// , CV_YUV2BGR_YV12);
	//cv::Mat picBGR = Yv12ToRgb(reinterpret_cast<uchar*>(data), linesize, width, height);
	//cv::imshow("test.bmp", picBGR);  //only for test
	//cv::waitKey(1);
}



/*
https://stackoverflow.com/questions/44852117/libav-avframe-to-opencv-mat-to-avpacket-conversion

add a function to get the pointer to the cv mat
pass image size, receive pointer to mat data

AVFrame cvmat_to_avframe(cv::Mat* frame)
{

		AVFrame dst;
		cv::Size frameSize = frame->size();
		AVCodec *encoder = avcodec_find_encoder(AV_CODEC_ID_RAWVIDEO);
		AVFormatContext* outContainer = avformat_alloc_context();
		AVStream *outStream = avformat_new_stream(outContainer, encoder);
		avcodec_get_context_defaults3(outStream->codec, encoder);

		outStream->codec->pix_fmt = AV_PIX_FMT_BGR24;
		outStream->codec->width = frame->cols;
		outStream->codec->height = frame->rows;
		avpicture_fill((AVPicture*)&dst, frame->data, AV_PIX_FMT_BGR24, outStream->codec->width, outStream->codec->height);
		dst.width = frameSize.width;
		dst.height = frameSize.height;

		return dst;
}


cv::Mat avframe_to_cvmat(AVFrame *frame)
{
		AVFrame dst;
		cv::Mat m;

		memset(&dst, 0, sizeof(dst));

		int w = frame->width, h = frame->height;
		m = cv::Mat(h, w, CV_8UC3);
		dst.data[0] = (uint8_t *)m.data;
		avpicture_fill( (AVPicture *)&dst, dst.data[0], AV_PIX_FMT_BGR24, w, h);

		struct SwsContext *convert_ctx=NULL;
		enum AVPixelFormat src_pixfmt = AV_PIX_FMT_BGR24;
		enum AVPixelFormat dst_pixfmt = AV_PIX_FMT_BGR24;
		convert_ctx = sws_getContext(w, h, src_pixfmt, w, h, dst_pixfmt,
						SWS_FAST_BILINEAR, NULL, NULL, NULL);

		sws_scale(convert_ctx, frame->data, frame->linesize, 0, h,
						dst.data, dst.linesize);
		sws_freeContext(convert_ctx);

		return m;
}
*/
