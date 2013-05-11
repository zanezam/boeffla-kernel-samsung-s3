if /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting=25 $BOEFFLA_CONFIG`" ]; then
  echo "1375 1338 1275 1213 1175 1125 1075 1025 975 950 938 925 925 900 875 " > /sys/devices/system/cpu/cpu0/cpufreq/UV_mV_table
  echo $(date) CPU undervolting by -25mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting=50 $BOEFFLA_CONFIG`" ]; then
  echo "1350 1313 1250 1188 1150 1100 1050 1000 950 925 913 900 900 875 850 " > /sys/devices/system/cpu/cpu0/cpufreq/UV_mV_table
  echo $(date) CPU undervolting by -50mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting=75 $BOEFFLA_CONFIG`" ]; then
  echo "1325 1288 1225 1163 1125 1075 1025 975 925 900 888 875 875 850 825 " > /sys/devices/system/cpu/cpu0/cpufreq/UV_mV_table
  echo $(date) CPU undervolting by -75mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting=100 $BOEFFLA_CONFIG`" ]; then
  echo "1300 1263 1200 1138 1100 1050 1000 950 900 875 863 850 850 825 800 " > /sys/devices/system/cpu/cpu0/cpufreq/UV_mV_table
  echo $(date) CPU undervolting by -100mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting=light $BOEFFLA_CONFIG`" ]; then
  echo "1400 1363 1300 1238 1200 1150 1075 1025 975 950 938 900 900 875 850 " > /sys/devices/system/cpu/cpu0/cpufreq/UV_mV_table
  echo $(date) CPU undervolting light applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting=medium $BOEFFLA_CONFIG`" ]; then
  echo "1375 1338 1275 1213 1175 1125 1050 1000 950 925 913 875 875 850 825 " > /sys/devices/system/cpu/cpu0/cpufreq/UV_mV_table
  echo $(date) CPU undervolting medium applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting=heavy $BOEFFLA_CONFIG`" ]; then
  echo "1350 1313 1250 1188 1150 1100 1025 975 925 900 888 850 850 825 800 " > /sys/devices/system/cpu/cpu0/cpufreq/UV_mV_table
  echo $(date) CPU undervolting heavy applied >> $BOEFFLA_LOGFILE
fi
