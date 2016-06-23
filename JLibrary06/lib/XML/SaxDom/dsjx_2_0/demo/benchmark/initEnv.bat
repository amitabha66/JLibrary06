@echo off

set jdk11_home=C:\Java\jdk1.1
set jdk12_home=C:\Java\jdk1.2
set jdk13_home=C:\Java\jdk1.3

set benchmark_cp=benchmark.jar;..\..\lib\saxdomix.jar
set jdk11_cp=%benchmark_cp%;%jdk11_home%\lib\classes.zip
set jdk12_cp=%benchmark_cp%
set jdk13_cp=%benchmark_cp%

set javamx=200
set jdk11_java=java -mx%javamx%m
set jdk12_java=java -Xmx%javamx%m
set jdk13_java=java -Xmx%javamx%m 

set jaxp10=C:\Java\ext\jaxp-1.0\jaxp.jar;C:\Java\ext\jaxp-1.0\parser.jar
set jaxp11=C:\Java\ext\jaxp-1.1\jaxp.jar;C:\Java\ext\jaxp-1.1\crimson.jar;C:\Java\ext\jaxp-1.1\xalan.jar
set xerces12=D:\xml\apache\xerces-1_2_3\xerces.jar
set xerces13=D:\xml\apache\xerces-1_3_0\xerces.jar;D:\xml\apache\xalan-2_0_0\bin\xalan.jar
set xerces14=D:\xml\apache\xerces-1_4_0\xerces.jar;D:\xml\apache\xalan-2_0_0\bin\xalan.jar

set mainClass1=com.devsphere.xml.benchmark.Main1
set mainClass2=com.devsphere.xml.benchmark.Main2

set rcStart=0
set rcStep=10000
set rcEnd=50000

set rcFixed=500
set thStart=0
set thStep=20
set thEnd=100
