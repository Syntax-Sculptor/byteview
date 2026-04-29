byteview:
	gcc src/byte_view.c -o byte_view -Wall -std=c2x

clean:
	rm -rf byte_view