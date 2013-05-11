if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=54 $BOEFFLA_CONFIG`" ]; then

	echo "54 54 54 54" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequency 54 applied >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=160 $BOEFFLA_CONFIG`" ]; then

	echo "160 160 160 160" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequency 160 applied >> $BOEFFLA_LOGFILE

fi


if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=160and266 $BOEFFLA_CONFIG`" ]; then

	echo "160 160 266 366" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequencies 160/266 applied >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=266and350 $BOEFFLA_CONFIG`" ]; then

	echo "266 266 350 350" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequencies 266/350 applied >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=54to266 $BOEFFLA_CONFIG`" ]; then

	echo "54 108 160 266" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequencies 54/108/160/266 applied >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=108to350 $BOEFFLA_CONFIG`" ]; then

	echo "108 160 266 350" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequencies 108/160/266/350 applied >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=266to533 $BOEFFLA_CONFIG`" ]; then

	echo "266 350 440 533" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequencies 266/350/440/533 applied >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=350to600 $BOEFFLA_CONFIG`" ]; then

	echo "350 440 533 600" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequencies 350/440/533/600 applied >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_frequency=440to700 $BOEFFLA_CONFIG`" ]; then

	echo "440 533 600 700" > /sys/class/misc/gpu_clock_control/gpu_control

	echo $(date) GPU frequencies 440/533/600/700 applied >> $BOEFFLA_LOGFILE

fi
