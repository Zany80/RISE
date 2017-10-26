AS=scas

STARTUP_SOURCES=$(addprefix startup/,rise.asm)
SOURCES=$(addprefix src/,$(STARTUP_SOURCES))
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(SOURCES)))

bin/src/%.asm.o:src/%.asm
	scas -c $< -o $@ -Iheaders

.PHONY: .default all rise.bin
.default: all
all: rise.bin

rise.bin: $(OBJECTS)
	scas $(OBJECTS) -o $@

clean:
	$(RM) rise.bin $(OBJECTS)
