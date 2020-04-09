@echo off

set WindowsLib=opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib


mkdir bin
cd bin
cl ../build.c /Fe%cd%/Ch1mage /Zi /MD %WindowsLib% /link
start Ch1mage.exe
cd ..