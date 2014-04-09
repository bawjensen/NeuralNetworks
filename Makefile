# OS := $(shell uname)

# ifeq ($(OS), Darwin)
# 	CLIBS= 		-framework OpenGL -framework GLUT # 2014
# 	CFLAGS=		$(CLIBS)
# else # Linux
# 	CLIBS= 		-lm -lglut -lGL -lGLU -lX11 # 2014
# 	CPATHS=		-I/usr/include -L/usr/lib # 2014
# 	CFLAGS=		$(CPATHS)$(CLIBS)
# endif

nn:			main.cpp networkClass.cpp networkClass.h
			g++ main.cpp networkClass.cpp -o nn

nnp:		mainPrimitive.cpp networkClassPrimitive.cpp networkClassPrimitive.h
			g++ mainPrimitive.cpp networkClassPrimitive.cpp -o nnp

# testing:		testing.cpp
# 			g++ testing.cpp -o testing -w $(CFLAGS)

# clean:
# 			rm *.o