@echo off
call createDB.bat
call createDB.bat -n
call createDB.bat -v
call createDB.bat -n -v

call test jdk13
call test jdk12
call test jdk11
