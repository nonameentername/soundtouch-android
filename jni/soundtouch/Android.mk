LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libsoundtouch

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/soundtouch/include/ \
	$(LOCAL_PATH)/soundtouch/source/SoundTouch/

LOCAL_EXPORT_C_INCLUDES := \
	$(LOCAL_PATH)/soundtouch/include/

LOCAL_SRC_FILES := \
	soundtouch/source/SoundTouch/AAFilter.cpp \
	soundtouch/source/SoundTouch/BPMDetect.cpp \
	soundtouch/source/SoundTouch/FIFOSampleBuffer.cpp \
	soundtouch/source/SoundTouch/FIRFilter.cpp \
	soundtouch/source/SoundTouch/PeakFinder.cpp \
	soundtouch/source/SoundTouch/RateTransposer.cpp \
	soundtouch/source/SoundTouch/SoundTouch.cpp \
	soundtouch/source/SoundTouch/TDStretch.cpp \
	soundtouch/source/SoundTouch/cpu_detect_x86.cpp \
	soundtouch/source/SoundTouch/mmx_optimized.cpp \
	soundtouch/source/SoundTouch/sse_optimized.cpp \

include $(BUILD_SHARED_LIBRARY)
