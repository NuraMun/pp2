CC = g++
CFLAGS = -Wall -g
EXECUTABLE = comp
INSTALL_DIR = ~/pp 

all: $(EXECUTABLE)

$(EXECUTABLE): pp2.cpp ThreadsPool.cpp ThreadsPool.h
	$(CC) $(CFLAGS) pp2.cpp ThreadsPool.cpp -o $(EXECUTABLE)

install: $(EXECUTABLE)
	mkdir -p $(INSTALL_DIR)
	cp $(EXECUTABLE) $(INSTALL_DIR)

clean:
	rm -f $(EXECUTABLE)

cleanI:
	rm -f $(INSTALL_DIR)/$(EXECUTABLE)

.PHONY: all install clean cleanI
