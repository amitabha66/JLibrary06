@echo off
rem setEnv jdk parser method -1/-2 [-n] [-v]

set jdk_home=
if %1==jdk11 set jdk_home=%jdk11_home%
if %1==jdk12 set jdk_home=%jdk12_home%
if %1==jdk13 set jdk_home=%jdk13_home%

set jdk_cp=
if %1==jdk11 set jdk_cp=%jdk11_cp%
if %1==jdk12 set jdk_cp=%jdk12_cp%
if %1==jdk13 set jdk_cp=%jdk13_cp%

set jdk_java=
if %1==jdk11 set jdk_java=%jdk11_java%
if %1==jdk12 set jdk_java=%jdk12_java%
if %1==jdk13 set jdk_java=%jdk13_java%

set parser=
if %2==jaxp10 set parser=%jaxp10%
if %2==jaxp11 set parser=%jaxp11%
if %2==xerces11 set parser=%xerces11%
if %2==xerces12 set parser=%xerces12%
if %2==xerces13 set parser=%xerces13%
if %2==xerces14 set parser=%xerces14%

set mainClass=
if "%4"=="-1" set mainClass=%mainClass1%
if "%4"=="-2" set mainClass=%mainClass2%

if "%4"=="-1" set output=1
if "%4"=="-2" set output=2
if "%5"=="-n" set output=%output%n
if "%6"=="-n" set output=%output%n
if "%5"=="-v" set output=%output%v
if "%6"=="-v" set output=%output%v
set output=%output%_%1_%2_%3

set PATH=%jdk_home%\bin

set CLASSPATH=%jdk_cp%;%parser%
