#include "EnginePCH.h"
#include "TLGE_Windows.h"

using namespace TLGE;

int WINAPI WinMain(HINSTANCE aInstanceHandle, HINSTANCE aPreviousInstanceHandle, LPSTR aComandLine, int aShowCommand)
{
	//Setting initial variables for later use
	GameCore* gameCore = GameCore::GetInstance();
	WindowManager_Windows* windowManager = new WindowManager_Windows();
	gameCore->SetWindowManager(windowManager);

	windowManager->SetInstanceHandle(aInstanceHandle);
	windowManager->SetShowCommand(aShowCommand);

	BindFunctions = WIN32_BindFunctions;
	
	//Going to user main
	return User_main();
}

LRESULT CALLBACK WndProc(HWND aWindowHandle, UINT aMessage, WPARAM aUnsignedIntParam, LPARAM aLongParam)
{
	switch (aMessage)
	{
	case WM_MOUSEMOVE:
		{
			MouseMove* move = new MouseMove();
			move->SetPosition(glm::ivec2(GET_X_LPARAM(aLongParam), GET_Y_LPARAM(aLongParam)));
			GameCore::GetInstance()->AddEvent(move);

			TRACKMOUSEEVENT tme;
			tme.cbSize = sizeof(tme);
			tme.hwndTrack = aWindowHandle;
			tme.dwFlags = TME_LEAVE;
			tme.dwHoverTime = 1;
			TrackMouseEvent(&tme);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		GameCore::GetInstance()->AddEvent(new OnQuitEvent());
		break;
	case WM_LBUTTONDOWN:
		{
			ClickEvent* click = new ClickEvent();
			click->SetPosition(glm::ivec2(GET_X_LPARAM(aLongParam), GET_Y_LPARAM(aLongParam)));
			click->SetState(ClickState_JustClicked);
			GameCore::GetInstance()->AddEvent(click);
		}
		break;
	case WM_MOUSELEAVE:
		{
			MouseLeaveEvent* leave = new MouseLeaveEvent();
			GameCore::GetInstance()->AddEvent(leave);
		}
		break;
	case WM_LBUTTONUP:
		{
			ClickEvent* click = new ClickEvent();
			click->SetPosition(glm::ivec2(GET_X_LPARAM(aLongParam), GET_Y_LPARAM(aLongParam)));
			click->SetState(ClickState_Unclicked);
			GameCore::GetInstance()->AddEvent(click);
		}
		break;
	case WM_KEYDOWN:
		{
			KeyEvent* key = new KeyEvent();
			key->SetKey(aUnsignedIntParam);
			key->SetState(KeyState_JustPressed);
			GameCore::GetInstance()->AddEvent(key);
		}
		break;
	case WM_KEYUP:
		{
			KeyEvent* key = new KeyEvent();
			key->SetKey(aUnsignedIntParam);
			key->SetState(KeyState_Unpressed);
			GameCore::GetInstance()->AddEvent(key);
		}
	break;
	case WM_SIZE:
		{
			ResizeEvent* resize = new ResizeEvent();
			resize->SetSize(glm::ivec2(LOWORD(aLongParam), HIWORD(aLongParam)));
			GameCore::GetInstance()->AddEvent(resize);
		}
		break;
	default:
		return DefWindowProc(aWindowHandle, aMessage, aUnsignedIntParam, aLongParam);
		break;
	}

	return 0;
}

void WIN32_BindFunctions()
{
	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
}