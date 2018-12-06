#ifndef __TLGE__ENGINE_PCH_H__
#define __TLGE__ENGINE_PCH_H__

#if defined(__WINDOWS_BUILD__) || defined(_WINDOWS)
#define MAIN_NEEDS_REPLACING
#include "..\Platforms\Windows\TLGE_Windows.h"
#include <Windows.h>
#include <gl\GL.h>
#endif

#if defined (__ANDROID_BUILD__) || defined(__ANDROID__)
	#include <GLES/gl.h>
	#include "..\Libraries\GL\gl2.h"
	#include "..\Libraries\GL\gl2ext.h"
#elif defined(__WINDOWS_BUILD__) || defined(_WINDOWS)
	#include <gl\GL.h>
	#include "..\Libraries\GL\glext.h"
	#include "..\Libraries\GL\Extensions.h"
#endif

/*********************************************************************Code******************************************************************/
#include "TLGE.h"
#endif