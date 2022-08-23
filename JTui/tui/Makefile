all: Tui.class Tui.h libtui.dll libtui.def Snake.class

Tui.class: Tui.java
	..\jdk1.1.8\bin\javac Tui.java

Tui.h: Tui.class
	..\jdk1.1.8\bin\javah -jni Tui

libtui.dll: libtui.c libtui.h Tui.h
	..\tcc\tcc -I. -Itui -I..\jdk1.1.8\include -I..\jdk1.1.8\include\win32 -shared -o libtui.dll libtui.c

libtui.def: libtui.dll
	..\tcc\tcc -impdef libtui.dll -o libtui.def

Snake.class: Snake.java libtui.dll
	..\jdk1.1.8\bin\javac Snake.java

.PHONY: clean

clean:
	cmd /C del Tui.class Tui.h libtui.dll libtui.def Snake.class
