@echo off
rem For each file in your folder
for %%a in ("*.asm") do (
 cmd /c nasm -fobj %%a
)

set var=
setlocal enabledelayedexpansion
for %%a in ("*.obj") do (
   echo %%a
    set var=!var! %%a
)

echo %var%
cmd /k "alink %var% -oPE -subsys console -entry start"
endlocal

