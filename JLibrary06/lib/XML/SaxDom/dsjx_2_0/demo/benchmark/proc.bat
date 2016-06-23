@echo off
rem proc jdk parser method -1/-2 [-n] [-v]
call initEnv
call setEnv %1 %2 %3 %4 %5 %6
echo %test% %1 %2 %3 %4 %5 %6
call %test%Loop %3 %5 %6 >%test%_%output%.txt
