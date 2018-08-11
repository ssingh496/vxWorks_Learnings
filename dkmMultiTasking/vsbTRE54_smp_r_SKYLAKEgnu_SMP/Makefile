# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))
WIND_KRNL_MK := $(subst \,/,$(WIND_KRNL_MK))
WIND_USR_MK := $(subst \,/,$(WIND_USR_MK))
WIND_BUILD := $(subst \,/,$(WIND_BUILD))
WIND_BUILD_TOOL := $(subst \,/,$(WIND_BUILD_TOOL))

all : check_vsb pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

JOBS?=1
TARGET_JOBS?=$(JOBS)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = vsbTRE54_smp_r_SKYLAKEgnu_SMP
DEBUG_MODE = 0
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/Workbench_vXWorks7_BranchCoreDump
PRJ_ROOT_DIR := C:/GitRepos/coreDump/pes-dev-e5-sbc-vxworks7/Source/PlatformSoftware/DKMs/dkmMultiTasking



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0
APICHECK_OPTIONS = -warning


#BuildSpec specific Build Macros
VX_CPU_FAMILY = pentium
CPU = SKYLAKE
TOOL_FAMILY = gnu
TOOL_VERSION = gnu_4_8_1_8
_CC_VERSION = gnu_4_8_1_10
TOOL = gnu
TOOL_PATH = $(WIND_HOME)/compilers/gnu-4.8.1.10/$(WIND_VX7_GNU_HOST_TYPE)/bin
CC_ARCH_SPEC = -march=corei7 -mpopcnt -maes -mpclmul -mavx -mfsgsbase -mrdrnd -mf16c -mavx2 -mmovbe -mfma -mbmi -mbmi2 -mrdseed -madx -mprfchw -nostdlib -fno-builtin -fno-defer-pop -fno-implicit-fp
VSB_DIR = $(PRJ_ROOT_DIR)/../../VSBs/vsbTRE54_smp_r
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 
DKM_LONGCALL = 
BDGEN_VSB_INCLUDE = $(VSB_DIR)/h/config/auto.conf
APICHECK_CMD = apicheck.sh -r "$(VSB_DIR)/krnl/apicheck/forbidden_api.lst" -n "nmpentium" -u -s "$<" "$@" $(APICHECK_OPTIONS)
APICHECK = 0

IDE_INCLUDES = -I$(VSB_DIR)/share/h -isystem$(VSB_DIR)/krnl/h/system -isystem$(VSB_DIR)/krnl/h/public -I$(PRJ_ROOT_DIR)/../../Library/BalLib/h -I$(PRJ_ROOT_DIR)/../../Library/SystemLib/Common/h -I$(PRJ_ROOT_DIR)/../../Library/SystemLib/vxWorks/h -I$(PRJ_ROOT_DIR)/../../Library/AppLib/vxWorks/h -I$(PRJ_ROOT_DIR)/../../Library/CompLib/Common/h -I$(PRJ_ROOT_DIR)/../../Library/CompLib/vxWorks/h 

IDE_LIBRARIES = 

IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DBID_VERSION=\"$(RELEASE_VER)\" -DBID_SCMREV=\"$(SCM_REV)\" -DBID_BRANCH=\"$(BRANCH)\" -DBID_BUILDHOST=\"$(BUILD_HOST)\" -DBID_BUILDAGENT=\"$(BUILD_AGENT)\" -DBID_BUILDspec=\"$(BUILDspec)\" -DBID_DEBUGspec=\"$(DEBUGspec)\" -DBID_BUILDPLAN=\"$(BUILD_PLAN)\" -DBID_BUILDNUM=\"$(BUILD_NUM)\" 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -gdwarf-3
DEBUGFLAGS_C++-Compiler = -gdwarf-3
DEBUGFLAGS_Linker = -gdwarf-3
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -gdwarf-3
else
DEBUGFLAGS_C-Compiler = -O2
DEBUGFLAGS_C++-Compiler = -O2
DEBUGFLAGS_Linker = -O2
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2
endif


#Project Targets
PROJECT_TARGETS = dkmMultiTasking/$(MODE_DIR)/dkmMultiTasking.out \
	 dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage.o


#Rules

# dkmMultiTasking
ifeq ($(DEBUG_MODE),1)
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -gdwarf-3
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -gdwarf-3
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -gdwarf-3
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -gdwarf-3
else
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
dkmMultiTasking/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2
endif
dkmMultiTasking/$(MODE_DIR)/% : IDE_INCLUDES = -I$(VSB_DIR)/share/h -isystem$(VSB_DIR)/krnl/h/system -isystem$(VSB_DIR)/krnl/h/public -I$(PRJ_ROOT_DIR)/../../Library/BalLib/h -I$(PRJ_ROOT_DIR)/../../Library/SystemLib/Common/h -I$(PRJ_ROOT_DIR)/../../Library/SystemLib/vxWorks/h -I$(PRJ_ROOT_DIR)/../../Library/AppLib/vxWorks/h -I$(PRJ_ROOT_DIR)/../../Library/CompLib/Common/h -I$(PRJ_ROOT_DIR)/../../Library/CompLib/vxWorks/h 
dkmMultiTasking/$(MODE_DIR)/% : IDE_LIBRARIES = 
dkmMultiTasking/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DBID_VERSION=\"$(RELEASE_VER)\" -DBID_SCMREV=\"$(SCM_REV)\" -DBID_BRANCH=\"$(BRANCH)\" -DBID_BUILDHOST=\"$(BUILD_HOST)\" -DBID_BUILDAGENT=\"$(BUILD_AGENT)\" -DBID_BUILDspec=\"$(BUILDspec)\" -DBID_DEBUGspec=\"$(DEBUGspec)\" -DBID_BUILDPLAN=\"$(BUILD_PLAN)\" -DBID_BUILDNUM=\"$(BUILD_NUM)\" 
dkmMultiTasking/$(MODE_DIR)/% : PROJECT_TYPE = DKM
dkmMultiTasking/$(MODE_DIR)/% : DEFINES = 
dkmMultiTasking/$(MODE_DIR)/% : EXPAND_DBG = 0
dkmMultiTasking/$(MODE_DIR)/% : APICHECK_OPTIONS = -warning
dkmMultiTasking/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
dkmMultiTasking/$(MODE_DIR)/% : CPU = SKYLAKE
dkmMultiTasking/$(MODE_DIR)/% : TOOL_FAMILY = gnu
dkmMultiTasking/$(MODE_DIR)/% : TOOL_VERSION = gnu_4_8_1_8
dkmMultiTasking/$(MODE_DIR)/% : _CC_VERSION = gnu_4_8_1_10
dkmMultiTasking/$(MODE_DIR)/% : TOOL = gnu
dkmMultiTasking/$(MODE_DIR)/% : TOOL_PATH = $(WIND_HOME)/compilers/gnu-4.8.1.10/$(WIND_VX7_GNU_HOST_TYPE)/bin
dkmMultiTasking/$(MODE_DIR)/% : CC_ARCH_SPEC = -march=corei7 -mpopcnt -maes -mpclmul -mavx -mfsgsbase -mrdrnd -mf16c -mavx2 -mmovbe -mfma -mbmi -mbmi2 -mrdseed -madx -mprfchw -nostdlib -fno-builtin -fno-defer-pop -fno-implicit-fp
dkmMultiTasking/$(MODE_DIR)/% : VSB_DIR = $(PRJ_ROOT_DIR)/../../VSBs/vsbTRE54_smp_r
dkmMultiTasking/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
dkmMultiTasking/$(MODE_DIR)/% : LIBPATH = 
dkmMultiTasking/$(MODE_DIR)/% : LIBS = 
dkmMultiTasking/$(MODE_DIR)/% : DKM_LONGCALL = 
dkmMultiTasking/$(MODE_DIR)/% : BDGEN_VSB_INCLUDE = $(VSB_DIR)/h/config/auto.conf
dkmMultiTasking/$(MODE_DIR)/% : APICHECK_CMD = apicheck.sh -r "$(VSB_DIR)/krnl/apicheck/forbidden_api.lst" -n "nmpentium" -u -s "$<" "$@" $(APICHECK_OPTIONS)
dkmMultiTasking/$(MODE_DIR)/% : APICHECK = 0
dkmMultiTasking/$(MODE_DIR)/% : OBJ_DIR := dkmMultiTasking/$(MODE_DIR)

OBJECTS_dkmMultiTasking = dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage.o

checkDirdkmMultiTasking : 
	mkdir -p dkmMultiTasking/$(MODE_DIR)/
dkmMultiTasking/$(MODE_DIR)/.dkmMultiTaskingObject.list: $(OBJECTS_dkmMultiTasking) | checkDirdkmMultiTasking
	$(file >$@,$^)
ifeq ($(TARGET_JOBS),1)
dkmMultiTasking/$(MODE_DIR)/dkmMultiTasking.out : dkmMultiTasking/$(MODE_DIR)/.dkmMultiTaskingObject.list | check_objdirs
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmpentium @dkmMultiTasking/$(MODE_DIR)/.dkmMultiTaskingObject.list | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium -tags $(VSB_DIR)/krnl/tags/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)/ccpentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall   $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES)  $(DKM_LONGCALL) $(IDE_DEFINES) $(DEFINES) -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c;  $(TOOL_PATH)/ccpentium -r -nostdlib -Wl,-X -T $(WIND_BASE)/build/tool/gnu_4_8_1_8/krnl/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o @dkmMultiTasking/$(MODE_DIR)/.dkmMultiTaskingObject.list $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi && $(if $(_WRS_CONFIG_SECURE_LOADER),signtool --key=$(_WRS_CONFIG_SECURE_LOADER_PRIVATE_SIGNING_KEY_FILE) --cert=$(_WRS_CONFIG_SECURE_LOADER_PUBLIC_SIGNING_CERT_FILE) --type=ELF $@,true)

else
dkmMultiTasking/$(MODE_DIR)/dkmMultiTasking.out : dkmMultiTasking/$(MODE_DIR)/dkmMultiTasking.out_jobs

endif
dkmMultiTasking/$(MODE_DIR)/dkmMultiTasking_compile_file : $(FILE) ;

_clean :: dkmMultiTasking/$(MODE_DIR)/dkmMultiTasking_clean

dkmMultiTasking/$(MODE_DIR)/dkmMultiTasking_clean : 
	$(TRACE_FLAG)if [ -d "dkmMultiTasking" ]; then cd "dkmMultiTasking"; rm -rf $(MODE_DIR); fi


# dkmMultiTasking_partialImage
ifeq ($(DEBUG_MODE),1)
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -gdwarf-3
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -gdwarf-3
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -gdwarf-3
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -gdwarf-3
else
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2
endif
dkmMultiTasking_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(VSB_DIR)/share/h -isystem$(VSB_DIR)/krnl/h/system -isystem$(VSB_DIR)/krnl/h/public -I$(PRJ_ROOT_DIR)/../../Library/BalLib/h -I$(PRJ_ROOT_DIR)/../../Library/SystemLib/Common/h -I$(PRJ_ROOT_DIR)/../../Library/SystemLib/vxWorks/h -I$(PRJ_ROOT_DIR)/../../Library/AppLib/vxWorks/h -I$(PRJ_ROOT_DIR)/../../Library/CompLib/Common/h -I$(PRJ_ROOT_DIR)/../../Library/CompLib/vxWorks/h 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DBID_VERSION=\"$(RELEASE_VER)\" -DBID_SCMREV=\"$(SCM_REV)\" -DBID_BRANCH=\"$(BRANCH)\" -DBID_BUILDHOST=\"$(BUILD_HOST)\" -DBID_BUILDAGENT=\"$(BUILD_AGENT)\" -DBID_BUILDspec=\"$(BUILDspec)\" -DBID_DEBUGspec=\"$(DEBUGspec)\" -DBID_BUILDPLAN=\"$(BUILD_PLAN)\" -DBID_BUILDNUM=\"$(BUILD_NUM)\" 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DEFINES = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
dkmMultiTasking_partialImage/$(MODE_DIR)/% : APICHECK_OPTIONS = -warning
dkmMultiTasking_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
dkmMultiTasking_partialImage/$(MODE_DIR)/% : CPU = SKYLAKE
dkmMultiTasking_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
dkmMultiTasking_partialImage/$(MODE_DIR)/% : TOOL_VERSION = gnu_4_8_1_8
dkmMultiTasking_partialImage/$(MODE_DIR)/% : _CC_VERSION = gnu_4_8_1_10
dkmMultiTasking_partialImage/$(MODE_DIR)/% : TOOL = gnu
dkmMultiTasking_partialImage/$(MODE_DIR)/% : TOOL_PATH = $(WIND_HOME)/compilers/gnu-4.8.1.10/$(WIND_VX7_GNU_HOST_TYPE)/bin
dkmMultiTasking_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -march=corei7 -mpopcnt -maes -mpclmul -mavx -mfsgsbase -mrdrnd -mf16c -mavx2 -mmovbe -mfma -mbmi -mbmi2 -mrdseed -madx -mprfchw -nostdlib -fno-builtin -fno-defer-pop -fno-implicit-fp
dkmMultiTasking_partialImage/$(MODE_DIR)/% : VSB_DIR = $(PRJ_ROOT_DIR)/../../VSBs/vsbTRE54_smp_r
dkmMultiTasking_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
dkmMultiTasking_partialImage/$(MODE_DIR)/% : LIBPATH = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : LIBS = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : DKM_LONGCALL = 
dkmMultiTasking_partialImage/$(MODE_DIR)/% : BDGEN_VSB_INCLUDE = $(VSB_DIR)/h/config/auto.conf
dkmMultiTasking_partialImage/$(MODE_DIR)/% : APICHECK_CMD = apicheck.sh -r "$(VSB_DIR)/krnl/apicheck/forbidden_api.lst" -n "nmpentium" -u -s "$<" "$@" $(APICHECK_OPTIONS)
dkmMultiTasking_partialImage/$(MODE_DIR)/% : APICHECK = 0
dkmMultiTasking_partialImage/$(MODE_DIR)/% : OBJ_DIR := dkmMultiTasking_partialImage/$(MODE_DIR)

dkmMultiTasking_partialImage/$(MODE_DIR)/Objects/dkmMultiTasking/dkm.o : $(PRJ_ROOT_DIR)/dkm.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)/ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -std=c99 -fno-zero-initialized-in-bss -Wall -Werror -Wextra -MD -MP $(DKM_LONGCALL) $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<" && if [ "$(APICHECK)" = "1" ]; then $(APICHECK_CMD);fi


OBJECTS_dkmMultiTasking_partialImage = dkmMultiTasking_partialImage/$(MODE_DIR)/Objects/dkmMultiTasking/dkm.o

checkDirdkmMultiTasking_partialImage : 
	mkdir -p dkmMultiTasking_partialImage/$(MODE_DIR)/
dkmMultiTasking_partialImage/$(MODE_DIR)/.dkmMultiTasking_partialImageObject.list: $(OBJECTS_dkmMultiTasking_partialImage) | checkDirdkmMultiTasking_partialImage
	$(file >$@,$^)
ifeq ($(TARGET_JOBS),1)
dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage.o : dkmMultiTasking_partialImage/$(MODE_DIR)/.dkmMultiTasking_partialImageObject.list | check_objdirs
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";  $(TOOL_PATH)/ccpentium -r -nostdlib -Wl,-X  -o "$@" @dkmMultiTasking_partialImage/$(MODE_DIR)/.dkmMultiTasking_partialImageObject.list $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage.o : dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage.o_jobs

endif
dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage_compile_file : $(FILE) ;

_clean :: dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage_clean

dkmMultiTasking_partialImage/$(MODE_DIR)/dkmMultiTasking_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "dkmMultiTasking_partialImage" ]; then cd "dkmMultiTasking_partialImage"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := dkmMultiTasking_partialImage/$(MODE_DIR)/Objects/dkmMultiTasking/dkm.d
-include $(DEP_FILES)

OBJ_DIRS := dkmMultiTasking_partialImage/$(MODE_DIR)/Objects/dkmMultiTasking
check_objdirs : 
	$(TRACE_FLAG)echo "Creating object dirs";\
	for dir in $(OBJ_DIRS); do\
		if [ ! -d "$$dir" ]; then mkdir -p "$$dir"; fi;\
	done


ifdef BDGEN_VSB_INCLUDE
include $(BDGEN_VSB_INCLUDE)
endif

-include $(PRJ_ROOT_DIR)/*.makefile
include $(PRJ_ROOT_DIR)/../../Build/mk/Series6MakeRules.mk
-include *.makefile

TARGET_JOBS_RULE=$(MAKE) -f $(MAKEFILE) --jobs $(TARGET_JOBS) $(MFLAGS) $* TARGET_JOBS=1
ifeq ($(JOBS),1)
main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS) TARGET_JOBS=1 &&\
	echo "make: built targets of `pwd`"
endif 

check_vsb :
	@if [ "$(SKIP_VSB_CHECK)" = "" ]; then\
		if [ -f $(WIND_BASE)/build/mk/scripts/check_vsb.sh ]; then\
			jobsoption="";\
			if [ "$(JOBS)" != "" ]; then\
				jobsoption="-j $(JOBS)";\
			fi;\
			sh $(WIND_BASE)/build/mk/scripts/check_vsb.sh $$jobsoption $(VSB_DIR);\
		fi;\
	fi

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: check_objdirs $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
