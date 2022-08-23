class Tui {

	public native void clrscr();
	public native void gotoxy(int x,int y);
	public native void setTextAttribute(int attributes);
	public native int getch();
	public native int kbhit();
  public native void hideCursor();
  public native void showCursor();
  public native void setCursorSize(int size);
  public native int getWidth();
  public native int getHeight();
  public native void setWindow(int left, int top, int right, int bottom, boolean absolute);
  
  

	public Tui() {
    System.load("C:/dev/JTui/tui/libtui.dll"); // absolute path of libtui.dll
	}

}
