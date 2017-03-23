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
#OS specific commands
OSUNIX = unix
OSWIN = win
OS = $(OSWIN)
CAT =
DEL =
DELDIR =
DELOPT =
DELDIROPT =
MKDIR =
MAKEDIR =
MAKETESTDIR =
SUBSEPARATOR =
SEVERAL_CMD =
NULLREDIRECT =
ECHONEWLINE =

#Files extentions
CC = g++
MAINFILE = main
MAINSRCTESTFILE = main
OFILE = o
SRCFILE = cpp
HEADFILE = h
EXEFILE = exe
TESTFILE = spec
SRCTESTFILE = $(TESTFILE).$(SRCFILE)

#Debug mode
DEBUG = yes

#Folders & files
SRCPATH = src
OBJPATH = build
LIBPATH = lib
EXEPATH = bin
TESTPATH = test
INCLUDEFOLDER = include
INCLUDEPATH = $(wildcard $(LIBPATH)/*/$(INCLUDEFOLDER))
INCLUDEPATH := $(subst $(LIBPATH)/catch/$(INCLUDEFOLDER),,$(INCLUDEPATH))
SRC = $(filter-out %.$(SRCTESTFILE),$(call rwildcard,$(SRCPATH)/,*.$(SRCFILE)))
SRCTEST = $(call rwildcard,$(TESTPATH)/,*.$(SRCTESTFILE))
HEAD = $(call rwildcard,$(SRCPATH)/,*.$(HEADFILE))
OBJ = $(SRC:$(SRCPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
OBJLIB = $(filter-out %.$(TESTFILE).$(OFILE),$(call rwildcard,$(LIBPATH)/,*.$(OFILE)))
OBJTEST = $(SRCTEST:$(TESTPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
OBJLIBTEST = $(filter %.$(TESTFILE).$(OFILE),$(call rwildcard,$(LIBPATH)/,*.$(OFILE)))
WORKINGDIR =
ALLDIR =
TESTDIR =
ALLDIRCMD =
LIBS = $(wildcard $(LIBPATH)/*)
OUTDIR_ROOT = $(OBJPATH)
OUTDIR = $(OUTDIR_ROOT) $(EXEPATH)

#Convenient strings
PROMPTSEPARATOR = ------------

#Non-regression tests
NRPATH = $(TESTPATH)/non-regression
NRTESTS =
NRDESC = desc
NRINPUT = input.cmm
NROUTPUT = output
NRTARGETPREFIX = test-
NRPASSCMD =

#Executables
EXE1 = $(EXEPATH)/pld-compilo.$(EXEFILE)
EXE2 = $(EXEPATH)/tests.$(EXEFILE)
EXECS = $(EXE1) $(EXE2)
#---------------------------------------------------------------

#Variables pour les options de compilation----------------------
W = -W
WA = -Wall
STDLIB = -std=gnu++11
INCLUDES = $(foreach lib,$(INCLUDEPATH),-I $(lib))

CFLAGS = $(INCLUDES)
CTESTFLAGS = $(CFLAGS) -I $(LIBPATH)/catch/$(INCLUDEFOLDER) -I $(SRCPATH)
#---------------------------------------------------------------

#Compilation conditionnelle-------------------------------------
ifeq ($(OS),$(OSWIN))
	CAT = type
	DEL = del
	DELDIR = rd
	MKDIR = mkdir
	DELOPT = /s
	DELDIROPT = /s /q
	ECHONEWLINE = echo.
	WORKINGDIR = $(shell echo %cd%)
	ALLDIRCMD = dir /s /b /o:n /ad $(SRCPATH)
	ALLDIR=$(shell $(ALLDIRCMD))
    OUTDIR := $(OUTDIR) $(subst $(WORKINGDIR)\$(SRCPATH),$(OUTDIR_ROOT),$(ALLDIR))
    TESTDIR = $(TESTPATH) $(subst $(WORKINGDIR)\$(SRCPATH),$(TESTPATH),$(ALLDIR))
    SEVERAL_CMD = &
    MAKEDIR := $(foreach dir,$(OUTDIR),if not exist $(dir) mkdir $(dir) $(SEVERAL_CMD))
    MAKETESTDIR := $(foreach dir,$(TESTDIR),if not exist $(dir) mkdir $(dir) $(SEVERAL_CMD))
    SUBSEPARATOR = "\"
	SUBSEPARATOR := $(subst ",,$(SUBSEPARATOR))
	NRPATH := $(subst /,$(SUBSEPARATOR),$(NRPATH))
    NRTESTS := $(shell dir /s /b /o:n /ad $(NRPATH))
    NRTESTS := $(addprefix $(NRTARGETPREFIX),$(subst $(WORKINGDIR)\$(NRPATH)\,,$(NRTESTS)))
    NRPASSCMD = if errorlevel 0 (echo PASSED) else (echo FAILED) && exit 1
    NULLREDIRECT = nul
    EXE1 := $(subst /,$(SUBSEPARATOR),$(EXE1))
    EXE2 := $(subst /,$(SUBSEPARATOR),$(EXE2))
else ifeq ($(OS),$(OSUNIX))
	CAT = cat
	DEL = rm
	DELDIR = rm
	MKDIR = mkdir
	DELOPT = -rf
	DELDIROPT = -rf
	ECHONEWLINE =
	WORKINGDIR = $(shell cd $(SRCPATH) && pwd)
	ALLDIRCMD = find $(SRCPATH) -type d
	ALLDIR=$(filter-out $(SRCPATH),$(shell $(ALLDIRCMD)))
    OUTDIR := $(OUTDIR) $(subst $(SRCPATH),$(OUTDIR_ROOT),$(ALLDIR))
    TESTDIR = $(TESTPATH) $(subst $(SRCPATH),$(TESTPATH),$(ALLDIR))
    MAKEDIR := mkdir -p $(OUTDIR)
    MAKETESTDIR = mkdir -p $(TESTDIR)
    SEVERAL_CMD = ;
    SUBSEPARATOR = /
	NRTESTS := $(find $(NRPATH) -type d)
	NRTESTS := $(addprefix $(NRTARGETPREFIX),$(subst $(WORKINGDIR)\$(NRPATH)\,,$(filter-out $(NRPATH),$(NRTESTS))))
	NRPASSCMD = if [ $$? -eq 0 ]; then (echo PASSED) else (echo FAILED) && exit 1 fi
    NULLREDIRECT = /dev/nul
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
.PHONY: clean mrproper print-% makedir test libs libs-tests test-tree libs-test-tree $(NRTARGETPREFIX)% nr-test
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction-----------------------------------------
#Builds
all: makedir libs
	make OS=$(OS) DEBUG=$(DEBUG) build
ifeq ($(DEBUG),yes)
	@echo Projet compile en mode debug
else
	@echo Projet compile en mode release
endif

build: $(EXE1)

build-test: $(EXE2)

libs:
	$(foreach lib,$(LIBS),cd $(lib) && make OS=$(OS) DEBUG=$(DEBUG) $(SEVERAL_CMD) cd ../.. $(SEVERAL_CMD))

libs-tests:
	$(foreach lib,$(LIBS),cd $(lib) && make OS=$(OS) DEBUG=$(DEBUG) tests $(SEVERAL_CMD) cd ../.. $(SEVERAL_CMD))

$(EXE1): $(OBJ) $(OBJLIB)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE2): $(filter-out %$(MAINFILE).$(OFILE),$(OBJ)) $(OBJTEST) $(OBJLIB) $(OBJLIBTEST)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJPATH)/$(MAINFILE).$(OFILE): $(SRCPATH)/$(MAINFILE).$(SRCFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)/%.$(OFILE) : $(SRCPATH)/%.$(SRCFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)/$(MAINSRCTESTFILE).$(TESTFILE).$(OFILE): $(TESTPATH)/$(MAINSRCTESTFILE).$(SRCTESTFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CTESTFLAGS)
$(OBJPATH)/%.$(TESTFILE).$(OFILE) : $(TESTPATH)/%.$(SRCTESTFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CTESTFLAGS)

#Tests
tests: makedir libs libs-tests
	make OS=$(OS) DEBUG=$(DEBUG) build-test
	@echo UNIT TESTS
	$(EXE2)
	@echo NON-REGRESSION TESTS
	make OS=$(OS) DEBUG=$(DEBUG) nr-tests

$(NRTARGETPREFIX)%:
	@echo $(PROMPTSEPARATOR)
	@$(CAT) $(NRPATH)$(SUBSEPARATOR)$*$(SUBSEPARATOR)$(NRDESC)
	@$(ECHONEWLINE)
	@$(EXE1) < $(NRPATH)$(SUBSEPARATOR)$*$(SUBSEPARATOR)$(NRINPUT) > $(NULLREDIRECT) $(SEVERAL_CMD) @$(NRPASSCMD)

nr-tests: all $(NRTESTS)
	@echo $(PROMPTSEPARATOR)
	@echo ALL TESTS PASSED

#Runs
run: $(EXE1)
	$(EXE1)

#Construct folders tree
makedir:
	$(MAKEDIR)

test-tree: libs-test-tree
	$(MAKETESTDIR)

libs-test-tree:
	$(foreach lib,$(LIBS),cd $(lib) && make OS=$(OS) DEBUG=$(DEBUG) test-tree $(SEVERAL_CMD) cd ../.. $(SEVERAL_CMD))

#Clean
clean:
	$(foreach lib,$(LIBS),cd $(lib) && make OS=$(OS) clean $(SEVERAL_CMD) cd ../.. $(SEVERAL_CMD))
	$(DEL) $(DELOPT) *.$(OFILE)
	$(DEL) $(DELOPT) *.$(EXEFILE)

mrproper:
	$(foreach lib,$(LIBS),cd $(lib) && make OS=$(OS) mrproper $(SEVERAL_CMD) cd ../.. $(SEVERAL_CMD))
	$(DELDIR) $(DELDIROPT) $(OUTDIR_ROOT)
	$(DELDIR) $(DELDIROPT) $(EXEPATH)

#Debug
print-%:
	@echo $* = $($*)

test:

#---------------------------------------------------------------