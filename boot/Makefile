
TARGET = boot

SDK_ROOT := ../../nRF5_SDK
PROJ_DIR := ..

OBJS   = bomain.o
OBJS  += gcc_startup_nrf52.o


#########################################################################
#########################################################################

VPATH := .
#VPATH += :./sys
GPATH := $(VPATH)


#########################################################################

GNU_INSTALL_ROOT := /usr/local/gcc-arm-none-eabi-4_9-2015q3/bin/
GNU_VERSION := 4.9.3
GNU_PREFIX  := arm-none-eabi
# Toolchain commands
CC      := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-gcc
CXX     := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-c++
AS      := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-as
AR      := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-ar -r
LD      := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-ld -v -nostartfiles
NM      := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-nm
OBJDUMP := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-objdump
OBJCOPY := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-objcopy
SIZE    := $(GNU_INSTALL_ROOT)$(GNU_PREFIX)-size



OPT = -Os
TARGET_ARCH = -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=soft
#WARNINGS = -Wall -Wshadow -Wcast-qual -Wwrite-strings -Winline -Wno-strict-aliasing 
WARNINGS = -Wall
F_NO_EXCEPTIONS = -fno-exceptions #disabling exceptions saves code space


CFLAGS  =  $(WARNINGS)
CFLAGS +=  $(TARGET_ARCH)
CFLAGS +=  $(F_NO_EXCEPTIONS)
CFLAGS += -nostdlib -std=c99
CFLAGS += -fno-builtin -fshort-enums
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-common
CFLAGS += $(OPT)
CFLAGS += -DNRF52832_XXAA
CFLAGS += -DS112
CFLAGS += -DSOFTDEVICE_PRESENT
CFLAGS += -DSWI_DISABLE0
CFLAGS += -DLEVEL1
##CFLAGS += -g


CFLAGS += -I$(PROJ_DIR)
# Include folders common to all targets
CFLAGS += -I$(SDK_ROOT)/components
CFLAGS += -I$(SDK_ROOT)/components/softdevice/common
CFLAGS += -I$(SDK_ROOT)/components/softdevice/s112/headers
CFLAGS += -I$(SDK_ROOT)/components/softdevice/s112/headers/nrf52
CFLAGS += -I$(SDK_ROOT)/components/toolchain
CFLAGS += -I$(SDK_ROOT)/components/toolchain/gcc
CFLAGS += -I$(SDK_ROOT)/components/toolchain/cmsis/include
CFLAGS += -I$(SDK_ROOT)/components/boards
CFLAGS += -I$(SDK_ROOT)/components/device
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/common
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/swi
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/comp
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/clock
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/usbd
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/delay
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/pwm
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/pdm
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/hal
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/twi_master
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/timer
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/i2s
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/rtc
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/ppi
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/gpiote
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/rng
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/power
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/uart
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/saadc
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/wdt
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/twis_slave
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/spi_slave
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/spi_master
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/qdec
CFLAGS += -I$(SDK_ROOT)/components/drivers_nrf/lpcomp
CFLAGS += -I$(SDK_ROOT)/components/ble/common
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_dtm
CFLAGS += -I$(SDK_ROOT)/components/ble/nrf_ble_gatt
CFLAGS += -I$(SDK_ROOT)/components/ble/nrf_ble_qwr
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_racp
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_advertising
CFLAGS += -I$(SDK_ROOT)/components/ble/peer_manager
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_rscs_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_bas_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_hrs_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_ancs_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_ans_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_ias_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_nus_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_cts_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_lbs_c
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_rscs
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_nus
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_hids
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_hrs
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_ias
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_gls
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_bas
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_lls
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_dfu
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_lbs
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_hts
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_cscs
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_tps
CFLAGS += -I$(SDK_ROOT)/components/ble/ble_services/ble_dis
CFLAGS += -I$(SDK_ROOT)/components/libraries/pwm
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/cdc/acm
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/hid/generic
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/msc
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/hid
CFLAGS += -I$(SDK_ROOT)/components/libraries/experimental_log
CFLAGS += -I$(SDK_ROOT)/components/libraries/fstorage
CFLAGS += -I$(SDK_ROOT)/components/libraries/mutex
CFLAGS += -I$(SDK_ROOT)/components/libraries/gpiote
CFLAGS += -I$(SDK_ROOT)/components/libraries/experimental_log/src
CFLAGS += -I$(SDK_ROOT)/components/libraries/experimental_memobj
CFLAGS += -I$(SDK_ROOT)/components/libraries/queue
CFLAGS += -I$(SDK_ROOT)/components/libraries/pwr_mgmt
CFLAGS += -I$(SDK_ROOT)/components/libraries/experimental_section_vars
CFLAGS += -I$(SDK_ROOT)/components/libraries/slip
CFLAGS += -I$(SDK_ROOT)/components/libraries/mem_manager
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/cdc
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/hid/mouse
CFLAGS += -I$(SDK_ROOT)/components/libraries/ecc
CFLAGS += -I$(SDK_ROOT)/components/libraries/atomic
CFLAGS += -I$(SDK_ROOT)/components/libraries/scheduler
CFLAGS += -I$(SDK_ROOT)/components/libraries/cli
CFLAGS += -I$(SDK_ROOT)/components/libraries/crc16
CFLAGS += -I$(SDK_ROOT)/components/libraries/util
CFLAGS += -I$(SDK_ROOT)/components/libraries/csense_drv
CFLAGS += -I$(SDK_ROOT)/components/libraries/csense
CFLAGS += -I$(SDK_ROOT)/components/libraries/balloc
CFLAGS += -I$(SDK_ROOT)/components/libraries/low_power_pwm
CFLAGS += -I$(SDK_ROOT)/components/libraries/hardfault
CFLAGS += -I$(SDK_ROOT)/components/libraries/uart
CFLAGS += -I$(SDK_ROOT)/components/libraries/hci
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/hid/kbd
CFLAGS += -I$(SDK_ROOT)/components/libraries/timer
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/config
CFLAGS += -I$(SDK_ROOT)/components/libraries/led_softblink
CFLAGS += -I$(SDK_ROOT)/components/libraries/twi_mngr
CFLAGS += -I$(SDK_ROOT)/components/libraries/strerror
CFLAGS += -I$(SDK_ROOT)/components/libraries/crc32
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd/class/audio
CFLAGS += -I$(SDK_ROOT)/components/libraries/button
CFLAGS += -I$(SDK_ROOT)/components/libraries/usbd
CFLAGS += -I$(SDK_ROOT)/components/libraries/atomic_fifo
CFLAGS += -I$(SDK_ROOT)/components/libraries/fds
CFLAGS += -I$(SDK_ROOT)/components/libraries/twi
CFLAGS += -I$(SDK_ROOT)/external/fprintf
CFLAGS += -I$(SDK_ROOT)/external/segger_rtt



LINKER_SCRIPT = $(TARGET).ld


# Linker flags
#LDFLAGS  = -lc -lnosys -lm
#LDFLAGS += $(OPT)
#LDFLAGS += -mthumb -mabi=aapcs -T$(LINKER_SCRIPT)
#LDFLAGS += -mcpu=cortex-m4
## let linker dump unused sections
##LDFLAGS += -Wl,--gc-sections
#LDFLAGS += --specs=nano.specs

LDFLAGS = -Map=$(@:.elf=.map)


#########################################################################

#########################################################################
.PRECIOUS: %.o %.elf
.PHONY: all clean $(TARGET).sym $(TARGET).lss
.PHONY: $(TARGET).hex $(TARGET).bin


all: $(TARGET).elf $(TARGET).hex


$(TARGET).lss: $(TARGET).elf
	@$(OBJDUMP) -h -S -D $< > $@

$(TARGET).sym:
	@$(NM) -n $(TARGET).elf > $@


$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@


$(TARGET).elf: $(OBJS)
	$(LD) $(LDFLAGS) -T$(LINKER_SCRIPT) -o $@ $^ ../libgcc.a
	$(SIZE) $@



# Create object files from C source files
%.c.o:
	$(CC) -MP -MD -c -o $@ $(CFLAGS) $<

# Create object files from C++ source files
%.cpp.o:
	$(CC) -MP -MD -c -o $@ $(CFLAGS) $(CXXFLAGS) $<

# Create object files from assembly source files
%.S.o %.s.o.o:
	$(CC) -x assembler-with-cpp $(ASMFLAGS) $<


clean:
	@rm -f *.o *.elf *.bin *.hex *.lss *.map *.sym 

##########################################################################
#
#clean: ; for i in $(SUBDIRS); do make -C $$i clean; done
#	@rm -f *.o *.elf *.bin *.hex *.lss *.map *.sym
#
#
##########################################################################

##%: ; make -C $@
##%: ; make -C tsk/$@

#########################################################################

