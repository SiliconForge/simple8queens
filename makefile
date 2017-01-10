CC=gcc
CFLAGS=-I./include
RE=rm
LIST=ls
SOURCELIST = ls sources/
DEPS = include/genetics.h
OBJS = $(addsuffix .o,$(basename $(shell $(SOURCELIST))))

#funcoes que nao sao arquivos
.PHONY: clean sourcesonly help run

#constroi todos os objetos de compilacao para construir o programa
binaries/%.o: sources/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)	

#regra que roda o makefile
run: 8queens
	@clear
	@./8queens

#requisita a construcao de um arquivo 8queens
8queens: $(addprefix binaries/,$(OBJS))
	$(CC) -o $@ $^ $(CFLAGS)


#Limpa tudo que nao for codigo fonte
sourcesonly:
	@echo "Cleaning machine files and leaving sources only."
	@$(RE) 8queens
	@$(RE) binaries/*.o
	@echo "Done..."

#Limpa os arquivos mas deixa o executavel

clean:
	@echo "Cleaning machine files and leaving sources and executable only."
	@$(RE) binaries/*.o
	@echo "Done..."

#funcao de ajuda ao desenvolvedor
help:
	@echo "Type -make- to compile and run the sources"
	@echo "Type -make clean- to clean the binary files but leave the executable"
	@echo "Type -make sourcesonly- to clear all compilation generated files"
	@echo "Type -make help- for this menu"	
