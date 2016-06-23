
rem === This batch file builds the saxon8.dll and saxon8sa.dll assemblies,
rem === leaving them in c:\MyDotNet\bin\release. They are also moved into the
rem === General Assembly Cache. The script takes off where the Ant build finishes,
rem === that is with the two JAR files in c:/MyJava/build/temp/n/jar

rem === This file is designed to be invoked from task ikvmc in the Ant build file build.xml

rem === Set argument 1 to "debug" to build for development/debugging, or to "live" for live running
rem === Set argument 2 to the directory containing the JAR files
rem === Set argument 3 to the .NET "release" directory

set ASSEMBLY_NAME=saxon8
set SAXON_VERSION=8.9
set SAXON_NET_BUILD=0.1
set SAXON_NET_VERSION=%SAXON_VERSION%.%SAXON_NET_BUILD%
set SAXON_NET_RC=RC1
set IKVMVER=ikvm-0.32.0.0
set IKVM=c:\MyDotNet\%IKVMVER%\bin

set SAXON_BUILD_BN=c:\saxon-build\%SAXON_VERSION%\bn
set SAXON_BUILD_SAN=c:\saxon-build\%SAXON_VERSION%\san

set SAXON_JAR_DIR=%2



rem cd c:\MyDotNet\make


rem === Variables identifying release version ===

set SAXON_RELEASE_DIR=%3

rem mkdir %SAXON_RELEASE_DIR%
rem copy /y %IKVM%\IKVM.Runtime.dll %SAXON_RELEASE_DIR%\IKVM.Runtime.dll
rem copy /y %IKVM%\IKVM.GNU.Classpath.dll %SAXON_RELEASE_DIR%\IKVM.GNU.Classpath.dll

echo Building %ASSEMBLY_NAME% %SAXON_NET_VERSION% %SAXON_NET_RC% DLL 

rem use the two lines below when building for release...

if %1==debug goto c1debug

%IKVM%\ikvmc -assembly:saxon8 -target:library -keyfile:saxondotnet.snk -version:%SAXON_NET_VERSION% ^
             -debug -srcpath:c:\MyJava\saxon8.x %SAXON_JAR_DIR%\saxon8.jar ^
             -reference:mscorlib.dll -reference:System.Xml -reference:System ^
             -out:%SAXON_RELEASE_DIR%\saxon8.dll
%IKVM%\ikvmc -assembly:saxon8sa -target:library -keyfile:saxondotnet.snk -version:%SAXON_NET_VERSION% ^
             -reference:%SAXON_RELEASE_DIR%\saxon8.dll ^
             -reference:mscorlib.dll -reference:System.Xml -reference:System ^
             -reference:System.Security ^
             -debug -srcpath:c:\MyJava\saxon8.x %SAXON_JAR_DIR%\saxon8sa.jar ^
             -out:%SAXON_RELEASE_DIR%\saxon8sa.dll

rem Need to install the dlls in the Global Assembly Cache now for the rest of the script to work

cd %SAXON_RELEASE_DIR%
set NET="c:\Program Files\Microsoft.NET\SDK\v1.1\Bin"
%NET%\gacutil /if saxon8.dll 
%NET%\gacutil /if saxon8sa.dll 

goto c1resume

:c1debug
rem use the two lines below when building debug version...

%IKVM%\ikvmc -assembly:saxon8 -target:library -srcpath:%SRC% -debug  c:\MyDotNet\make\saxon8.jar
%IKVM%\ikvmc -assembly:saxon8sa -target:library -reference:saxon8.dll  -debug -srcpath:%SRC% c:\MyDotNet\make\saxon8sa.jar

:c1resume
