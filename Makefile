obj-m := cedusb.o
cedusb-objs := usb1401.o ced_ioc.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
EXTRA_CFLAGS += -DDEBUG=1 -DVERBOSE=1
EXTRA_CFLAGS += -I$(HOME)/src/ced1401

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm try1432

%.o:%.c
	gcc $(EXTRA_CFLAGS) -c $<

try1432 : try1432.c use1401.o
	gcc $(EXTRA_CFLAGS) $^ -o $@

