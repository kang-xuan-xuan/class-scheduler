CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror
 
exec: bin/exec
 
bin/exec: ./src/main.cc ./src/courses.cc ./src/title.cc ./src/course.cc
	$(CXX) $(CXX_FLAGS) $^ -o $@
 
 
.DEFAULT_GOAL := exec
.PHONY: exec clean
 
clean:
	rm -f bin/*