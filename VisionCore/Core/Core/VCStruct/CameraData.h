#pragma once

/*
All these names are from the OpenCV documentation (http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html#videocapture-set)

CV_CAP_PROP_POS_MSEC		| pos_msec			| Current position of the video file in milliseconds.
CV_CAP_PROP_POS_FRAMES		| pos_frames		| 0-based index of the frame to be decoded/captured next.
CV_CAP_PROP_POS_AVI_RATIO	| pos_avi_ratio		| Relative position of the video file: 0 - start of the film, 1 - end of the film.
CV_CAP_PROP_FRAME_WIDTH		| frame_width		| Width of the frames in the video stream.
CV_CAP_PROP_FRAME_HEIGHT	| frame_height		| Height of the frames in the video stream.
CV_CAP_PROP_FPS				| fps				| Frame rate.
CV_CAP_PROP_FOURCC			| ---				| 4-character code of codec.
CV_CAP_PROP_FRAME_COUNT		| frame_count		| Number of frames in the video file.
CV_CAP_PROP_FORMAT			| format			| Format of the Mat objects returned by retrieve() .
CV_CAP_PROP_MODE			| mode				| Backend-specific value indicating the current capture mode.
CV_CAP_PROP_BRIGHTNESS		| brightness		| Brightness of the image (only for cameras).
CV_CAP_PROP_CONTRAST		| contrast			| Contrast of the image (only for cameras).
CV_CAP_PROP_SATURATION		| saturation		| Saturation of the image (only for cameras).
CV_CAP_PROP_HUE				| hue				| Hue of the image (only for cameras).
CV_CAP_PROP_GAIN			| gain				| Gain of the image (only for cameras).
CV_CAP_PROP_EXPOSURE		| exposure			| Exposure (only for cameras).
CV_CAP_PROP_CONVERT_RGB		| convert_RGB		| Boolean flags indicating whether images should be converted to RGB.
CV_CAP_PROP_WHITE_BALANCE_U	| white_balance_u	| The U value of the whitebalance setting (note: only supported by DC1394 v 2.x backend currently)
CV_CAP_PROP_WHITE_BALANCE_V	| white_balance_v	| The V value of the whitebalance setting (note: only supported by DC1394 v 2.x backend currently)
CV_CAP_PROP_RECTIFICATION	| rectification		| Rectification flag for stereo cameras (note: only supported by DC1394 v 2.x backend currently)
CV_CAP_PROP_ISO_SPEED		| ISO_speed			| The ISO speed of the camera (note: only supported by DC1394 v 2.x backend currently)
CV_CAP_PROP_BUFFERSIZE		| buffersize		| Amount of frames stored in internal buffer memory (note: only supported by DC1394 v 2.x backend currently)
*/

namespace VisionCore
{
	namespace VCStruct
	{
		struct VideoSettings
		{
			int pos_msec;
			int pos_frames;
			int pos_avi_ratio;

			int frame_width;
			int frame_height;
			int fps;

			int brightness;
			int contrast;
			int saturation;
			int hue;
			int gain;
			int exposure;


			// NOT REALLY SUPPORTED
			int frame_count;
			int format;
			int mode;

			bool convert_RGB;
			double white_balance_u;
			double white_balance_v;
			int rectification;
			int ISO_speed;
			int buffersize;
		};
	}
}
