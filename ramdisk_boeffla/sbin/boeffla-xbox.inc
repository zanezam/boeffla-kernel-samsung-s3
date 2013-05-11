# xbox controller support
if [ "`/sbin/busybox grep xbox=on $BOEFFLA_CONFIG`" ]; then

	insmod /lib/modules/xpad.ko

	echo $(date) "XBox support enabled" >> $BOEFFLA_LOGFILE
fi
