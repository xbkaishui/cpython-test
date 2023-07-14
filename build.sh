下面是Python2的编译方式，Python3的话，只需要将Python的库路径改成Python3的即可
g++ -I/usr/include/python3.8 -c main.cpp
g++ -o main main.o -L/usr/local/lib -lpython3.8 -lrt -lpthread -lutil -ldl