/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
 * log.h
 *
 *  Created on: 2012. 10. 26.
 *      Author: kjsa
 */

#ifdef _NDK_LOG_ENABLE_
#include <android/log.h>

#define LOGV(...)   __android_log_print(ANDROID_LOG_VERBOSE, "ProudNet_VERBOSE", __VA_ARGS__)
#define LOGD(...)   __android_log_print(ANDROID_LOG_DEBUG, "ProudNet_DEBUG", __VA_ARGS__)
#define LOGI(...)   __android_log_print(ANDROID_LOG_INFO, "ProudNet_INFO", __VA_ARGS__)
#define LOGW(...)   __android_log_print(ANDROID_LOG_WARN, "ProudNet_WARN", __VA_ARGS__)
#define LOGE(...)   __android_log_print(ANDROID_LOG_ERROR, "ProudNet_ERROR", __VA_ARGS__)

#else
#define LOGV(...)
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#endif /* LOG_H_ */
