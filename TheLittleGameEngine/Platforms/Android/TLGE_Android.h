#ifndef __TLGE__ANDROID_H__
#define __TLGE__ANDROID_H__

#include <android/sensor.h>
#include <EGL/egl.h>
#include "android_native_app_glue.h"
#include <vector>
#include "../Core/GameCore.h"
#include <GLES/gl.h>
#include "WindowManager_Android.h"
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include "WaveLoader.h"
#include "SoundManagerAndroid.h"

#define android_main UserAndroidMain

//TODO: handle save state

int32_t AndroidHandleInput(struct android_app* app, AInputEvent* event);
void AndroidHandleCommand(struct android_app* app, int32_t cmd);
void engine_draw_frame(struct TLGEngine* engine);

extern android_app* g_pAndroidApp;
extern bool g_allIsNew;

#endif