include ../makefile.inc

all : ${LIB}

${LIB} : *.c 
	${CC} -c -g ${CFLAGS} *.c
	${RM} ${INC_LIB}
	${AR} rs ${LIB} *.o

clean :
	${RM} *.o ${LIB}
