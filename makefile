.POSIX:
CPP	= g++
CPPFLAGS = -g -Wall -O3

all: adcom char_count
adcom: main.o encoder.o htree.o
	$(CPP) $(LDFLAGS) -o adcom main.o encoder.o htree.o $(LDLIBS)
char_count: char_count.o
	$(CPP) $(LDFLAGS) -o char_count char_count.o $(LDLIBS)
main.o: main.cc 
encoder.o: encoder.cc encoder.h define.h
htree.o: htree.cc htree.h define.h
char_count.o: char_count.cc
clean:
	rm -f adcom char_count main.o encoder.o htree.o char_count.o
