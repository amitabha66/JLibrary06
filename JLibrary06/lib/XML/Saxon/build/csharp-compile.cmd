

rem ====================================================
rem         compile the API files
rem ====================================================

rem param 1: source code directory e.g. MyJava\build\n\csource
rem param 2: .NET dll dir e.g. MyJava\build\n\dll

set Path=C:\Program Files\Microsoft.NET\SDK\v1.1\Bin\;C:\WINDOWS\Microsoft.NET\Framework\v1.1.4322\;C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\bin\;C:\Program Files\Microsoft Visual Studio .NET 2003\Common7\IDE\;%PATH%
set LIB=C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\lib\;"C:\Program Files\Microsoft.NET\SDK\v1.1\Lib\";%LIB%
set INCLUDE=C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\include\;"C:\Program Files\Microsoft.NET\SDK\v1.1\include\";%INCLUDE%

set APISOURCE=%1/api/Saxon.Api
set CMDSOURCE=%1/cmd
set SMPSOURCE=%1/samples
set DLLDIR=%2

cd %APISOURCE%

csc /target:module /out:%DLLDIR%/saxon8api.netmodule /doc:../apidoc.xml /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/IKVM.Runtime.dll;%DLLDIR%/saxon8.dll;%DLLDIR%/saxon8sa.dll *.cs
al /keyfile:c:\MyDotNet\make\saxondotnet.snk /comp:Saxonica /prod:Saxon /v:8.9.0.1 %DLLDIR%/saxon8api.netmodule /out:%DLLDIR%/saxon8api.dll

rem =====================================================
rem - install saxon8api assembly in the Global Assembly Cache
rem =====================================================

cd %DLLDIR%
set NET="c:\Program Files\Microsoft.NET\SDK\v1.1\Bin"
%NET%\gacutil /if saxon8api.dll 


rem ====================================================
rem         compile the command files
rem ====================================================


cd %CMDSOURCE%

csc /target:exe /win32icon:c:\MyDotNet\icons\gyfu.ico ^
    /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/IKVM.Runtime.dll;%DLLDIR%/saxon8.dll;%DLLDIR%/saxon8sa.dll ^
    /out:%DLLDIR%/Transform.exe ^
    Transform.cs
csc /target:exe /win32icon:c:\MyDotNet\icons\gyfu.ico ^
    /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/IKVM.Runtime.dll;%DLLDIR%/saxon8.dll;%DLLDIR%/saxon8sa.dll ^
    /out:%DLLDIR%/Query.exe ^
    Query.cs
csc /target:exe /win32icon:c:\MyDotNet\icons\gyfu.ico ^
    /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/IKVM.Runtime.dll;%DLLDIR%/saxon8.dll;%DLLDIR%/saxon8sa.dll ^
    /out:%DLLDIR%/Validate.exe ^
    Validate.cs


rem =====================================================
rem         compile the issued sample applications
rem =====================================================


cd %SMPSOURCE%

csc  /target:exe /win32icon:c:\MyDotNet\icons\csharp.ico /debug+ ^
		 /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/saxon8api.dll ^
		 /out:%DLLDIR%/samples/XQueryExamples.exe ^
		 XQueryExamples.cs
csc  /target:exe /win32icon:c:\MyDotNet\icons\csharp.ico /debug+ ^
     /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/saxon8api.dll ^
     /out:%DLLDIR%/samples/XPathExample.exe ^
     XPathExample.cs
csc  /target:exe /win32icon:c:\MyDotNet\icons\csharp.ico /debug+ ^
     /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/saxon8api.dll ^
     /out:%DLLDIR%/samples/XsltExamples.exe ^
     XsltExamples.cs
csc  /target:exe /win32icon:c:\MyDotNet\icons\csharp.ico /debug+ ^
     /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/saxon8api.dll ^
     /out:%DLLDIR%/samples/SchemaExamples.exe ^
     SchemaExamples.cs

rem =====================================================
rem           compile test drivers
rem =====================================================

csc  /target:exe /win32icon:c:\MyDotNet\icons\csharp.ico /debug+ ^
     /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/saxon8api.dll ^
     /out:%DLLDIR%/tests/XsltTestSuiteDriver.exe ^
     XsltTestSuiteDriver.cs
csc  /target:exe /win32icon:c:\MyDotNet\icons\csharp.ico /debug+ ^
     /r:%DLLDIR%/IKVM.GNU.Classpath.dll;%DLLDIR%/saxon8api.dll ^
     /out:%DLLDIR%/tests/XQueryTestSuiteDriver.exe ^
     XQueryTestSuiteDriver.cs



