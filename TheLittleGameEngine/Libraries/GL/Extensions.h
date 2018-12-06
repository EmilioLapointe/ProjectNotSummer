#ifndef __TLGE__EXTENSIONS_H__
#define __TLGE__EXTENSIONS_H__

extern void (*BindFunctions)();

//GL functions that need binding
extern PFNGLGENBUFFERSPROC              glGenBuffers;
extern PFNGLBINDBUFFERPROC              glBindBuffer;
extern PFNGLBUFFERDATAPROC              glBufferData;
extern PFNGLCREATEPROGRAMPROC           glCreateProgram;
extern PFNGLCREATESHADERPROC            glCreateShader;
extern PFNGLSHADERSOURCEPROC            glShaderSource;
extern PFNGLCOMPILESHADERPROC           glCompileShader;
extern PFNGLATTACHSHADERPROC            glAttachShader;
extern PFNGLUSEPROGRAMPROC              glUseProgram;
extern PFNGLVERTEXATTRIBPOINTERPROC     glVertexAttribPointer;
extern PFNGLBINDATTRIBLOCATIONPROC      glBindAttribLocation;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLGETUNIFORMLOCATIONPROC		glGetUniformLocation;
extern PFNGLUNIFORM3FPROC				glUniform3f;
extern PFNGLLINKPROGRAMPROC				glLinkProgram;
extern PFNGLUNIFORM1FPROC				glUniform1f;
extern PFNGLACTIVETEXTUREPROC			glActiveTexture;
extern PFNGLUNIFORM1IPROC				glUniform1i;
extern PFNGLUNIFORMMATRIX4FVPROC        glUniformMatrix4fv;

#endif