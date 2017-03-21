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
MAKETESTDIR =
CP =
CPOPT =
SUBSEPARATOR =
SEVERAL_CMD =

MAINFILE = main
OFILE = o
SRCFILE = cpp
HEADFILE = h
EXEFILE = exe
TESTFILE = spec
SRCTESTFILE = $(TESTFILE).$(SRCFILE)

CC = g++
DEBUG = yes

SRCPATH = src
TEMPPATH = temp
OBJPATH = build
LIBPATH = ..
HEADPATH = include
TESTPATH = test
INCLUDEFOLDER = include
SRC = $(filter-out %.$(SRCTESTFILE),$(call rwildcard,$(SRCPATH)/,*.$(SRCFILE)))
SRCTEST = $(call rwildcard,$(TESTPATH)/,*.$(SRCTESTFILE))
SRCTEMP = $(call rwildcard,$(TEMPPATH)/,*.$(SRCFILE))
HEAD = $(call rwildcard,$(SRCPATH)/,*.$(HEADFILE))
HEADTEMP = $(call rwildcard,$(TEMPPATH)/,*.$(HEADFILE))
OBJ = $(SRC:$(SRCPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
OBJTEMP = $(SRCTEMP:$(TEMPPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
OBJTEST = $(SRCTEST:$(TESTPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
WORKINGDIR =
ALLDIR =
TESTDIR =
ALLDIRCMD =

HEADREGEX =
EXEROOT =
EXEPATH = $(EXEROOT)/
EXE1 = $(EXEPATH)pld-compilo.$(EXEFILE)
EXE2 =
EXECS = $(EXE1) $(EXE2)

OUTDIR_ROOT = $(OBJPATH)
OUTDIR = $(OUTDIR_ROOT) $(TEMPPATH) $(HEADPATH)
#---------------------------------------------------------------

#Variables pour les options de compilation----------------------
W = -W
WA = -Wall
STDLIB = -std=gnu++11

CFLAGS =
CFLEXBISONFLAGS = $(CFLAGS) -I $(SRCPATH)
CTESTFLAGS = $(CFLAGS) -I $(LIBPATH)/catch/$(INCLUDEFOLDER) -I $(SRCPATH)
#---------------------------------------------------------------

#Compilation conditionnelle-------------------------------------
ifeq ($(OS),$(OSWIN))
	DEL += del
	DELDIR += rd
	DELOPT += /s
	DELDIROPT += /s /q
	CP += copy
	CPOPT +=
	WORKINGDIR = $(shell echo %cd%)
	ALLDIR=$(shell $(ALLDIRCMD))
    OUTDIR += $(subst $(WORKINGDIR)\$(SRCPATH),$(OUTDIR_ROOT),$(ALLDIR))
    OUTDIR += $(subst $(WORKINGDIR)\$(SRCPATH),$(HEADPATH),$(ALLDIR))
    TESTDIR = $(TESTPATH) $(subst $(WORKINGDIR)\$(SRCPATH),$(TESTPATH),$(ALLDIR))
    ALLDIRCMD = dir /s /b /o:n /ad $(SRCPATH)
    SEVERAL_CMD = &
    MAKEDIR := $(foreach dir,$(OUTDIR),if not exist $(dir) mkdir $(dir) $(SEVERAL_CMD))
    MAKETESTDIR := $(foreach dir,$(TESTDIR),if not exist $(dir) mkdir $(dir) $(SEVERAL_CMD))
    HEAD := $(subst /,\, $(HEAD))
    HEADTEMP := $(subst /,\, $(HEADTEMP))
    SUBSEPARATOR = "\"
    SUBSEPARATOR := $(subst ",,$(SUBSEPARATOR))
else ifeq ($(OS),$(OSUNIX))
	DEL += rm
	DELDIR += rm
	DELOPT += -rf
	DELDIROPT += -rf
	CP += cp
	WORKINGDIR = $(shell cd $(SRCPATH) && pwd)
	ALLDIR=$(filter-out $(SRCPATH),$(shell $(ALLDIRCMD)))
    OUTDIR += $(subst $(SRCPATH),$(OUTDIR_ROOT),$(ALLDIR))
    OUTDIR += $(subst $(SRCPATH),$(HEADPATH),$(ALLDIR))
    TESTDIR = $(TESTPATH) $(subst $(SRCPATH),$(TESTPATH),$(ALLDIR))
    MAKEDIR := mkdir -p $(OUTDIR)
    MAKETESTDIR = mkdir -p $(TESTDIR)
    ALLDIRCMD = find $(SRCPATH) -type d
	SEVERAL_CMD = ;
    SUBSEPARATOR = /
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
.PHONY: clean mrproper print-% test makedir flex bison deploy test-tree
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction
all: makedir flex bison
	make OS=$(OS) DEBUG=$(DEBUG) build
	make OS=$(OS) DEBUG=$(DEBUG) deploy

ifeq ($(DEBUG),yes)
	@echo Parser lib compile en mode debug
else
	@echo Parser lib compile en mode release
endif

build: $(EXECS)

tests: $(OBJTEST)

$(EXE1): $(OBJ) $(OBJTEMP)

$(OBJPATH)/$(MAINFILE).$(OFILE): $(SRCPATH)/$(MAINFILE).$(SRCFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)/%.$(OFILE) : $(SRCPATH)/%.$(SRCFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)/%.$(OFILE) : $(TEMPPATH)/%.$(SRCFILE) $(TEMPPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLEXBISONFLAGS)
$(OBJPATH)/%.$(OFILE) : $(TEMPPATH)/%.$(SRCFILE)
	$(CC) -o $@ -c $< $(CFLEXBISONFLAGS)

$(OBJPATH)/%.$(TESTFILE).$(OFILE) : $(TESTPATH)/%.$(SRCTESTFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CTESTFLAGS)

makedir:
	$(MAKEDIR)

test-tree:
	$(MAKETESTDIR)

flex:
	cd $(SRCPATH) && make -f flex.makefile

bison:
	cd $(SRCPATH) && make -f bison.makefile

deploy:
	$(foreach head,$(HEAD),$(CP) $(CPOPT) $(head) $(subst $(SRCPATH),$(HEADPATH),$(head)) $(SEVERAL_CMD))
	$(CP) $(CPOPT) $(TEMPPATH)$(SUBSEPARATOR)*.$(HEADFILE) $(HEADPATH)

#Regles de nettoyage
clean:
	cd $(SRCPATH) && make -f flex.makefile clean
	cd $(SRCPATH) && make -f bison.makefile clean
	$(DEL) $(DELOPT) *.$(OFILE)

mrproper: clean
	$(DELDIR) $(DELDIROPT) $(OUTDIR)

#Regles de debuggage
print-% :
	@echo $* = $($*)

test:
