CC = gcc				#CD 311 Veis Onur Șener
CFLAGS = -g -Wall
HEADERS =bmp_header.h functii.h
OBJECTS = tema3.o piesa_O.o piesa_L.o piesa_J.o piesa_I.o piesa_S.o piesa_Z.o piesa_T.o piesa_O_imagine.o piesa_J_imagine.o piesa_T_imagine.o piesa_Z_imagine.o piesa_S_imagine.o piesa_L_imagine.o piesa_I_imagine.o imagine.o Eliminare.o Verificare.o Imagine4.o task4.o
EXEC = myProgram

.PHONY = default build clean

default: build

build: myProgram

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

run: build
	./$(EXEC) ${ARGS}

run_task1: build
	./$(EXEC) 1

run_task2: build
	./$(EXEC) 2

run_task3: build
	./$(EXEC) 3

run_task4: build
	./$(EXEC) 4

run_bonus: build
	./$(EXEC) bonus

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC)