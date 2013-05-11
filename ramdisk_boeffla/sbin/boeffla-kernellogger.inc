if /sbin/busybox [ "`/sbin/busybox grep kernellogger=on $BOEFFLA_CONFIG`" ]; then

  echo 1 > /sys/kernel/printk_mode/printk_mode

  echo $(date) Kernel logger enabled >> $BOEFFLA_LOGFILE

else

  echo 0 > /sys/kernel/printk_mode/printk_mode

  echo $(date) Kernel logger disabled >> $BOEFFLA_LOGFILE

fi
