LOCAL_PATH := $(call my-dir)

PACKAGE_NAME := org.tecunhuman.jni

JAVA_DIR := $(LOCAL_PATH)/../../src/$(shell echo $(PACKAGE_NAME) | sed 's/\./\//g')
NDK_DIR := $(LOCAL_PATH)/gen

$(shell mkdir -p $(JAVA_DIR))
$(shell mkdir -p $(NDK_DIR))

$(shell \
	swig -c++ -java -package $(PACKAGE_NAME) \
	-outdir $(JAVA_DIR) \
	-o $(NDK_DIR)/wrapper_wrap.cpp \
	$(LOCAL_PATH)/wrapper.i \
)

include $(CLEAR_VARS)

LOCAL_MODULE := libsoundstretch

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/.

LOCAL_EXPORT_C_INCLUDES := \
	$(LOCAL_PATH)/.

LOCAL_SRC_FILES := \
	RunParameters.cpp \
	WavFile.cpp \
	SoundStretch.cpp \
	gen/wrapper_wrap.cpp

LOCAL_SHARED_LIBRARIES := libsoundtouch

include $(BUILD_SHARED_LIBRARY)
