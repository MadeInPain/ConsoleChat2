#vars:
obj = src/server.cpp src/lin_socket.cpp

#targets:
app:
	g++ $(obj) -o server