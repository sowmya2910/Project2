
-include sources.mk

#flags

COM_CFLAGS=  \
-Wall \
-Werror \
-g \
-O0 \
-std=c99 \
-DPROJECT2

KL25Z_CFLAGS= \
-mcpu=cortex-m0plus \
-mthumb \
-march=armv6-m \
-mfloat-abi=soft \
-mfpu=fpv4-sp-d16 \
-specs=nosys.specs

KL25Z_LDFLAGS=-T ../platform/MKL25Z128xxx4_flash.ld 

BBB_CFLAGS= \
-mcpu=cortex-a8 \
-mthumb
-mfloat-abi=hard

#Platform Information

ifeq ($(PLATFORM),KL25Z) 

CC = arm-none-eabi-gcc
CFLAGS = $(COM_CFLAGS) $(KL25Z_CFLAGS)
SOURCES = $(COM_SOURCES) $(KL25Z_SOURCES_C) $(KL25Z_SOURCES_S)
INCLUDES = $(COM_INCLUDES) $(CMSIS_INCLUDES) $(KL25Z_INCLUDES)
LDFLAGS = $(KL25Z_LDFLAGS)

else ifeq ($(PLATFORM),BBB)

CC = arm-linux-gnueabihf-gcc 
CFLAGS = $(COM_CFLAGS) $(BBB_CFLAGS)
SOURCES = $(COM_SOURCES)
INCLUDES = $(COM_INCLUDES) $(CMSIS_INCLUDES) 

else #HOST

CC = gcc
CFLAGS =  $(COM_CFLAGS)
SOURCES = $(COM_SOURCES)
INCLUDES = $(COM_INCLUDES) $(CMSIS_INCLUDES)
LDFLAGS = 
endif

ifeq ($(PLATFORM),KL25Z)
OBJS:= $(COM_SOURCES:.c=.o) $(KL25Z_SOURCES_C:.c=.o) $(KL25Z_SOURCES_S:.S=.o)
C_DEPS:= $(COM_SOURCES: .c=.d) $(KL25Z_SOURCES_C:.c=.d) $(KL25Z_SOURCES_S:.S=.d)
else
OBJS:= $(SOURCES:.c=.o)
C_DEPS:= $(SOURCES:.c=.d)
endif

#PHONY Information

.PHONY: compile-all build clean

#Defining Targets

%.i: %.c
	-@echo 'Creating pre-processed output of c-program implementation files '
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E $< -o $@ 
	-@echo ' '
	
%.asm: %.c
	-@echo 'Creating assembly output of c-program implementation files '
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@
	-@echo ' '
	
%.o: %.c
	-@echo 'Creating object file for all source files '
	-$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@
	-@echo ' '

%.o: %.S
	-@echo 'Creating object files for assembly files '
	-$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@
	-@echo ' '
	
%.d: %.c
	-@echo 'Creating dependency file'
	-$(CC) $(CPPFLAG) $(CFLAGS) $(INCLUDES) -M $< -o $@
	-@echo ' '

%.d: %.S
	-@echo 'Creating dependency files for assembly files'
	-$(CC) $(CPPFLAG) $(CFLAGS) $(INCLUDES) -M $< -o $@
	-@echo ' '	

#Compile,Build and Clean

compile-all:$(OBJS)

build:$(OBJS) $(C_DEPS)
	-@echo 'To build'
	-$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -Xlinker -Map=project2.map -o project2.elf $(OBJS) 
	-@echo ' '

clean:
	-@echo 'Cleaning the files'
	-$(RM) *.o *.d *.i *.asm *.out project2.elf project2.map
	-@echo ' '


