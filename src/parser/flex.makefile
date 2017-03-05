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
MV =
CC = flex
MAINFILE =
OFILE = yy.c
SRCFILE = l
HEADFILE =
EXEFILE =

DEBUG = yes

SRCPATH = .
SRC = $(call rwildcard,$(SRCPATH)/,*.$(SRCFILE))
HEAD =
OBJPATH = ../../parser-lib/
OUTDIR_ROOT = ../../parser-lib
OUTDIR = $(OUTDIR_ROOT)
OUTDIRPATH = $(OUTDIR_ROOT)/
OBJ = $(addprefix $(OBJPATH), $(SRC:$(SRCPATH)/%.$(SRCFILE)=%.$(OFILE)))
WORKINGDIR =
ALLDIRCMD =

EXEPATH = $(OBJPATH)
EXE1 = $(OBJPATH)pld-compilo.$(EXEFILE)
EXE2 =
EXECS = $(EXE1) $(EXE2)
#---------------------------------------------------------------

#Variables pour les options de compilation----------------------
W = -W
WA = -Wall
STDLIB = -std=c++11

CFLAGS =
#---------------------------------------------------------------

#Compilation conditionnelle-------------------------------------
ifeq ($(OS),$(OSWIN))
	DEL += del
	DELDIR += rd
	DELOPT += /s
	DELDIROPT += /s /q
	MV += move
	MAKEDIR += if not exist $(OUTDIR_ROOT) mkdir
	WORKINGDIR = $(shell echo %cd%)
	ALLDIRCMD = dir /s /b /o:n /ad $(SRCPATH)
	ALLDIR=$(shell $(ALLDIRCMD))
    OUTDIR += $(subst $(WORKINGDIR)\$(SRCPATH),$(OUTDIR_ROOT),$(ALLDIR))
    OUTDIR := $(subst /,\,$(OUTDIR))
    OUTDIR_ROOT := $(subst /,\,$(OUTDIR_ROOT))
    OUTDIRPATH := $(subst /,\,$(OUTDIRPATH))
else ifeq ($(OS),$(OSUNIX))
	DEL += rm
	DELDIR += rm
	DELOPT += -rf
	DELDIROPT += -rf
	MV += mv
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
.PHONY: clean mrproper print-%
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction
all: makedir $(EXECS)
ifeq ($(DEBUG),yes)
	@echo Projet compile en mode debug
else
	@echo Projet compile en mode release
endif

$(EXE1): $(OBJ)
	@echo Parser built.

$(OBJPATH)%.$(OFILE) : $(SRCPATH)/%.$(SRCFILE)
	$(CC) -t $<>$@

makedir:
	$(MAKEDIR) $(OUTDIR)

#Regles de nettoyage
clean:
	$(DEL) $(DELOPT) $(OUTDIRPATH)*.$(OFILE)

#Regles de debuggage
print-% :
	@echo $* = $($*)
