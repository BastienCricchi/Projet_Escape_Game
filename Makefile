LDFLAGS	   		   := `(pkg-config gtkmm-3.0 --cflags --libs)`
CC                 := g++
OBJDIR             := ./compile

PROG_VERSION        := base


CFLAGS_COMMON      := -Wall -std=c++14
CFLAGS_COMMON      += -mavx
CFLAGS_COMMON      += -DPROG_VERSION=\"$(PROG_VERSION)\"
CFLAGS_COMMON      += -pg


CFLAGS             := $(CFLAGS_COMMON)


TARGET             := main_test_graphic_room
SRC_FILES          := \
  main_test_graphic_room.cpp


OBJECT_FILES       := $(addprefix  $(OBJDIR)/,$(notdir $(SRC_FILES:.cpp=.r.o)))
DEP_FILES          := $(addprefix  $(OBJDIR)/,$(notdir $(SRC_FILES:.cpp=.r.P)))




$(TARGET): $(OBJECT_FILES) Makefile
	$(CC) -o $@ $(OBJECT_FILES) $(LDFLAGS)


$(OBJECT_FILES)        :| $(OBJDIR)

#
# Generation of dependency include files during compilation
# which will be used during the next compilation
# thanks to  http://make.paulandlesley.org/autodep.html
#


$(OBJDIR)/%.r.o : ./%.cpp
	@printf "Compiling release version of $<\n"
	$(CC) -c -MMD -MF $(OBJDIR)/$*.r.d -MT $(OBJDIR)/$*.r.o $(CFLAGS) -o $@ $<  $(LDFLAGS)
	@cp $(OBJDIR)/$*.r.d $(OBJDIR)/$*.r.P
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJDIR)/$*.r.d >> $(OBJDIR)/$*.r.P
	@rm -f $(OBJDIR)/$*.r.d


$(OBJDIR):
	mkdir -p $@



clean:
	$(RM) $(TARGET) $(TARGET).debug $(OBJECT_FILES) $(DEP_FILES)


.SUFFIXES:              # Delete the default suffixes
.SUFFIXES: .cpp .o .h   # Define "CPP" language suffix list

-include $(DEP_FILES)