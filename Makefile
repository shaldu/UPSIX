# Makefile
SRCS := main.cpp

# Detect the operating system
ifeq ($(shell uname -s),Darwin)
    # Mac OS X
    CXX := clang++
    CXXFLAGS := -std=c++17 -I frameworks/SDL2.framework/Headers -I frameworks/SDL2_ttf.framework/Headers -I frameworks/SDL2_image.framework/Headers -I entt/include
    LFLAGS := -F frameworks -framework SDL2 -framework SDL2_ttf -framework SDL2_image
	OBJS :=
	TARGET := main.cpp src/*
	RUN_TARGET := ./app.out
else
	# Windows 

endif

# Build target
mac:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) $(TARGET) $(LFLAGS)
	mv a.out app.out
	$(RUN_TARGET)
	
# Run target windows
win:


clean:
	rm -rf ./src/*.gch