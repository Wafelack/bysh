@echo off
title ByPass Shell
set starting_dir="C:\Users\%username%"
cd %starting_dir%
cls
:loop
set /p cmd="%username% %% "
%cmd%
goto :loop