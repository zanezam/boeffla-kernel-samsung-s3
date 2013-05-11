# Initialize variables and read settings for AC and USB charge rates
AC_RATE=""
AC_RATE=$(/sbin/busybox sed -n -e 's/.*charge_ac=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

USB_RATE=""
USB_RATE=$(/sbin/busybox sed -n -e 's/.*charge_usb=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

# AC charge rate
# Only apply if value valid, if not apply standard value of 1100
if [ ! -z "$AC_RATE" ] && [ "${AC_RATE:-0}" -ge 100 ] && [ "${AC_RATE:-0}" -le 1600 ]; then
  echo "$AC_RATE" > /sys/kernel/charge_levels/charge_level_ac
  echo $(date) "AC charge rate set to $AC_RATE mA" >> $BOEFFLA_LOGFILE
else
  echo "1100" > /sys/kernel/charge_levels/charge_level_ac
fi


# USB charge rate
# Only apply if value valid, if not apply standard value of 475
if [ ! -z "$USB_RATE" ] && [ "${USB_RATE:-0}" -ge 0 ] && [ "${USB_RATE:-0}" -le 1600 ]; then
  echo "$USB_RATE" > /sys/kernel/charge_levels/charge_level_usb
  echo $(date) "USB charge rate set to $USB_RATE mA" >> $BOEFFLA_LOGFILE
else
  echo "475" > /sys/kernel/charge_levels/charge_level_usb
fi
