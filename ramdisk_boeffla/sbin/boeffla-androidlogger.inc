if /sbin/busybox [ "`/sbin/busybox grep androidlogger=on $BOEFFLA_CONFIG`" ]; then

  echo 1 > /sys/kernel/logger_mode/logger_mode

  echo $(date) Android logger enabled >> $BOEFFLA_LOGFILE

else

  echo 0 > /sys/kernel/logger_mode/logger_mode

  echo $(date) Android logger disabled >> $BOEFFLA_LOGFILE

fi
