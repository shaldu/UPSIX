# Makefile
SRCS := main.cpp

# Detect the operating system
ifeq ($(shell uname -s),Darwin)
    # Mac OS X
    CXX := clang++
    CXXFLAGS := -std=c++17 -I includes/frameworks/SDL2.framework/Headers -I includes/entt/include -I includes/glm -I src
    LFLAGS := -F includes/frameworks -framework SDL2
	OBJS :=
	TARGET :=main.cpp src/*
	RUN_TARGET := ./app.out
	APP := SlimeStrike
else
    # Assume Windows
    CXX := g++ # or use your Windows C++ compiler
    CXXFLAGS := -std=c++17
	SDL_LIB := -L includes/SDL2/src/lib
	SDL_INCLUDE := -I includes/SDL2/src/include/SDL2 includes/entt/include -I src -I includes/glm
    LFLAGS := -lmingw32 -lSDL2main -lSDL2
	TARGET := main.exe
	SRC := main.cpp src/*
	RUN_TARGET := .\main.exe
endif

# Build target
mac:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) $(TARGET) $(LFLAGS)
	mv a.out app.out
	$(RUN_TARGET)
	
# Run target windows
win:
	$(CXX) $(CXXFLAGS) $(SDL_INCLUDE) $(SRC) $(SDL_LIB) ${LFLAGS} -o $(TARGET) -static-libstdc++ -mwindows
	$(RUN_TARGET)

run:
	$(RUN_TARGET)

buildmac:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) $(TARGET) $(LFLAGS)
	mv a.out app.out

	rm -rf $(APP)
	mkdir $(APP)

	cp app.out $(APP)
	
	chmod +x $(APP)/app.out

	mkdir $(APP)/Contents
	mkdir $(APP)/Contents/MacOS

	cp -R includes $(APP)/Contents/MacOS
	cp -R res $(APP)/Contents/MacOS
	cp -R info.plist $(APP)/Contents/MacOS
	cp -R SlimeStrike.png $(APP)/Contents/MacOS
	mv $(APP)/app.out $(APP)/Contents/MacOS
	zip -r $(APP) . -i $(APP).app

clean:
	rm -rf ./src/*.gch