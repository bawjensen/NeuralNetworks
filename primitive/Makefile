# OS := $(shell uname)

# ifeq ($(OS), Darwin)
# 	CLIBS= 		-framework OpenGL -framework GLUT # 2014
# 	CFLAGS=		$(CLIBS)
# else # Linux
# 	CLIBS= 		-lm -lglut -lGL -lGLU -lX11 # 2014
# 	CPATHS=		-I/usr/include -L/usr/lib # 2014
# 	CFLAGS=		$(CPATHS)$(CLIBS)
# endif

nn:			main.cpp netClass.cpp netClass.h
			g++ main.cpp netClass.cpp -o nn

# testing:		testing.cpp
# 			g++ testing.cpp -o testing -w $(CFLAGS)

# clean:
# 			rm *.o