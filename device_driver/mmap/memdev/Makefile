ifeq ($(KERNELRELEASE),)

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

modules_install:
	make -C $(KDIR) M=$(PWD) modules_install

clean:
	rm -rf *.o *.ko .depend *.symvers *.mod *.mod.o *.mod.c Module.* modules.* .*.cmd $(SOURCE)

else

MODULE_NAME := memdev
obj-m := $(MODULE_NAME).o

endif