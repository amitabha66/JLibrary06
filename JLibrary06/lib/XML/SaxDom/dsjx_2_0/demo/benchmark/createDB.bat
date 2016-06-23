@echo off
rem createDB [-n] [-v]
call initEnv
call setEnv jdk13 xerces14 sax -2
%jdk_java% %mainClass% create %rcFixed% 0 %1 %2 > nul
for /L %%c in (%rcStart%, %rcStep%, %rcEnd%) do %jdk_java% %mainClass% create %%c 0 %1 %2 > nul
