SPIDERQ_MAJOR=0
SPIDERQ_MINOR=1
DYLIBSUFFIX=so
DYLIBMAJORSUFFIX=$(SPIDERQ_MAJOR)
DYLIBMINORSUFFIX=$(SPIDERQ_MAJOR).$(SPIDERQ_MINOR)

SOURCES=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SOURCES))
DYLIBNAMES=$(patsubst %.cpp,%.$(DYLIBSUFFIX),$(SOURCES))

CXX:=g++
OPTIMIZATION?=-O2 -DNDEBUG
WARNINGS=-Wall
CXXFLAGS=-I../src
REAL_CXXFLAGS=$(OPTIMIZATION) -fPIC $(CXXFLAGS) $(WARNINGS) $(DEBUG) $(PROF)


all: $(DYLIBNAMES) 

#$(DYLIBNAMES): $(OBJS)
%.so:%.o
	$(CXX) -shared -Wl,-soname,$@.$(DYLIBMINORSUFFIX) $(LDFLAGS) $< -o $@ 


.cpp.o:
	$(CXX)  -c $(REAL_CXXFLAGS) $<

clean:
	rm -rf $(DYLIBNAMES) $(OBJS)

PREFIX:=/etc/spider
MODULEDIR=$(PREFIX)/modules

ifeq ($(uname_S),SunOS)
  INSTALL?= cp -r
endif
INSTALL?= cp -af

install: $(DYLIBNAMES) 
	@mkdir -p $(MODULEDIR)
	-$(INSTALL) $^ $(MODULEDIR)

.PHONY: all clean debug gprof install
