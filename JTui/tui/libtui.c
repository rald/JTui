#include "libtui.h"

#include "Tui.h"

JNIEXPORT void JNICALL Java_Tui_clrscr(JNIEnv *env, jobject obj) {
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen={0,0};    
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	DWORD dwConSize;                 
	GetConsoleScreenBufferInfo(hConsole,&csbi);
	dwConSize=csbi.dwSize.X*csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole,' ',dwConSize,coordScreen,&cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole,&csbi);
	FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
	SetConsoleCursorPosition(hConsole,coordScreen);
}

JNIEXPORT void JNICALL Java_Tui_gotoxy(JNIEnv *env, jobject obj, jint x, jint y) {
	COORD coord;
	coord.X=x-1;
	coord.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

JNIEXPORT void JNICALL Java_Tui_setTextAttribute(JNIEnv *env, jobject obj, jint wAttributes) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wAttributes);
}

JNIEXPORT jint JNICALL Java_Tui_getch(JNIEnv *env, jobject obj) {
	return _getch();
}

JNIEXPORT jint JNICALL Java_Tui_kbhit(JNIEnv *env, jobject obj) {
	return _kbhit();
}

JNIEXPORT void JNICALL Java_Tui_hideCursor(JNIEnv *env, jobject obj) {
  CONSOLE_CURSOR_INFO info;
  info.dwSize=100;
  info.bVisible=FALSE;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}

JNIEXPORT void JNICALL Java_Tui_showCursor(JNIEnv *env, jobject obj) {
  CONSOLE_CURSOR_INFO info;
  info.dwSize=100;
  info.bVisible=TRUE;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}

JNIEXPORT void JNICALL Java_Tui_setCursorSize(JNIEnv *env, jobject obj, jint size) {
  CONSOLE_CURSOR_INFO info;
  info.dwSize=size;
  info.bVisible=TRUE;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}

JNIEXPORT jint JNICALL Java_Tui_getWidth(JNIEnv *env, jobject obj) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.srWindow.Right-csbi.srWindow.Left+1;
}

JNIEXPORT jint JNICALL Java_Tui_getHeight(JNIEnv *env, jobject obj) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.srWindow.Bottom-csbi.srWindow.Top+1;
}

JNIEXPORT void JNICALL Java_Tui_setWindow(JNIEnv *env, jobject obj, jint left, jint top, jint right, jint bottom, jboolean absolute) {
  SMALL_RECT rect = {left, top, right, bottom};
  COORD coord = {right-left+1, bottom-top+1};
  SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord);
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),absolute,&rect);
  SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
