# Initialize variable and read zCache size setting from config file
SIZE=""
SIZE=$(/sbin/busybox sed -n -e 's/.*zRam=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)


# Check if a setting in tweaks app activates/overrides this value

if [ -f /system/etc/init.d/*bkzram*300 ]; then
	SIZE="300"
fi

if [ -f /system/etc/init.d/*bkzram*400 ]; then
	SIZE="400"
fi

if [ -f /system/etc/init.d/*bkzram*600 ]; then
	SIZE="600"
fi


# Only apply value if valid and not off
if [ ! "$SIZE" = "off" ] && [ "${SIZE:-0}" -ge 100 ] && [ "${SIZE:-0}" -le 800 ] ; then

	if [ -e /sys/block/zram0/disksize ] ; then

		swapoff /dev/block/zram0

		echo 1 > /sys/block/zram0/reset
		echo $(( $SIZE * 1024 * 1024 )) > /sys/block/zram0/disksize
		echo 1 > /sys/block/zram0/initstate

		swapon /dev/block/zram0

		/sbin/busybox sysctl -w vm.swappiness=70

		echo $(date) zRam swap activated with $SIZE MB size >> $BOEFFLA_LOGFILE
		
		# Give settings some time to settle
		/sbin/busybox sleep 1

	fi
fi
