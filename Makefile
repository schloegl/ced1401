obj-m := cedusb.o
cedusb-objs := usb1401.o ced_ioc.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
KBUILD_EXTRA_SYMBOLS := $(PWD)
EXTRA_CFLAGS += -DDEBUG=1 -DVERBOSE=1
EXTRA_CFLAGS += -I$(HOME)/src/ced1401

all: try1432
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
	rm try1432

%.o:%.c
	gcc $(EXTRA_CFLAGS) -c $^

try1432 : try1432.c use1401.o
	gcc $(EXTRA_CFLAGS) try1432.c use1401.o -o $@

