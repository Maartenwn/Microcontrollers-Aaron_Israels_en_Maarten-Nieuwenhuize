TARGET	= ipac

# Application source en include includes
SRC_DIR	= ./source
INC_DIR = ./include

# NutOS location (includes and libs)
NUT_INC = c:/ethernut-4.3.3/nut/include
NUT_BUILD_INC = c:/ethernut-4.3.3/build/gcc/atmega2561/lib/include
NUT_LIB_DIR = c:/ethernut-4.3.3/build/gcc/atmega2561/lib

# WinAvr includes
AVR_INC = c:/winavr/avr/include


# Compiler, assembler & linker (flags)
CC		= 	avr-gcc
CFLAGS	= 	-mmcu=atmega2561 -Os -Wall -Wstrict-prototypes -DNUT_CPU_FREQ=14745600 \
			-D__HARVARD_ARCH__ -DNUTOS_VERSION=433 \
			-Wa,-ahlms=$(SRC_DIR)/$*lst
ASFLAGS = 	-mmcu=atmega2561 -I. -x assembler-with-cpp -Wa,-ahlms=$(SRC_DIR)/$*lst,-gstabs 
LDFLAGS	=	-mmcu=atmega2561 -Wl,--defsym=main=0,-Map=TIStreamer.map,--cref


# =================================================================================
# Source files
CFILES =        main.c			\
				uart0driver.c	\
				log.c			\
                led.c			\
				keyboard.c		\
				display.c		\
                vs10xx.c		\
                remcon.c		\
                watchdog.c		\
				mmc.c			\
				spidrv.c        \
                mmcdrv.c        \
                fat.c			\
				flash.c			\
				rtc.c			\
				statemachine.c  \
				backlight.c		\
				state_welcomescreen.c 	\
				state_alarmscreen.c 	\
				state_alarmSoundChooserscreen.c 	\
				state_clockscreen.c 	\
				state_confirmationscreen.c \
				state_factoryResetscreen.c \
				state_menuscreen.c 			\
				state_newDailyAlarmscreen.c \
				state_newOnceAlarmscreen.c 	\
				state_Radioscreen.c 		\
				state_settingsscreen.c 		\
				state_settingsTimeZonescreen.c 	\
				state_sleepTimerscreen.c 	\
				state_syncingscreen.c 	\
				state_timezoneStartscreen.c 	\
				state_typeOfAlarmscreen.c \
				ethernet.c					\
				TimeCalculations.c
# Header files.
HFILES =        display.h        keyboard.h              \
                led.h                            \
                portio.h         remcon.h         log.h          \
                system.h                 settings.h     \
                                  inet.h         \
                platform.h       version.h        update.h       \
                           uart0driver.h    typedefs.h     \
                       vs10xx.h         audio.h        \
                watchdog.h       mmc.h             \
                flash.h          spidrv.h         command.h      \
                parse.h          mmcdrv.h         fat.h          \
                fatdrv.h         flash.h	  	rtc.h		\
				statemachine.h state_welcomescreen.h \
				state_welcomescreen.h 	\
				state_alarmscreen.h 	\
				state_alarmSoundChooserscreen.h 	\
				state_clockscreen.h 	\
				state_confirmationscreen.h \
				state_factoryResetscreen.h \
				state_menuscreen.h 			\
				state_newDailyAlarmscreen.h \
				state_newOnceAlarmscreen.h 	\
				state_Radioscreen.h 		\
				state_settingsscreen.h 		\
				state_settingsTimeZonescreen.h 	\
				state_sleepTimerscreen.h 	\
				state_syncingscreen.h 	\
				state_timezoneStartscreen.h 	\
				state_typeOfAlarmscreen.h 	\
				ethernet.h		 \
				TimeCalculations.h



# Alle source files in de ./source dir
SRCS =	$(addprefix $(SRC_DIR)/,$(CFILES))
OBJS = 	$(SRCS:.c=.o)

NUT_LIBS = $(NUT_LIB_DIR)/nutinit.o -lnutpro -lnutnet -lnutpro -lnutfs -lnutos -lnutdev -lnutarch -lnutnet -lnutcrt -lnutdev


# Alle includes (header files) in de ./header dir
INCS =	$(addprefix $(INC_DIR)/,$(HFILES))

# Linking rule. All *.o to elf file. Then convert to *.hex
$(TARGET):	$(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -L$(NUT_LIB_DIR) $(NUT_LIBS) -o $@.elf
	avr-objcopy -O ihex $@.elf $@.hex
#	hex2bin -ebin $@.hex

# Compiling the objs's. avr-gcc autocalls assembler	
$(SRC_DIR)/%o:	$(SRC_DIR)/%c 
	$(CC) -c $< $(CFLAGS) -I$(INC_DIR) -I$(NUT_INC) -I$(AVR_INC) -o $@

	
all: $(TARGET)

debug:
	
	@echo $(OBJS)


.PHONY: clean
clean:
	-rm -f $(OBJS)
	-rm -f $(SRCS:.c=.lst)
	-rm -f *.hex *.elf *.map *.bin


