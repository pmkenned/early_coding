@echo off
C:
CD C:\PROGRA~1\DIGITA~1\HELLOW~1\DEBUG
echo Compiling...
"..\..\BIN\DMC.EXE" -v "..\HelloWorld.cpp" > "debug_log.txt"
If %ERRORLEVEL%==0. (
	echo Compilation Successful
	echo Executing...
	HelloWorld.exe
) else (
	echo ERRORLEVEL = %ERRORLEVEL%
	echo View debug_log.txt [Y/N]?
	set /p userInput=
	If %userInput%==y type "debug_log.txt"
)