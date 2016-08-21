include ../makefile.inc

all : ${LIB}

${LIB} : *.c 
	${CC} -c -g ${CFLAGS} *.c
	${AR} rs ${LIB} *.o

clean :
	${RM} *.o ${LIB}
