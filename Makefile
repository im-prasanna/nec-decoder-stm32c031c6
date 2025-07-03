CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

MCU = cortex-m0plus
CFLAGS  = -mcpu=$(MCU) -mthumb -I./Inc
LDFLAGS = -T linker.ld -nostdlib

SRC = ./Src/main.c ./Src/startup.c ./Src/startup_assembly.s

TARGET = firmware
ELF = ./build/$(TARGET).elf
BIN = ./build/$(TARGET).bin

all: $(ELF) $(BIN)

$(ELF):
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(ELF) $(BIN)

