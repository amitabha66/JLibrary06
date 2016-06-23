@echo off
rem test jdk

set test=rc
call parser %1 jaxp10
call parser %1 jaxp11
call parser %1 xerces12
call parser %1 xerces13
call parser %1 xerces14


set test=th
call parser %1 jaxp10
call parser %1 jaxp11
call parser %1 xerces12
call parser %1 xerces13
call parser %1 xerces14
