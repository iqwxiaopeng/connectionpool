main:
	g++ -I. -std=c++11 -o main main.cc mysql_connection.o /usr/lib/libmysqlclient_r.a -lpthread
mysql_result.o:
	 g++ -std=c++11 -I. -c mysql_connection.cc -o mysql_connection.o
clean:
	rm main

