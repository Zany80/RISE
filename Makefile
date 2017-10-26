AS=scas
ASFLAGS=-fexplicit-export -fexplicit-import

STARTUP_SOURCES=$(addprefix startup/,first_run.asm)
SOURCES=$(addprefix src/,$(STARTUP_SOURCES))
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(SOURCES)))

bin/src/%.asm.o:src/%.asm headers
	scas -c $< -o $@ -Iheaders $(ASFLAGS)

.PHONY: .default all $(ROM)
.default: $(ROM)

ROM=bin/rise.bin

MAIN=bin/src/startup/rise.asm.o

$(ROM): $(MAIN) $(OBJECTS)
	scas $^ -o $@

clean:
	$(RM) $(ROM) $(OBJECTS) $(MAIN)

run:
	zenith80 --file $(ROM)

debug:
	zenith80-superdebug --file $(ROM) 2>o
	geany o
