rem parser jdk parser

echo %test% %1 %2

call proc %1 %2 sax -1
call proc %1 %2 saxdomix -1
call proc %1 %2 dom -1

call proc %1 %2 sax -1 -v
call proc %1 %2 saxdomix -1 -v
call proc %1 %2 dom -1 -v

if %2==jaxp10 goto skip_2

call proc %1 %2 sax -2
call proc %1 %2 saxdomix -2
if not %2==xerces12 call proc %1 %2 saxdomixt -2
call proc %1 %2 dom -2

call proc %1 %2 sax -2 -n
call proc %1 %2 saxdomix -2 -n
if not %2==xerces12 call proc %1 %2 saxdomixt -2 -n
call proc %1 %2 dom -2 -n

call proc %1 %2 sax -2 -v
call proc %1 %2 saxdomix -2 -v
if not %2==xerces12 call proc %1 %2 saxdomixt -2 -v
call proc %1 %2 dom -2 -v

call proc %1 %2 sax -2 -n -v
call proc %1 %2 saxdomix -2 -n -v
if not %2==xerces12 call proc %1 %2 saxdomixt -2 -n -v
call proc %1 %2 dom -2 -n -v

:skip_2
