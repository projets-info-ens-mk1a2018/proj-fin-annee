all: 7colors 

7colors: standalone.o 7colors.o maj.o map_gen.o human.o territory.o stop_condition.o alea1.o alea2.o glouton.o hegemonique.o smart_glouton.o
	gcc standalone.o 7colors.o maj.o map_gen.o human.o territory.o stop_condition.o alea1.o alea2.o glouton.o hegemonique.o smart_glouton.o -o 7colors 

standalone.o: standalone.c
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter standalone.c -c -g

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

alea2.o: alea2.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter alea2.c -c -g
	
glouton.o: glouton.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter glouton.c -c -g

hegemonique.o: hegemonique.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter hegemonique.c -c -g
	
smart_glouton.o: smart_glouton.c 7colors.h
	gcc -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter smart_glouton.c -c -g
