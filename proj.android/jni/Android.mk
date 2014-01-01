LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/TestScene.cpp \
                   ../../Classes/CoreScene.cpp \
                   ../../Classes/RoleLayer.cpp \
                   ../../Classes/sqlite/KompexSQLiteBlob.cpp \
                   ../../Classes/sqlite/KompexSQLiteDatabase.cpp \
                   ../../Classes/sqlite/KompexSQLiteStatement.cpp \
                   ../../Classes/sqlite/sqlite3.c \
                   ../../Classes/jansson_android/dump.c \
                   ../../Classes/jansson_android/error.c \
                   ../../Classes/jansson_android/hashtable.c \
                   ../../Classes/jansson_android/load.c \
                   ../../Classes/jansson_android/memory.c \
                   ../../Classes/jansson_android/pack_unpack.c \
                   ../../Classes/jansson_android/strbuffer.c \
                   ../../Classes/jansson_android/strconv.c \
                   ../../Classes/jansson_android/utf.c \
                   ../../Classes/jansson_android/value.c \
                   ../../Classes/NDKHelper/NDKCallbackNode.cpp \
                   ../../Classes/NDKHelper/NDKHelper.cpp \
                   ../../Classes/ytools/YFile.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
                    $(LOCAL_PATH)/../../Classes/sqlite \
                    $(LOCAL_PATH)/../../Classes/NDKHelper \
					$(LOCAL_PATH)/../../Classes/jansson_android \
                    $(LOCAL_PATH)/../../Classes/ytools

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
