all: 7colors 

7colors: 7colors.o maj.o map_gen.o human.o territory.o stop_condition.o alea1.o alea2.o
	gcc 7colors.o maj.o map_gen.o human.o territory.o stop_condition.o alea1.o alea2.o -o 7colors

7colors.o: 7colors.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter 7colors.c -c -g
	
maj.o: maj.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter maj.c -c -g
	
map_gen.o: map_gen.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter map_gen.c -c -g
	
human.o: human.c
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter human.c -c -g
	
stop_condition.o: stop_condition.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter stop_condition.c -c -g
	
territory.o: territory.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter territory.c -c -g

alea1.o: alea1.c
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter alea1.c -c -g

alea2.o: alea2.c
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter alea2.c -c -g
