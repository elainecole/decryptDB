CXX = g++
CXXFLAGS = -Wall -g -w

objects = decryptDB.o userControl.o aes.o

decryptDB: $(objects)
	$(CXX) $(CXXFLAGS) -o decryptDB $(objects)

decryptDB.o: decryptDB.cpp userControl.h aes.h
	$(CXX) $(CXXFLAGS) -c decryptDB.cpp

userControl.o: userControl.h

aes.o: aes.h

clean:
	rm -r decryptDB $(objects)
