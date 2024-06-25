:: /-------------------------------------------------/
:: / Simple batch script to compile Game of Life C++ /
:: / Program on Windows machines.                    /
:: / Author: Zachary Pedigo                          /
:: /-------------------------------------------------/

@echo off

echo Compiling...
g++ -o main Cell.cpp Board.cpp main.cpp

if exist main.exe (
echo Compilation Successful!
)

