call "D:\SW\Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
set compilerflags=/Od /Zi /EHsc -Wall
set linkerflags=/OUT:main.exe
cl.exe %compilerflags% ring_buffer_test.c ring_buffer.c /link %linkerflags%