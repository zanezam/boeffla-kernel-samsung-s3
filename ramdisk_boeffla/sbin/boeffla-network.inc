# CIFS support
if [ "`/sbin/busybox grep network_cifs=on $BOEFFLA_CONFIG`" ]; then

	insmod /lib/modules/cifs.ko

	echo $(date) "CIFS support enabled" >> $BOEFFLA_LOGFILE
fi


# NFS support
if [ "`/sbin/busybox grep network_nfs=on $BOEFFLA_CONFIG`" ]; then

	insmod /lib/modules/sunrpc.ko
	insmod /lib/modules/auth_rpcgss.ko
	insmod /lib/modules/lockd.ko
	insmod /lib/modules/nfs.ko

	echo $(date) "NFS support enabled" >> $BOEFFLA_LOGFILE
fi
