packed:
	gcc packed.c -o myexe

pack_run:
	./myexe ${ARGS} 

clean:
	rm myexe

unpacked:
	gcc unpacked.c -o myexe1

unpack_run:
	./myexe1 ${ARGS}

clean1:
	rm myexe1
	

