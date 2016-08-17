include ../makefile.inc

all : ${INC_LIB}

${INC_LIB} : *.c
	${CC} -c -g ${CFLAGS} *.c
	${RM} ${INC_LIB}
	${AR} rs {INC_LIB} *.o

clean :
	${RM} *.o ${INC_LIB}
