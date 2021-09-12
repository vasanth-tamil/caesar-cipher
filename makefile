GC=gcc
flag32=-m32
flag64=-m64
out=-o

compile-64 :
	$(GC) $(flag64) $(out) caesar-cipher caesar-cipher.c

compile-32 :
	$(GC) $(flag32) $(out) caesar-cipher caesar-cipher.c 

rm : 
	rm -rf caesar-cipher
