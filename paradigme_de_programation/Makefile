
#Makefile - INF224
PROG = main
SOURCES = src/basic.cpp src/main.cpp src/groupe.cpp src/createandmodify.cpp
CXX = c++
CXXFLAGS = -std=c++11 -Wall -Weffc++ -g -MD -MP

BUILD_DIR = build
SRC_DIR = src
DEPS_DIR = deps
HEADERS_DIR = include

PROG = ${BUILD_DIR}/main
OBJETS = $(patsubst ${SRC_DIR}/%.cpp,${BUILD_DIR}/%.o,${SOURCES})

.PHONY : all clean clean-all tar run

all: ${PROG}

$(BUILD_DIR) $(DEPS_DIR):
	@mkdir -p $@

${PROG}: ${OBJETS} | ${BUILD_DIR} ${DEPS_DIR}
	${CXX} ${CXXFLAGS} -o $@ $^

# Compilation des fichiers .cpp en .o
${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp | ${BUILD_DIR} ${DEPS_DIR}
	${CXX} ${CXXFLAGS} -MF $(DEPS_DIR)/$*.d -I${HEADERS_DIR} -c -o $@ $<

run: ${PROG}
	./${PROG}

clean:
	@rm -rf ${BUILD_DIR}/*.o
	@rm -rf ${PROG}

clean-all: clean
	@rm -rf ${DEPS_DIR}/*.d

tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}
