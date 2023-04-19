#####################################################
# You may need to change the parameters under here. #
#####################################################

# Step 1: Choose a compiler. By default, use clang++

# If you use clang++, make sure the following line does not start with a comment (#)
#CXX=clang++
# If you use g++, uncomment the following line
CXX=g++

# Set default compiler parameters
# -Wall 	shows all warnings when compiling, always use this!
# -std=c++11 	enables the C++11 standard mode
CXXFLAGS = -Wall -std=c++11

# Step 2: If you use clang++ under Mac OS X, remove these comments
#CXXFLAGS += -stdlib=libc++
#LFLAGS += -stdlib=libc++

# Step 3: Run 'make' in the same directory as this file


############################
# Settings for the library #
############################


# Compiler flag -Idir specifies, that there are includes in the 'dir' directory
LIB_CXXFLAGS = $(CXXFLAGS) -Iinclude

# List of objects for the library
LIBOBJS = obj/point2.o obj/Line2.o obj/Circle2.o

# Name of the library
LIBRARY = lib/libgeometry.a

################################
# Settings for the testing app #
################################

# Compiler flags for the testing app
APP_CXXFLAGS = $(CXXFLAGS) -Iinclude

# Linker flags (order the compiler to link with our library)
LFLAGS += -Llib -lgeometry

# The object for the testing app
TESTOBJS = obj/geometrytest.o

# The name of the testing app
TESTAPP = bin/geometrytest

# This is the first target. It will be built when you run 'make' or 'make build'
build: $(LIBRARY)

# Create the library by using 'ar'
$(LIBRARY) : $(LIBOBJS)
	ar cr $(LIBRARY) $(LIBOBJS)

# Compile each source file of the librar
obj/point2.o: src/point2.cpp
	$(CXX) $(LIB_CXXFLAGS) -c src/point2.cpp -o obj/point2.o

obj/Line2.o: src/Line2.cpp
	$(CXX) $(LIB_CXXFLAGS) -c src/Line2.cpp -o obj/Line2.o

obj/Circle2.o: src/Circle2.cpp
	$(CXX) $(LIB_CXXFLAGS) -c src/Circle2.cpp -o obj/Circle2.o

# Rule for linking the test app with our library
$(TESTAPP): $(TESTOBJS) $(LIBRARY)
	$(CXX) $(TESTOBJS) -o $(TESTAPP) $(LFLAGS) 

# Compile each source file of the library
obj/geometrytest.o: tests/geometrytest.cpp
	$(CXX) $(APP_CXXFLAGS) -c tests/geometrytest.cpp -o obj/geometrytest.o 

test: $(TESTAPP)
	./$(TESTAPP)

doc:
	doxygen

clean:
	rm -f $(LIBOBJS)
	rm -f $(TESTOBJS)
	rm -f $(LIBRARY)
	rm -f $(TESTAPP)
