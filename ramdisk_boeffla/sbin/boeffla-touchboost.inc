# Touch boost

if /sbin/busybox [ "`/sbin/busybox grep touch_boost=off $BOEFFLA_CONFIG`" ]; then

  echo "0" > /sys/class/misc/touchboost_switch/touchboost_switch

  echo $(date) "Touch boost disabled" >> $BOEFFLA_LOGFILE

fi
