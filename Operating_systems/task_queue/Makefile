obj-m := zad3ful.o
zad3ful-objs := zad3.o queue.o
KERNELDIR=/lib/modules/$(shell uname -r)/build

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

 
