rem thLoop method  [-n] [-v]
%jdk_java% %mainClass% %1 0 %thStart% %2 %3 > nul
for /L %%t in (%thStart%, %thStep%, %thEnd%) do %jdk_java% %mainClass% %1 %rcFixed% %%t %2 %3
