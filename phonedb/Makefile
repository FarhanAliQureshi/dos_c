# Reference: https://open-watcom.github.io/open-watcom-v2-wikidocs/ctools.html#The_Open_Watcom_Make_Utility
# Reference: https://github.com/open-watcom/open-watcom-v2/blob/master/bld/src/goodies/makefile.c

# Update following two depending on your project type
PROJECT = PHONEDB
# Programming language can be C or CPP
LANGUAGE = C

# NOTES: 
# 1) You probably won't need to update anything below.
# 2) If compiler asks to include or exclude any flag then update it 
#    below with macros C_FLAGS or CPP_FLAGS (or corresponding debug 
#    or release macros).
# 3) If you are using any external library then add it below with LIBS macro.
# 4) If you are targeting Tiny memory model to generate .COM file then
#    change extension of macro OUTPUT_FILE below.

C_COMPILER = wcl
C_FLAGS = -cc -za99 -0 -wcd=138 -lr -q
C_DEBUG_FLAGS = $+ $(C_FLAGS) $- -d3 -wx -we -db -od
C_RELEASE_FLAGS = $+ $(C_FLAGS) $- -d0 -oh -ol -ot -ox

CPP_COMPILER = wcl
CPP_FLAGS = -cc++ -za0x -0 -lr -q
CPP_DEBUG_FLAGS = $+ $(CPP_FLAGS) $- -d3 -wx -we -db -od
CPP_RELEASE_FLAGS = $+ $(CPP_FLAGS) $- -d0 -oh -ol -ot -ox

OUTPUT_DIR = build
OUTPUT_FILE = $(OUTPUT_DIR)\$(PROJECT).exe

LIBS = 
OBJ_DIR = objs
SRC_DIR = src
OBJ_FILES = *.obj
C_SRC_FILES = $(SRC_DIR)\*.c
C_INCLUDE_FILES = $(SRC_DIR)\*.h
CPP_SRC_FILES = $(SRC_DIR)\*.cpp
CPP_INCLUDE_FILES = $(SRC_DIR)\*.hpp

!ifeq LANGUAGE C
LANGUAGE_SYMBOL = C
COMPILER = $(C_COMPILER)
COMPILER_FLAGS = $(C_FLAGS)
COMPILER_DEBUG_FLAGS = $(C_DEBUG_FLAGS)
COMPILER_RELEASE_FLAGS = $(C_RELEASE_FLAGS)
SRC_FILES = $(C_SRC_FILES)
INCLUDE_FILES = $(C_INCLUDE_FILES)
!else ifeq LANGUAGE CPP
LANGUAGE_SYMBOL = C++
COMPILER = $(CPP_COMPILER)
COMPILER_FLAGS = $(CPP_FLAGS)
COMPILER_DEBUG_FLAGS = $(CPP_DEBUG_FLAGS)
COMPILER_RELEASE_FLAGS = $(CPP_RELEASE_FLAGS)
SRC_FILES = $(CPP_SRC_FILES)
INCLUDE_FILES = $(CPP_INCLUDE_FILES)
!else
!error Unknown programming language $(LANGUAGE)
!endif


all : $(OUTPUT_FILE) .SYMBOLIC

$(OUTPUT_FILE) : $(SRC_FILES)
	@echo Compiling and linking $(LANGUAGE_SYMBOL) source code to debug executable...
	@mkdir $(OUTPUT_DIR) > silent
	@del silent
	#@$(COMPILER) $(COMPILER_DEBUG_FLAGS) -fm=$* -fe=$@ $< $(LIBS)
	@$(COMPILER) $(COMPILER_DEBUG_FLAGS) -fm=$* -fe=$@ $(SRC_FILES) $(LIBS)

release : $(SRC_FILES) .SYMBOLIC
	@$(MAKE) -h clean
	@echo Compiling and linking $(LANGUAGE_SYMBOL) source code to release executable...
	@mkdir $(OUTPUT_DIR) > silent
	#@$(COMPILER) $(COMPILER_RELEASE_FLAGS) -fe=$(OUTPUT_FILE) $< $(LIBS)
	@$(COMPILER) $(COMPILER_RELEASE_FLAGS) -fe=$(OUTPUT_FILE) $(SRC_FILES) $(LIBS)
	@del *.obj > silent
	@del silent
	@$(MAKE) -h strip

strip : $(OUTPUT_FILE) .SYMBOLIC
	@echo Stripping any unnecessary information from production executable file...
	@wstrip -q -n $<

debug : $(OUTPUT_FILE) .SYMBOLIC
	@echo Launching Watcom Debugger...
	@wd $<

run : $(OUTPUT_FILE) .SYMBOLIC
	$<

clean : .SYMBOLIC
	@echo Removing all files which were generated using source files
	@del $(OBJ_DIR)\*.* > silent	
	@del $(OUTPUT_DIR)\*.* > silent
	@rmdir $(OBJ_DIR) > silent
	@rmdir $(OUTPUT_DIR) > silent
	@del *.obj > silent
	@del *.mbr > silent
	@del silent
