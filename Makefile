CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
SOURCES = main.c history.c navigation.c search.c ui.c
TARGET = browser_history
all: $(TARGET)
$(TARGET): $(SOURCES) history.h
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)
clean:
	rm -f $(TARGET) browser_history_tests
.PHONY: all clean
