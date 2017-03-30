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

#Functions------------------------------------------------------
# Recursive wildcard
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Create mkdir command
# --> mkdir-cmd
# --> This depends of the OS and is therefore located further away

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
DIRTOCREATE =
TESTDIRTOCREATE =
SUBSEPARATOR =
SEVERAL_CMD =
NULLREDIRECT =
ECHONEWLINE =

#Files extensions
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
OBJTEST = $(SRCTEST:$(UTESTPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
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

#Unit tests
UTESTPATH = $(TESTPATH)/unit

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
EXE3 =
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
define mkdir-cmd
	if not exist $1 mkdir $1
endef
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
    UTESTPATH := $(subst /,\,$(UTESTPATH))
    TESTDIR = $(UTESTPATH) $(subst $(WORKINGDIR)\$(SRCPATH),$(UTESTPATH),$(ALLDIR))
    SEVERAL_CMD = &
    DIRTOCREATE := $(foreach dir,$(OUTDIR),makedir-$(subst \,-,$(dir)))
    TESTDIRTOCREATE := $(foreach dir,$(TESTDIR),makedir-$(subst \,-,$(dir)))
    SUBSEPARATOR = "\"
	SUBSEPARATOR := $(subst ",,$(SUBSEPARATOR))
	NRPATH := $(subst /,$(SUBSEPARATOR),$(NRPATH))
    NRTESTS := $(shell dir /s /b /o:n /ad $(NRPATH))
    NRTESTS := $(addprefix $(NRTARGETPREFIX),$(subst $(WORKINGDIR)\$(NRPATH)\,,$(NRTESTS)))
    NRPASSCMD = if not errorlevel 1 (echo [92mPASSED[0m) else ((echo [91mFAILED[0m) && exit 1)
    NULLREDIRECT = nul
    EXE1 := $(subst /,$(SUBSEPARATOR),$(EXE1))
    EXE2 := $(subst /,$(SUBSEPARATOR),$(EXE2))
else ifeq ($(OS),$(OSUNIX))
define mkdir-cmd
	mkdir -p $1
endef
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
    TESTDIR = $(UTESTPATH) $(subst $(SRCPATH),$(UTESTPATH),$(ALLDIR))
    DIRTOCREATE := $(foreach dir,$(OUTDIR),makedir-$(subst /,-,$(dir)))
    TESTDIRTOCREATE = mkdir -p $(TESTDIR)
    SEVERAL_CMD = ;
    SUBSEPARATOR = /
	NRTESTS := $(subst $(NRPATH)/,$(NRTARGETPREFIX),$(filter-out $(NRPATH),$(shell find $(NRPATH) -type d)))
	NRPASSCMD = if [ $$? -eq 0 ]; then (echo [92mPASSED[0m); else (echo [91mFAILED[0m) && exit 1; fi
    NULLREDIRECT = /dev/null
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
.PHONY: clean mrproper print-% makedir-% test libs libs-tests test-tree libs-test-tree $(NRTARGETPREFIX)% nr-test
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction-----------------------------------------
#Pre build
makedir: $(DIRTOCREATE)

makedir-%:
	$(call mkdir-cmd,$(subst -,$(SUBSEPARATOR),$*))

#Builds
all: makedir libs
	make OS=$(OS) DEBUG=$(DEBUG) build
ifeq ($(DEBUG),yes)
	@echo Projet compile en mode debug
else
	@echo Projet compile en mode release
endif

build: $(EXE1)

build-utest: $(EXE2)

build-nrtest: $(EXE3)

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

$(OBJPATH)/$(MAINSRCTESTFILE).$(TESTFILE).$(OFILE): $(UTESTPATH)/$(MAINSRCTESTFILE).$(SRCTESTFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CTESTFLAGS)
$(OBJPATH)/%.$(TESTFILE).$(OFILE) : $(UTESTPATH)/%.$(SRCTESTFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CTESTFLAGS)

#Tests
tests: all libs-tests
	make OS=$(OS) DEBUG=$(DEBUG) build-utest
	@echo UNIT TESTS
	$(EXE2)
	@echo NON-REGRESSION TESTS
	make OS=$(OS) DEBUG=$(DEBUG) nr-tests

$(NRTARGETPREFIX)%:
	@echo $(PROMPTSEPARATOR)
	@echo TEST $*
	@$(CAT) $(NRPATH)$(SUBSEPARATOR)$*$(SUBSEPARATOR)$(NRDESC)
	@$(ECHONEWLINE)
	@$(EXE1) < $(NRPATH)$(SUBSEPARATOR)$*$(SUBSEPARATOR)$(NRINPUT) > $(NULLREDIRECT) $(SEVERAL_CMD) $(NRPASSCMD)

nr-tests: $(NRTESTS)
	@echo $(PROMPTSEPARATOR)
	@echo ALL TESTS PASSED

#Runs
run: $(EXE1)
	$(EXE1)

#Construct folders tree
test-tree: libs-test-tree $(TESTDIRTOCREATE)

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