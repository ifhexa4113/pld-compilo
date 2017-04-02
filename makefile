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
UTESTDIRTOCREATE =
NRTESTDIRTOCREATE =
SUBSEPARATOR =
SEVERAL_CMD =
NULLREDIRECT =
ECHONEWLINE =

#Other commands
CC = g++

#Files extensions
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
MAINFILE = main
MAINSRCUTESTFILE = main
MAINSRCNRTESTFILE = main
INCLUDEFOLDER = include
INCLUDEPATH = $(wildcard $(LIBPATH)/*/$(INCLUDEFOLDER))
INCLUDEPATH := $(subst $(LIBPATH)/catch/$(INCLUDEFOLDER),,$(INCLUDEPATH))
SRC = $(filter-out %.$(SRCTESTFILE),$(call rwildcard,$(SRCPATH)/,*.$(SRCFILE)))
SRCUTEST = $(call rwildcard,$(UTESTPATH)/,*.$(SRCTESTFILE))
SRCNRTEST = $(call rwildcard,$(NRTESTPATH)/,*.$(SRCFILE))
HEAD = $(call rwildcard,$(SRCPATH)/,*.$(HEADFILE))
HEADNRTEST = $(call rwildcard,$(SRCPATH)/,*.$(HEADFILE))
OBJ = $(SRC:$(SRCPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
OBJLIB = $(filter-out %.$(TESTFILE).$(OFILE),$(call rwildcard,$(LIBPATH)/,*.$(OFILE)))
OBJUTEST = $(SRCUTEST:$(UTESTPATH)/%.$(SRCFILE)=$(OBJPATH)/%.$(OFILE))
OBJLIBUTEST = $(filter %.$(TESTFILE).$(OFILE),$(call rwildcard,$(LIBPATH)/,*.$(OFILE)))
OBJNRTEST = $(SRCNRTEST:$(NRTESTPATH)/%.$(SRCFILE)=$(OBJPATH)/$(NRFOLDER)/%.$(OFILE))
WORKINGDIR =
ALLDIR =
UTESTDIR =
NRTESTDIR =
ALLDIRCMD =
LIBS = $(wildcard $(LIBPATH)/*)
OUTDIR_ROOT = $(OBJPATH)
OUTDIR = $(OUTDIR_ROOT) $(EXEPATH)

#Convenient strings
PROMPTSEPARATOR = ------------
SUBSTSEPARATOR = +

#Unit tests
UNITFOLDER = unit
UTESTPATH = $(TESTPATH)/$(UNITFOLDER)

#Non-regression tests
NRFOLDER = non-regression
NRTESTPATH = $(TESTPATH)/$(NRFOLDER)
NRSETPATH = $(TESTPATH)/set
NRTESTS =
NRDESC = desc
NRINPUT = input.cmm
NROUTPUT = output
NROUTPUTST = $(NROUTPUT).st
NROUTPUTAST = $(NROUTPUT).ast
NROUTPUTCFG = $(NROUTPUT).cfg
NROUTPUTASM = $(NROUTPUT).asm
NRALLOUTPUTS = $(NROUTPUTST) $(NROUTPUTAST) $(NROUTPUTCFG) $(NROUTPUTASM)
NRTARGETPREFIX = test-
NRPASSCMD =

#Executables
EXE1 = $(EXEPATH)/gmm.$(EXEFILE)
EXE2 = $(EXEPATH)/unit-tests.$(EXEFILE)
EXE3 = $(EXEPATH)/nr-tests.$(EXEFILE)
EXECS = $(EXE1) $(EXE2) $(EXE3)
#---------------------------------------------------------------

#Variables pour les options de compilation----------------------
W = -W
WA = -Wall
STDLIB = -std=gnu++11
INCLUDES = $(foreach lib,$(INCLUDEPATH),-I $(lib))

CFLAGS = $(INCLUDES)
CUTESTFLAGS = $(CFLAGS) -I $(LIBPATH)/catch/$(INCLUDEFOLDER) -I $(SRCPATH)
CNRTESTFLAGS = $(CFLAGS) -I $(SRCPATH) -I $(NRTESTPATH)
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
    UTESTDIR := $(subst /,\,$(UTESTPATH)) $(subst $(WORKINGDIR)\$(SRCPATH),$(subst /,\,$(UTESTPATH)),$(ALLDIR))
    NRSETPATH := $(subst /,\,$(NRSETPATH))
    NRTESTDIR = $(shell dir /s /b /o:n /ad $(subst /,\,$(NRTESTPATH)))
    NRTESTDIR := $(subst $(TESTPATH)/,$(OBJPATH)\,$(NRTESTPATH)) $(subst $(WORKINGDIR)\$(TESTPATH),$(OBJPATH),$(NRTESTDIR))
    NRTESTS = $(subst $(WORKINGDIR)\$(NRSETPATH)\,$(NRTARGETPREFIX),$(shell dir /s /b /o:n /ad $(subst /,$(SUBSEPARATOR),$(NRSETPATH))))
    NRPASSCMD = if not errorlevel 1 (echo [92mPASSED[0m) else ((echo [91mFAILED[0m) && exit 1)
    SEVERAL_CMD = &
    DIRTOCREATE := $(foreach dir,$(OUTDIR),makedir-$(subst /,$(SUBSTSEPARATOR),$(subst \,$(SUBSTSEPARATOR),$(dir))))
    UTESTDIRTOCREATE := $(foreach dir,$(UTESTDIR),makedir-$(subst /,$(SUBSTSEPARATOR),$(subst \,$(SUBSTSEPARATOR),$(dir))))
    NRTESTDIRTOCREATE := $(foreach dir,$(NRTESTDIR),makedir-$(subst \,$(SUBSTSEPARATOR),$(dir)))
    SUBSEPARATOR = "\"
	SUBSEPARATOR := $(subst ",,$(SUBSEPARATOR))
    NULLREDIRECT = nul
    EXE1 := $(subst /,$(SUBSEPARATOR),$(EXE1))
    EXE2 := $(subst /,$(SUBSEPARATOR),$(EXE2))
    EXE3 := $(subst /,$(SUBSEPARATOR),$(EXE3))
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
    UTESTDIR = $(UTESTPATH) $(subst $(SRCPATH),$(UTESTPATH),$(ALLDIR))
	NRTESTDIR := $(subst $(TESTPATH),$(OBJPATH),$(shell find $(NRTESTPATH) -type d))
    DIRTOCREATE := $(foreach dir,$(OUTDIR),makedir-$(subst /,$(SUBSTSEPARATOR),$(dir)))
    UTESTDIRTOCREATE := $(foreach dir,$(UTESTDIR),makedir-$(subst /,$(SUBSTSEPARATOR),$(dir)))
    NRTESTDIRTOCREATE = $(foreach dir,$(NRTESTDIR),makedir-$(subst /,$(SUBSTSEPARATOR),$(dir)))
    SEVERAL_CMD = ;
    SUBSEPARATOR = /
	NRTESTS := $(subst $(NRSETPATH)/,$(NRTARGETPREFIX),$(filter-out $(NRSETPATH),$(shell find $(NRSETPATH) -type d)))
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
.PHONY: clean mrproper print-% makedir-% test libs libs-tests test-tree libs-test-tree $(NRTARGETPREFIX)%
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction-----------------------------------------
#Specify default rule (names here are just a convention)
default: all

#Pre build
makedir: $(DIRTOCREATE)

makenrdir: $(NRTESTDIRTOCREATE)

makedir-%:
	$(call mkdir-cmd,$(subst $(SUBSTSEPARATOR),$(SUBSEPARATOR),$*))

#Builds
all: makedir libs
	make OS=$(OS) DEBUG=$(DEBUG) build
ifeq ($(DEBUG),yes)
	@echo [92mProject build in debug mode[0m
else
	@echo [92mProject build in release mode[0m
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
$(EXE2): $(filter-out %$(MAINFILE).$(OFILE),$(OBJ)) $(OBJUTEST) $(OBJLIB) $(OBJLIBUTEST)
	$(CC) -o $@ $^ $(LDFLAGS)
$(EXE3): $(filter-out %$(MAINFILE).$(OFILE),$(OBJ)) $(OBJLIB) $(OBJNRTEST)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJPATH)/$(MAINFILE).$(OFILE): $(SRCPATH)/$(MAINFILE).$(SRCFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)/%.$(OFILE) : $(SRCPATH)/%.$(SRCFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)/$(MAINSRCUTESTFILE).$(TESTFILE).$(OFILE): $(UTESTPATH)/$(MAINSRCUTESTFILE).$(SRCTESTFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CUTESTFLAGS)
$(OBJPATH)/%.$(TESTFILE).$(OFILE) : $(UTESTPATH)/%.$(SRCTESTFILE) $(SRCPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CUTESTFLAGS)

$(OBJPATH)/$(NRFOLDER)/$(MAINSRCNRTESTFILE).$(OFILE): $(NRTESTPATH)/$(MAINSRCNRTESTFILE).$(SRCFILE) $(HEAD)
	$(CC) -o $@ -c $< $(CNRTESTFLAGS)
$(OBJPATH)/$(NRFOLDER)/%.$(OFILE) : $(NRTESTPATH)/%.$(SRCFILE) $(NRTESTPATH)/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CNRTESTFLAGS)

#Tests
u-tests: makedir libs libs-tests
	make OS=$(OS) DEBUG=$(DEBUG) build-utest
ifeq ($(DEBUG),yes)
	@echo [92mUnit tests build in debug mode[0m
else
	@echo [92mUnit tests build in release mode[0m
endif

nr-tests: makedir makenrdir libs
	make OS=$(OS) DEBUG=$(DEBUG) build-nrtest
ifeq ($(DEBUG),yes)
	@echo [92mNon-regression tests build in debug mode[0m
else
	@echo [92mNon-regression tests build in release mode[0m
endif

tests: all u-tests nr-tests
	@echo UNIT TESTS
	$(EXE2)
	@echo NON-REGRESSION TESTS
	@make run-nrtests

$(NRTARGETPREFIX)%:
	@echo $(PROMPTSEPARATOR)
	@echo TEST $*
	@$(CAT) $(NRSETPATH)$(SUBSEPARATOR)$*$(SUBSEPARATOR)$(NRDESC)
	@$(ECHONEWLINE)
	@$(EXE3) $(foreach output,$(NRALLOUTPUTS),$(WORKINGDIR)$(SUBSEPARATOR)$(NRSETPATH)$(SUBSEPARATOR)$*$(SUBSEPARATOR)$(output)) < $(NRSETPATH)$(SUBSEPARATOR)$*$(SUBSEPARATOR)$(NRINPUT) > $(NULLREDIRECT) $(SEVERAL_CMD) $(NRPASSCMD)

#Runs
run: $(EXE1)
	$(EXE1)

run-utests: $(EXE2)
	$(EXE2)

run-nrtests: $(EXE3) $(NRTESTS)
	@echo [92mALL NR TESTS PASSED[0m

#Construct folders tree
test-tree: libs-test-tree $(UTESTDIRTOCREATE)

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