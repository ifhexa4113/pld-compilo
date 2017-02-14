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

#Variables generales--------------------------------------------
OSUNIX = unix
OSWIN = win
OS = $(OSWIN)
DEL =
DELOPT =
MAKEDIR =
CC = g++
MAINFILE = main
OFILE = o
SRCFILE = cpp
HEADFILE = h
EXEFILE = exe

DEBUG = yes

SRCPATH = src/
SRC = $(wildcard */*.$(SRCFILE))
HEAD = $(wildcard */*.$(HEADFILE))
OBJPATH = build/
OUT_DIR = build
OBJ = $(addprefix $(OBJPATH),$(notdir $(SRC:.$(SRCFILE)=.$(OFILE))))

EXEPATH = $(OBJPATH)
EXE1 = $(OBJPATH)tp-compilo.$(EXEFILE)
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
	DELOPT += /s
	MAKEDIR += if not exist $(OUT_DIR) mkdir
else ifeq ($(OS),$(OSUNIX))
	DEL += rm
	DELOPT += -rf
	MAKEDIR += mkdir -p
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
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE2):
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJPATH)$(MAINFILE).$(OFILE): $(SRCPATH)$(MAINFILE).$(SRCFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)%.$(OFILE) : $(SRCPATH)%.$(SRCFILE) $(SRCPATH)%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)

makedir:
	$(MAKEDIR) $(OUT_DIR)

#Regles de nettoyage
clean:
	$(DEL) $(DELOPT) *.$(OFILE)
	
mrproper: clean
	$(DEL) $(DELOPT) $(notdir $(EXECS))


#Regles de debuggage
print-% :
	@echo $* = $($*)




