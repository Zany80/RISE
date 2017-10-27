AS=scas
ASFLAGS=-fexplicit-export -fexplicit-import

STARTUP_SOURCES=$(addprefix startup/,first_run.asm rise.asm)
IO_SOURCES=$(addprefix io/,output.asm)
SOURCES=$(addprefix src/,$(STARTUP_SOURCES) $(IO_SOURCES))
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(SOURCES)))

bin/src/%.asm.o:src/%.asm headers
	scas -c $< -o $@ -Iheaders $(ASFLAGS)

.PHONY: .default all $(ROM)
.default: $(ROM)

LINKER=bin/src/linker.asm.o
ROM=bin/rise.bin

$(ROM): $(LINKER) $(OBJECTS)
	scas $^ -o $@ $(ASFLAGS)

clean:
	$(RM) $(ROM) $(OBJECTS) $(LINKER)

run:
	zenith80 --file $(ROM)

debug:
	zenith80-superdebug --file $(ROM) 2>o
	geany o
