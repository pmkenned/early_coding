@echo off
:1
set /a a=%RANDOM%/3276
set /a b=%RANDOM%/3276
:echo SYSTEM FAILURE
:echo 
color %a%%b%
goto 1
