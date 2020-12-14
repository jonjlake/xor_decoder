TARGET = xor_decoder
OBJECT = xor_decoder.o

all: $(OBJECT)
	gcc -o $(TARGET) $(OBJECT)

$(OBJECT) : xor_decoder.c
	gcc -c xor_decoder.c

clean:
	rm $(TARGET) $(OBJECT)
