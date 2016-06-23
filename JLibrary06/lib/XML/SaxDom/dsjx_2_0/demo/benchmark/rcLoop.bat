rem rcLoop method [-n] [-v]
%jdk_java% %mainClass% %1 %rcStart% 0 %2 %3 > nul
for /L %%c in (%rcStart%, %rcStep%, %rcEnd%) do %jdk_java% %mainClass% %1 %%c 0 %2 %3
