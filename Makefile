AS=scas
CC=kcc
ASFLAGS=-fexplicit-export -fexplicit-import -Iheaders
CFLAGS=--nostdinc --nostdlib -Iheaders --no-std-crt0 --std-sdcc99 -mz80

STARTUP_SOURCES=$(addprefix startup/,rise.c)
IO_SOURCES=$(addprefix io/,output.c input.c sprites.c)
MAIN_SOURCES=system.c screens.c data.c icon.asm
SCREEN_SOURCES=$(addprefix screens/,main_menu.c intro_screen.c awaken.c to_your_feet.c)
SOURCES=$(addprefix src/,$(STARTUP_SOURCES) $(IO_SOURCES) $(MAIN_SOURCES) $(SCREEN_SOURCES))
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(SOURCES)))

bin/src/%.asm.o:src/%.asm headers
	mkdir $(dir bin/src/%.asm.o) -p
	$(AS) -c $< -o $@ $(ASFLAGS)
	
bin/src/%.c.o:src/%.c headers
	mkdir $(dir bin/$<.asm) -p
	$(CC) -S $< -o bin/$<.asm $(CFLAGS)
	$(AS) -c bin/$<.asm -o $@ $(ASFLAGS)

.PHONY: .default all $(ROM) burn
.default: $(ROM)

LINKER=bin/src/linker.asm.o
ROM=bin/rise.bin
IMAGE=bin/rise.png

$(ROM): $(LINKER) $(OBJECTS)
	scas $^ -o $@ $(ASFLAGS)

$(IMAGE): $(ROM)
	cat src/icon.png $(ROM) > $(IMAGE)

clean:
	$(RM) $(ROM) $(OBJECTS) $(LINKER) $(IMAGE)
	find bin/ -mindepth 2 -type f -delete

run: $(IMAGE)
	zenith80 --file $(IMAGE) --format=png

debug: $(IMAGE)
	zenith80-superdebug --file $(IMAGE) --format=png 2>o
	geany o
	rm o
	
burn: $(IMAGE)
	dd if=$(IMAGE) of=/dev/sdb

from_disk:
	zenith80 --file /dev/sdb --real --wait --format=png
