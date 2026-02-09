CC=gcc
CFLAGS=-Wall -Wextra -fPIC -Iinclude
LDFLAGS=-shared

TARGET=libmysyslog.so
SRC=src/mysyslog.c
OBJ=$(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)