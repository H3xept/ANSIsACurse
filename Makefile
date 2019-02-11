CC = gcc
CFLAGS = -Wall --pedantic --std=c99
SOURCE_FOLDER = src
OUT_FOLDER = bin
SOURCE_FILES = $(SOURCE_FOLDER)/*.c
LIB_NAME = libansisacurse.a

all: compile_dylib copy_headers
	
compile_dylib: taget_dir 
	@ echo "Compiling dylib..."
	@ $(CC) $(CFLAGS) $(SOURCE_FILES) -c
	@ ar rs $(LIB_NAME) *.o
	@ cp $(LIB_NAME) bin/libs
	@ rm *.o $(LIB_NAME)

copy_headers: taget_dir
	@ echo "Copying headers..."
	@ cp $(SOURCE_FOLDER)/*.h $(OUT_FOLDER)/headers/

taget_dir:
	@ echo "Creating folder structure..."
	@ mkdir -p bin/headers
	@ mkdir -p bin/libs

clean:
	rm -rf bin/