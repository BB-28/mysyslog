CC=gcc
CFLAGS=-Wall -Wextra -fPIC -I../libmysyslog/include
LDFLAGS=-shared

TARGET=libmysyslog-json.so
SRC=src/driver_json.c
OBJ=$(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)