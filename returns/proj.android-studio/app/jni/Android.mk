LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

MY_SRC_PATH := ../../..
# Classes : include all 'cpp' files in the ../../Classes/ directory
LIR_FILE_LIST_CLASSES 	:= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/GameObjects/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/AI/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/GUI/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/GUI/CocosWidget/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Helper/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Lib/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Lib/shatter/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Plugins/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Secene/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Utils/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Plugins/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Layer/*.cpp)
LIR_FILE_LIST_CLASSES 	+= $(wildcard $(LOCAL_PATH)/$(MY_SRC_PATH)/Classes/Layer/SubLayer/*.cpp)


LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(LIR_FILE_LIST_CLASSES:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES :=	 $(LOCAL_PATH)/../../../Classes
LOCAL_C_INCLUDES +=	 $(LOCAL_PATH)/../../../Classes/AI
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/GameObjects
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/GUI
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/GUI/CocosWidget
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/Helper
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/Layer
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/Layer/SubLayer
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/Lib
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/Plugins
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/Secene
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/Utils


# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

#LOCAL_EXPORT_C_INCLUDES :=	 $(LOCAL_PATH)/../../Classes
#LOCAL_EXPORT_C_INCLUDES +=	 $(LOCAL_PATH)/../../Classes/AI
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/GameObjects
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/GUI
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/GUI/CocosWidget
#							$(LOCAL_PATH)/../../Classes/GUI/CocosWidget/CEditBox
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Helper
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Layer
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Layer/SubLayer
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Lib
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Plugins
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Secene
#LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utils

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
