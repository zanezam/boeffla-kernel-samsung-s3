# MDNIE presets

# Hardcore speedmod sharpness fix
if /sbin/busybox [ "`/sbin/busybox grep sharpness_fix=on $BOEFFLA_CONFIG`" ]; then

  echo "1" > /sys/class/misc/mdnie_preset/mdnie_preset

  echo $(date) "Sharpness fix enabled" >> $BOEFFLA_LOGFILE

fi
