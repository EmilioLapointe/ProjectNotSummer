#include "EnginePCH.h"

void(*BindFunctions)() = 0;

PFNGLGENBUFFERSPROC              glGenBuffers = 0;
PFNGLBINDBUFFERPROC              glBindBuffer = 0;
PFNGLBUFFERDATAPROC              glBufferData = 0;
PFNGLCREATEPROGRAMPROC           glCreateProgram = 0;
PFNGLCREATESHADERPROC            glCreateShader = 0;
PFNGLSHADERSOURCEPROC            glShaderSource = 0;
PFNGLCOMPILESHADERPROC           glCompileShader = 0;
PFNGLATTACHSHADERPROC            glAttachShader = 0;
PFNGLUSEPROGRAMPROC              glUseProgram = 0;
PFNGLVERTEXATTRIBPOINTERPROC     glVertexAttribPointer = 0;
PFNGLBINDATTRIBLOCATIONPROC      glBindAttribLocation = 0;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = 0;
PFNGLGETUNIFORMLOCATIONPROC		 glGetUniformLocation = 0;
PFNGLUNIFORM3FPROC				 glUniform3f = 0;
PFNGLLINKPROGRAMPROC			 glLinkProgram = 0;
PFNGLUNIFORM1FPROC				 glUniform1f = 0;
PFNGLACTIVETEXTUREPROC			 glActiveTexture = 0;
PFNGLUNIFORM1IPROC				 glUniform1i = 0;
PFNGLUNIFORMMATRIX4FVPROC        glUniformMatrix4fv = 0;