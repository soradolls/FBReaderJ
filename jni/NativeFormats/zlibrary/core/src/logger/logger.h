#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>
#include "android/log.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

#define LOG(priority, tag, ...) __android_log_print(priority, tag, __VA_ARGS__);
#define LOGV(tag, ...) __android_log_print(ANDROID_LOG_VERBOSE, tag, __VA_ARGS__);
#define LOGD(tag, ...) __android_log_print(ANDROID_LOG_DEBUG, tag, __VA_ARGS__);
#define LOGW(tag, ...) __android_log_print(ANDROID_LOG_WARN, tag, __VA_ARGS__);
#define LOGE(tag, ...) __android_log_print(ANDROID_LOG_ERROR, tag, __VA_ARGS__);

#define LOG_(priority, ...)   \
    do {    \
        std::string _file_name = __FILE__;  \
        std::string _fn = _file_name;   \
        int pos = _file_name.rfind('/');   \
        if (pos >=0 && pos < _file_name.length())  \
        {   \
            _fn = _file_name.substr(pos+1);   \
        }   \
        int line = __LINE__;                \
        char tag[1024] = {0};               \
        sprintf(tag, "%s:%d", _fn.c_str(), line);    \
        LOG(priority, tag, __VA_ARGS__); \
    } while(0);

#define LOG_V(...) LOG_(ANDROID_LOG_VERBOSE, __VA_ARGS__);
#define LOG_D(...) LOG_(ANDROID_LOG_DEBUG, __VA_ARGS__);
#define LOG_W(...) LOG_(ANDROID_LOG_WARN, __VA_ARGS__);
#define LOG_E(...) LOG_(ANDROID_LOG_ERROR, __VA_ARGS__);


#endif