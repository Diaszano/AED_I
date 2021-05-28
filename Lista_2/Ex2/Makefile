#Nome do executavel
Nome=Executavel

#Todos os arquivos .c
Aquivos_c=$(wildcard *.c)

#Todos os arquivos .h
Aquivos_h=$(wildcard *.h)

#Compilador
CC=gcc

#Flags do compilador
Flags=	-c \
        -W \
        -Wall \
        -ansi \
        -pedantic

Flags_c = 	-w \
			-Wall \
			-pedantic

#Compilacao
all: $(Nome)

$(Nome): $(Aquivos_c)
	$(CC) $(Flags_c) $^ -o $@ 

main.o: $(Aquivos_h)
	$(CC) -o $< $(Flags)