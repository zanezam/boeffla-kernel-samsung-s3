# unload exfat drivers if configured to off in boeffla config file

if [ "`/sbin/busybox grep exfat=off $BOEFFLA_CONFIG`" ]; then
  /sbin/busybox rmmod /lib/modules/exfat_fs.ko
  /sbin/busybox rmmod /lib/modules/exfat_core.ko
fi
