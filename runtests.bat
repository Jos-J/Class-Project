@echo off
REM Compile test runner
g++ -o tests/test-runner tests/test.cpp student.cpp roster.cpp
IF %ERRORLEVEL% NEQ 0 (
    echo Compilation failed.
    pause
    exit /b %ERRORLEVEL%
)

REM Run the test runner
./tests/test-runner

pause
