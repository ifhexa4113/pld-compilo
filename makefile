#Rappels elementaires-------------------------------------------
#
#	$@ : adresse de la cible
#	$< : premiere dependance
#	$^ : liste des dependances
#	$? : liste des dependances plus recentes que la cible
#	$* : le nom du fichier sans suffixe
#
#---------------------------------------------------------------

#Notes----------------------------------------------------------
#
#	Cette version de tests fait fonctionner la compilation dans
#	des sous-repertoires.
#	Reste a la faire fonctionner de maniere recursive.
#
#---------------------------------------------------------------

#Fonctions------------------------------------------------------
# Wildcard recursif
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

#Variables generales--------------------------------------------
OSUNIX = unix
OSWIN = win
OS = $(OSWIN)
DEL =
DELDIR =
DELOPT =
DELDIROPT =
MKDIR =
MAKEDIR =
SEVERAL_CMD =

CC = g++
MAINFILE = main
OFILE = o
SRCFILE = cpp
HEADFILE = h
EXEFILE = exe

DEBUG = yes

SRCPATH = src
OBJPATH = build
LIBPATH = lib
EXEPATH = bin
INCLUDEPATH = $(wildcard $(LIBPATH)/*/include)
SRC = $(call rwildcard,$(SRCPATH)/,*.$(SRCFILE))
HEAD = $(call rwildcard,$(SRCPATH)/,*.$(HEADFILE))
OBJ = $(SRC:$(SRCPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
LIBOBJ = $(call rwildcard,$(LIBPATH)/,*.$(OFILE))
WORKINGDIR =
ALLDIRCMD =
LIBS = $(wildcard $(LIBPATH)/*)

EXE1 = $(EXEPATH)/pld-compilo.$(EXEFILE)
EXE2 =
EXECS = $(EXE1) $(EXE2)

OUTDIR_ROOT = build
OUTDIR = $(OUTDIR_ROOT) bin
#---------------------------------------------------------------

#Variables pour les options de compilation----------------------
W = -W
WA = -Wall
STDLIB = -std=gnu++11
INCLUDES = $(foreach lib,$(INCLUDEPATH),-I $(lib))

CFLAGS = $(INCLUDES)
#---------------------------------------------------------------

#Compilation conditionnelle-------------------------------------
ifeq ($(OS),$(OSWIN))
	DEL = del
	DELDIR = rd
	MKDIR = mkdir
	DELOPT = /s
	DELDIROPT = /s /q
	WORKINGDIR = $(shell echo %cd%)
	ALLDIRCMD = dir /s /b /o:n /ad $(SRCPATH)
	ALLDIR=$(shell $(ALLDIRCMD))
    OUTDIR := $(OUTDIR) $(subst $(WORKINGDIR)\$(SRCPATH),$(OUTDIR_ROOT),$(ALLDIR))
    SEVERAL_CMD = &
    MAKEDIR := $(foreach dir,$(OUTDIR),if not exist $(dir) mkdir $(dir) $(SEVERAL_CMD))
else ifeq ($(OS),$(OSUNIX))
	DEL = rm
	DELDIR = rm
	MKDIR = mkdir
	DELOPT = -rf
	DELDIROPT = -rf
	WORKINGDIR = $(shell cd $(SRCPATH) && pwd)
	ALLDIRCMD = find ./$(SRCPATH) -type d
	ALLDIR=$(shell $(ALLDIRCMD))
    OUTDIR := $(OUTDIR) $(subst ./$(SRCPATH)/,$(OUTDIR_ROOT)/,$(ALLDIR))
    MAKEDIR := mkdir -p $(OUTDIR)
    SEVERAL_CMD = ;
else
	echo Unknown OS
	exit 1
endif


ifeq ($(DEBUG),yes)
	CFLAGS += $(W) $(WA) $(STDLIB)
else
	CFLAGS += $(STDLIB)
endif

#---------------------------------------------------------------



#Variables pour les options d'edition des liens-----------------

LDFLAGS =
#---------------------------------------------------------------

#Dependances a reconstruire de maniere systematique-------------
.PHONY: clean mrproper print-% makedir libs test
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction
all: makedir libs
	make OS=$(OS) DEBUG=$(DEBUG) build
ifeq ($(DEBUG),yes)
	@echo Projet compile en mode debug
else
	@echo Projet compile en mode release
endif

build: $(EXECS)

$(EXE1): $(OBJ) $(LIBOBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE2):
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJPATH)/$(MAINFILE).$(OFILE): $(SRCPATH)/$(MAINFILE).$(SRCFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)/%.$(OFILE) : $(SRCPATH)/%.$(SRCFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)/parser/%.$(OFILE) : $(PARSERPATH)/%.$(SRCFILE) $(PARSERPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)/parser/%.$(OFILE) : $(PARSERPATH)/%.$(SRCFILE)
	$(CC) -o $@ -c $< $(CFLAGS)

run: all
	$(EXE1)
	
makedir:
	$(MAKEDIR)

libs:
	$(foreach lib,$(LIBS),cd $(lib) && (make OS=$(OS) DEBUG=$(DEBUG) $(SEVERAL_CMD) cd ../..) $(SEVERAL_CMD))

#Regles de nettoyage
clean:
	$(foreach lib,$(LIBS),cd $(lib) && (make OS=$(OS) clean $(SEVERAL_CMD) cd ../..) $(SEVERAL_CMD))
	$(DEL) $(DELOPT) *.$(OFILE)
	$(DEL) $(DELOPT) *.$(EXEFILE)

mrproper:
	$(foreach lib,$(LIBS),cd $(lib) && (make OS=$(OS) mrproper $(SEVERAL_CMD) cd ../..) $(SEVERAL_CMD))
	$(DELDIR) $(DELDIROPT) $(OUTDIR_ROOT)
	$(DELDIR) $(DELDIROPT) $(EXEPATH)

#Regles de debuggage
print-% :
	@echo $* = $($*)