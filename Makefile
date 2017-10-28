AS=scas
CC=kcc
ASFLAGS=-fexplicit-export -fexplicit-import -Iheaders
CFLAGS=--nostdinc --nostdlib -Iheaders --no-std-crt0 

STARTUP_SOURCES=$(addprefix startup/,rise.c)
IO_SOURCES=$(addprefix io/,output.c input.c)
MAIN_SOURCES=system.c screens.c data.c
SCREEN_SOURCES=$(addprefix screens/,main_menu.c new_game.c)
SOURCES=$(addprefix src/,$(STARTUP_SOURCES) $(IO_SOURCES) $(MAIN_SOURCES) $(SCREEN_SOURCES))
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(SOURCES)))

bin/src/%.asm.o:src/%.asm headers
	$(AS) -c $< -o $@ $(ASFLAGS)
	
bin/src/%.c.o:src/%.c headers
	$(CC) -mz80 -S $< -o bin/$<.asm $(CFLAGS)
	$(AS) -c bin/$<.asm -o $@ $(ASFLAGS)

.PHONY: .default all $(ROM)
.default: $(ROM)

LINKER=bin/src/linker.asm.o
ROM=bin/rise.bin

$(ROM): $(LINKER) $(OBJECTS)
	scas $^ -o $@ $(ASFLAGS)

clean:
	$(RM) $(ROM) $(OBJECTS) $(LINKER)
	find bin/ -mindepth 2 -type f -delete

run: $(ROM)
	zenith80 --file $(ROM)

debug:
	zenith80-superdebug --file $(ROM) 2>o
	geany o
