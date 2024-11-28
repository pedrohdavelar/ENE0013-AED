all: failsvetor failslista

Student_info.o: Student_info.cc Student_info.h
	g++ -std=c++11 -Wall -c Student_info.cc

median.o: median.cc median.h
	g++ -std=c++11 -Wall -c median.cc

grade.o: grade.cc grade.h
	g++ -std=c++11 -Wall -c grade.cc

vec_main.o: vec_main.cc grade.h Student_info.h
	g++ -std=c++11 -Wall -c vec_main.cc

fails_iters.o: fails_iters.cc grade.h Student_info.h
	g++ -std=c++11 -Wall -c fails_iters.cc

fails_list.o: fails_list.cc grade.h Student_info.h
	g++ -std=c++11 -Wall -c fails_list.cc

list_main.o: list_main.cc grade.h Student_info.h
	g++ -std=c++11 -Wall -c list_main.cc

failsvetor: fails_iters.o vec_main.o grade.o median.o Student_info.o
	g++ -std=c++11 -Wall fails_iters.o vec_main.o grade.o median.o Student_info.o -o failsvetor

failslista: fails_list.o list_main.o grade.o median.o Student_info.o
	g++ -std=c++11 -Wall fails_list.o list_main.o grade.o median.o Student_info.o -o failslista

clean:
	rm -f *.o *.exe failsvetor failslista
