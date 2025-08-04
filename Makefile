TARGET = chess

build:
	gcc main.c move.c -o $(TARGET)

clean:
	rm -f $(TARGET)
