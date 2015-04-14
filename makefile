main:mysql_connection.o  mysql_result.o
	g++ -I. -std=c++11 -o main main.cc mysql_connection.o  mysql_result.o /usr/lib/libmysqlclient_r.a -lpthread
mysql_connection.o:
	 g++ -std=c++11 -I. -c mysql_connection.cc -o mysql_connection.o
mysql_result.o:
	g++ -std=c++11 -I. -c mysql_result.cc -o mysql_result.o
clean:
	rm main mysql_connection.o mysql_result.o

