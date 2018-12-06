#ifndef __TLGE__TLGE_H__
#define __TLGE__TLGE_H__

#define PI 3.1415926535897932384626433832795f

/**************************************************************OS Specific Code**************************************************************/

//Check for platform and load corresponding header
#if defined(__WINDOWS_BUILD__) || defined(_WINDOWS)
	#define MAIN_NEEDS_REPLACING
	#include "..\Platforms\Windows\TLGE_Windows.h"
	#include <Windows.h>
	#include <gl\GL.h>
#endif

#if defined(__ANDROID_BUILD__) || defined(__ANDROID__)
	#define MAIN_NEEDS_REPLACING
	#include "..\Platforms\Android\TLGE_Android.h"
	#include <GLES/gl.h>
	#include <SLES/OpenSLES.h>
	#include <SLES/OpenSLES_Android.h>
#endif


//Redefining main to let engine user have a main instead of winmain
#if defined(MAIN_NEEDS_REPLACING)
	#undef main
	#define main    User_main
#endif

extern int User_main();

/**************************************************************General Includes**************************************************************/
#include <vector>
#include <map>
#include <assert.h>
#include <time.h> 
#include <string>
#include <sstream>

#include "../Libraries/glm/glm.hpp"
#include "..\Libraries\glm\gtc\quaternion.hpp"
#include "..\Libraries\glm\gtc\matrix_transform.hpp"

#include "..\Libraries\lodepng\lodepng.h"

/**************************************************************Engine Includes***************************************************************/
#include "..\Core\Constants.h"
#include "..\Core\GameCore.h"
#include "..\Core\WindowManager.h"
#include "..\Core\SceneManager.h"
#include "..\Core\SoundManager.h"
#include "..\Core\Scene.h"
#include "..\Core\Tween.h"
#include "..\Core\TweenFuncs.h"
#include "..\Core\GameObject.h"

#include "..\Resources\Resource.h"
#include "..\Resources\Mesh.h"
#include "..\Resources\ShaderProgram.h"
#include "..\Resources\Texture.h"

#include "..\Events\Event.h"
#include "..\Events\OnQuitEvent.h"
#include "..\Events\ClickEvent.h"
#include "..\Events\ResizeEvent.h"
#include "..\Events\KeyEvent.h"
#include "..\Events\MouseMove.h"
#include "..\Events\MouseLeaveEvent.h"

#include "..\Components\Component.h"
#include "..\Components\Transform.h"
#include "..\Components\Model.h"
#include "..\Components\Sprite.h"
#include "..\Components\OBJModel.h"
#include "..\Components\Camera.h"
#include "..\Components\Button.h"

#include "..\Systems\System.h"
#include "..\Systems\Graphics.h"

#endif