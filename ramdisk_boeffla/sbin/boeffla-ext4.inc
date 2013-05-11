if [ ! "`/sbin/busybox grep ext4tweaks=off $BOEFFLA_CONFIG`" ]; then
	sync
	/sbin/busybox mount -o remount,commit=20,noatime $CACHE_DEVICE /cache

	sync
	/sbin/busybox mount -o remount,commit=20,noatime $DATA_DEVICE /data

	sync
	/sbin/busybox echo $(date) Ext4 tweaks applied >> $BOEFFLA_LOGFILE
fi
