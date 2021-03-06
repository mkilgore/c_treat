include ./config.mk

# Program wide settings
EXE       := c_treat
EXEC      := C_TREAT
PROG      := $(BIN)/$(EXE)
C_TREAT_VERSION   := 0
C_TREAT_SUBLEVEL  := 8
C_TREAT_PATCH     := 0
C_TREAT_VERSION_N := $(C_TREAT_VERSION).$(C_TREAT_SUBLEVEL).$(C_TREAT_PATCH)

LIBFLAGS :=

CFLAGS  += -I'./include' -I'./src' -DC_TREAT_VERSION_N="$(C_TREAT_VERSION_N)"

# 'tree' references the current directory later-on
tree := .

# This is our default target - The default is the first target in the file so
# we need to define this fairly high-up.
all: real-all

.PHONY: all install clean dist real-all configure

# Predefine this variable. It contains a list of extra files to clean. Ex.
CLEAN_LIST :=

# List of files that dependency files should be generated for
DEPS :=

# Current project being compiled - Blank for core
PROJ :=
EXES :=
SRC_OBJS :=

# Set configuration options
Q := @
ifdef V
	Q :=
endif

define create_link_rule
$(1): $(2)
	@echo " LD      $$@"
	$$(Q)$$(LD) -r $(2) -o $$@
endef

# Traverse into tree
#
# For those confused, this does a few things:
#   1. Initalizes some variables for the current directory
#   2. 'Include's the current directory's Makefile, to get it's object information
#   3. Updates the clean-list, dependency list
#   4. Creates a rule that links all the objects in that directory into a
#      single .o file (Including sub-directory objects)
#   5. Recurses into subdirectories listed in the included Makefile

define subdir_inc
tree := $$(tree)/$(1)

subdir-y :=
objs-y :=
clean-list-y :=

include $$(tree)/Makefile

# Prepend 'tree' to everything in the lists - the lists are relative to their directory
CLEAN_LIST += $$(patsubst %,$$(tree)/%,$$(objs-y)) $$(patsubst %,$$(tree)/%,$$(clean-list-y)) $$(tree).o
DEPS += $$(patsubst %,$$(tree)/%,$$(objs-y))

objs := $$(patsubst %,$$(tree)/%,$$(objs-y)) $$(patsubst %,$$(tree)/%.o,$$(subdir-y))

$$(eval $$(call create_link_rule,$$(tree).o,$$(objs)))

$$(foreach subdir,$$(subdir-y),$$(eval $$(call subdir_inc,$$(subdir))))

# Reduce 'tree' by one directory level
tree := $$(patsubst %/$(1),%,$$(tree))
endef

ifeq ($(CONFIG_DEBUG),y)
	CFLAGS += -g -DCONFIG_DEBUG
	ASFLAGS += -g
	LDFLAGS += -g
endif

ifeq ($(CONFIG_PROF),y)
	CFLAGS += -pg
	LDFLAGS += -pg
endif

$(eval $(call subdir_inc,src))
$(eval $(call subdir_inc,src_container_of))

CLEAN_LIST += $(BIN)
CLEAN_LIST += $(PROG)

# Actual entry
real-all: $(PROG)

$(PROG): ./src.o ./src_container_of.o | $(BIN)
	@echo " CCLD    $@"
	$(Q)$(CC) $(LDFLAGS) $(CFLAGS) -o $@ ./src.o ./src_container_of.o $(LIBFLAGS)

dist: clean
	$(Q)mkdir -p $(EXE)-$(C_ASYNC_VERSION_N)
	$(Q)cp -R Makefile README.md config.mk LICENSE ./include ./src $(EXE)-$(C_ASYNC_VERSION_N)
	$(Q)tar -cf $(EXE)-$(C_ASYNC_VERSION_N).tar $(EXE)-$(C_ASYNC_VERSION_N)
	$(Q)gzip $(EXE)-$(C_ASYNC_VERSION_N).tar
	$(Q)rm -fr $(EXE)-$(C_ASYNC_VERSION_N)
	@echo " Created $(EXE)-$(C_ASYNC_VERSION_N).tar.gz"

clean:
	$(Q)for file in $(CLEAN_LIST); do \
		if [ -e $$file ]; then \
		    echo " RM      $$file"; \
			rm -rf $$file; \
		fi \
	done

$(BIN):
	@echo " MKDIR   $@"
	$(Q)$(MKDIR) $@

%.o: %.c
	@echo " CC      $@"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

.%.d: %.c
	@echo " CCDEP   $@"
	$(Q)$(CC) -MM -MP -MF $@ $(CFLAGS) $< -MT ./$*.o -MT $@

%.c: %.l
	@echo " LEX     $@"
	$(Q)$(LEX) $(LFLAGS) -o $@ $<

%.tab.c %.tab.h: %.y
	@echo " YACC    $@"
	$(Q)$(YACC) $(YFLAGS) -d -b $* $<

DEP_LIST := $(foreach dep,$(DEPS),$(dir $(dep)).$(notdir $(dep)))
DEP_LIST := $(DEP_LIST:.o=.d)

real-all: $(DEP_LIST)

ifeq (,$(filter $(MAKECMDGOALS),clean dist))
-include $(DEP_LIST)
endif
CLEAN_LIST += $(DEP_LIST)

