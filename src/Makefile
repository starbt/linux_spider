TARGET=spider
SOURCES=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SOURCES))

CXX:=g++
OPTIMIZATION?=-O2 -DNDEBUG
WARNINGS=-Wall -g
#WARNINGS=-Wall -Werror
REAL_CXXFLAGS=$(OPTIMIZATION) $(CXXFLAGS) $(WARNINGS) $(DEBUG) $(PROF) 
REAL_LDFLAGS=$(LDFLAGS) $(PROF) -rdynamic -lpthread -ldl


#$(CXX) -o $@ $(REAL_LDFLAGS) $^

all: $(TARGET)
	@if [ ! -d ../download ]; then mkdir ../download; fi

$(TARGET): $(OBJS)
	$(CXX) $^ $(REAL_LDFLAGS) -o $@
.cpp.o:
	$(CXX) -c $(REAL_CXXFLAGS) $<

clean:
	-rm -rf $(TARGET) $(OBJS)
	-rm -rf ../$(TARGET)

install:
	-cp -f $(TARGET) ../

.PHONY: all clean debug gprof install
