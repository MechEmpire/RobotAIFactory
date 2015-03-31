#RobotAIFactory
#makefile for g++ linux

CC=g++
CFLAGS=-Wall

#INCLUDE_PATH = -I/home/shrekshao/Downloads/lua-5.2.3/install/include/
#LIB_PATH = -L/home/shrekshao/Downloads/lua-5.2.3/install/lib/
#LIBS = -llua

SRC_DIR = .
#VPATH = $(SRC_DIR)
VPATH += $(SRC_DIR)/myAI
VPATH += $(SRC_DIR)/sys


SRC_FILES = $(foreach n, $(VPATH), $(wildcard $(n)/*.cpp)) RobotAIFactoryLinux.cpp

OUTPUT_DIR=.
MYAI_DIR=./myAI


all:
	$(CC) -O2 -fPIC -shared -I $(MYAI_DIR) -o $(OUTPUT_DIR)/libmyAI.so $(SRC_FILES)
