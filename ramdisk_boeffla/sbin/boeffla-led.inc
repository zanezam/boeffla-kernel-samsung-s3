# LED fading

if /sbin/busybox [ "`/sbin/busybox grep led_fading=fade $BOEFFLA_CONFIG`" ]; then

  echo "1" > /sys/class/sec/led/led_fade
  echo "40" > /sys/class/sec/led/led_intensity

  echo $(date) "LED fading normal enabled" >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep led_fading=fade-bright $BOEFFLA_CONFIG`" ]; then

  echo "1" > /sys/class/sec/led/led_fade
  echo "192" > /sys/class/sec/led/led_intensity

  echo $(date) "LED fading bright enabled" >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep led_fading=blink-bright $BOEFFLA_CONFIG`" ]; then

  echo "0" > /sys/class/sec/led/led_fade
  echo "192" > /sys/class/sec/led/led_intensity

  echo $(date) "LED blinking bright enabled" >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep led_fading=fade-dark $BOEFFLA_CONFIG`" ]; then

  echo "1" > /sys/class/sec/led/led_fade
  echo "15" > /sys/class/sec/led/led_intensity

  echo $(date) "LED fading dark enabled" >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep led_fading=blink-dark $BOEFFLA_CONFIG`" ]; then

  echo "0" > /sys/class/sec/led/led_fade
  echo "15" > /sys/class/sec/led/led_intensity

  echo $(date) "LED blinking dark enabled" >> $BOEFFLA_LOGFILE

fi


# LED speed

if /sbin/busybox [ "`/sbin/busybox grep led_speed=2x $BOEFFLA_CONFIG`" ]; then

  echo "2" > /sys/class/sec/led/led_speed

  echo $(date) "LED speed set to 2x" >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep led_speed=3x $BOEFFLA_CONFIG`" ]; then

  echo "3" > /sys/class/sec/led/led_speed

  echo $(date) "LED speed set to 3x" >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep led_speed=4x $BOEFFLA_CONFIG`" ]; then

  echo "4" > /sys/class/sec/led/led_speed

  echo $(date) "LED speed set to 4x" >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep led_speed=5x $BOEFFLA_CONFIG`" ]; then

  echo "5" > /sys/class/sec/led/led_speed

  echo $(date) "LED speed set to 5x" >> $BOEFFLA_LOGFILE

fi
