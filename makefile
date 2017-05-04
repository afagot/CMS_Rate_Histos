#file: Makefile
#
# test program for CMS RPC
#
# 14/01/14  A.Fagot
# from makefile created by Y.Benhammou


DAQ_BIN_DIR  = ./bin
DAQ_OBJ_DIR  = ./obj

CC = g++ -std=c++11

ROOT_INC     := $(ROOTSYS)/include
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)

LFLAGS       := -Llib -L/usr/lib \
                $(ROOTLIBS)

CFLAGS       := -ggdb -fPIC -DLINUX -Wall -funsigned-char \
                -I$(ROOT_INC) -I$(ROOTCFLAGS)

all: $(DAQ_BIN_DIR) $(DAQ_OBJ_DIR) plot

plot: 	main.o make_plot.o
	g++ $(CFLAGS) $(DAQ_OBJ_DIR)/main.o \
	$(DAQ_OBJ_DIR)/make_plot.o \
        -o $(DAQ_BIN_DIR)/plot \
        $(LFLAGS)  \
        -l curses

main.o:
	$(CC) $(CFLAGS) -c main.cc -o $(DAQ_OBJ_DIR)/main.o
make_plot.o:
	$(CC) $(CFLAGS) -c make_plot.cc -o $(DAQ_OBJ_DIR)/make_plot.o


$(DAQ_BIN_DIR):
	mkdir -p $(DAQ_BIN_DIR)/

$(DAQ_OBJ_DIR):
	mkdir -p $(DAQ_OBJ_DIR)/

clean:
	rm -rf $(DAQ_BIN_DIR)/
	rm -rf $(DAQ_OBJ_DIR)/

remove:
	rm -rf $(DAQ_BIN_DIR)/
	rm -rf $(DAQ_OBJ_DIR)/

