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
MAKEDIR =
CC = g++
MAINFILE = main
OFILE = o
SRCFILE = cpp
HEADFILE = h
EXEFILE = exe

DEBUG = yes

SRCPATH = src
PARSERPATH = parser-lib
SRC = $(call rwildcard,$(SRCPATH)/,*.$(SRCFILE))
SRC += $(call rwildcard,$(PARSERPATH)/,*.$(SRCFILE))
HEAD = $(call rwildcard,$(SRCPATH)/,*.$(HEADFILE))
HEAD += $(call rwildcard,$(PARSERPATH)/,*.$(HEADFILE))
OBJPATH = build/
TEMPOBJ = $(SRC:$(PARSERPATH)/%.$(SRCFILE)=parser/%.$(OFILE))
OBJ = $(addprefix $(OBJPATH), $(TEMPOBJ:$(SRCPATH)/%.$(SRCFILE)=%.$(OFILE)))
WORKINGDIR =
ALLDIRCMD =

EXEROOT = bin
EXEPATH = $(EXEROOT)/
EXE1 = $(EXEPATH)pld-compilo.$(EXEFILE)
EXE2 =
EXECS = $(EXE1) $(EXE2)

OUTDIR_ROOT = build
OUTDIR = $(OUTDIR_ROOT) bin
#---------------------------------------------------------------

#Variables pour les options de compilation----------------------
W = -W
WA = -Wall
STDLIB = -std=gnu++11

CFLAGS =
#---------------------------------------------------------------

#Compilation conditionnelle-------------------------------------
ifeq ($(OS),$(OSWIN))
	DEL += del
	DELDIR += rd
	DELOPT += /s
	DELDIROPT += /s /q
	MAKEDIR += if not exist $(OUTDIR_ROOT) mkdir
	WORKINGDIR = $(shell echo %cd%)
	ALLDIRCMD = dir /s /b /o:n /ad $(SRCPATH)
	ALLDIR=$(shell $(ALLDIRCMD))
    OUTDIR += $(subst $(WORKINGDIR)\$(SRCPATH),$(OUTDIR_ROOT),$(ALLDIR))
    TEST = $(subst $(WORKINGDIR)\,,$(ALLDIR))
else ifeq ($(OS),$(OSUNIX))
	DEL += rm
	DELDIR += rm
	DELOPT += -rf
	DELDIROPT += -rf
	MAKEDIR += mkdir -p
	WORKINGDIR = $(shell cd $(SRCPATH) && pwd)
	ALLDIRCMD = find ./$(SRCPATH) -type d
	ALLDIR=$(shell $(ALLDIRCMD))
    OUTDIR += $(subst ./,$(OUTDIR_ROOT)/,$(ALLDIR))
else
	echo Unknown OS
	exit 1
endif


ifeq ($(DEBUG),yes)
	CFLAGS += $(W) $(WA) $(STDLIB)
else
	CFLAGS = $(STDLIB)
endif

#---------------------------------------------------------------



#Variables pour les options d'edition des liens-----------------

LDFLAGS =
#---------------------------------------------------------------

#Dependances a reconstruire de maniere systematique-------------
.PHONY: clean mrproper print-% makedir parser
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction
all: makedir parser
	make build
ifeq ($(DEBUG),yes)
	@echo Projet compile en mode debug
else
	@echo Projet compile en mode release
endif

build: $(EXECS)

$(EXE1): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE2):
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJPATH)$(MAINFILE).$(OFILE): $(SRCPATH)/$(MAINFILE).$(SRCFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)%.$(OFILE) : $(SRCPATH)/%.$(SRCFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)parser/%.$(OFILE) : $(PARSERPATH)/%.$(SRCFILE) $(PARSERPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)parser/%.$(OFILE) : $(PARSERPATH)/%.$(SRCFILE)
	$(CC) -o $@ -c $< $(CFLAGS)

makedir:
	$(MAKEDIR) $(OUTDIR)

parser:
	cd src/parser && make -f flex.makefile
	cd src/parser && make -f bison.makefile

#Regles de nettoyage
clean:
	cd src/parser && make -f flex.makefile clean
	cd src/parser && make -f bison.makefile clean
	$(DEL) $(DELOPT) *.$(OFILE)
	$(DEL) $(DELOPT) *.$(EXEFILE)

mrproper:
	cd src/parser && make -f flex.makefile clean
	cd src/parser && make -f bison.makefile clean
	$(DELDIR) $(DELDIROPT) $(OUTDIR_ROOT)
	$(DELDIR) $(DELDIROPT) $(EXEROOT)

#Regles de debuggage
print-% :
	@echo $* = $($*)
