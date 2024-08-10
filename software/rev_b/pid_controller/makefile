all:
	g++ -c -fPIC lib/pid.cpp -Ilib
	g++ -shared -Wl,-soname,libpid.so -o libpid.so  pid.o 
