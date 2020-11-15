@echo off
color 0a


:menu
cls
echo Compile debug[1],Compile and run debug[2], Compile release[3], Compile and release[4], Exit[5]
set /p user= 

if %user% == 1 goto compileDebug

if %user% == 2 goto compileRunDebug

if %user% == 3 goto compileRelease

if %user% == 4 goto compileRunRelease

if %user% == 5 exit

:compileDebug
cls
echo Compiling for debug...
echo.
g++ -c src/*.cpp -std=c++14 -I include -Werror -Wfatal-errors -I C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\include
g++ *.o -o bin/debug/Game.exe -L C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
pause >nul
goto menu

:compileRunDebug
cls
echo Compiling for runDebug...
echo.
g++ -c src/*.cpp -std=c++14 -I include -Werror -Wfatal-errors -I C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\include
g++ *.o -o bin/debug/Game.exe -L C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
"bin/debug/Game.exe"

goto menu

:compileRelease
cls
echo Compiling for release...
echo.
g++ -c src/*.cpp -std=c++14 -I include -Werror -Wfatal-errors -I C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\include -O3 -s -fexpensive-optimizations
g++ *.o -o bin/release/Game.exe -L C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
pause >nul
goto menu

:compileRunRelease
cls
echo Compiling and Running release...
echo.
g++ -c src/*.cpp -std=c++14 -I include -Werror -Wfatal-errors -I C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\include -O3 -s -fexpensive-optimizations
g++ *.o -o bin/release/Game.exe -L C:\Users\gamer\Desktop\sfml\MingwSfml\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
"bin/release/Game.exe"

goto menu
