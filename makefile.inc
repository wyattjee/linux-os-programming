# This is the common definitions using by subdir makefiles

ROOT = ..
LIB_DIR = ${ROOT}/lib
LIB = ${LIB_DIR}/libcommon.a

CFLAGS = -std=c99 \
		 -g -I${LIB_DIR} \
		 -Wall \

RM = rm -f
