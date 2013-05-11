# System tweaks: Boeffla-kernel
if /sbin/busybox [ "`/sbin/busybox grep systemtweaks=on $BOEFFLA_CONFIG`" ] || [ -f /system/etc/init.d/*bksystemtweak_005-on ]; then

  # file system tweaks
  /sbin/busybox sysctl -w fs.inotify.max_queued_events=32000
  /sbin/busybox sysctl -w fs.file-max=524288
  /sbin/busybox sysctl -w fs.inotify.max_user_instances=256
  /sbin/busybox sysctl -w fs.inotify.max_user_watches=10240
  /sbin/busybox sysctl -w fs.lease-break-time=10

  # kernel setting tweaks
  /sbin/busybox sysctl -w kernel.msgmax=65536
  /sbin/busybox sysctl -w kernel.msgmni=2048
  /sbin/busybox sysctl -w kernel.panic=10
  /sbin/busybox sysctl -w kernel.random.read_wakeup_threshold=128
  /sbin/busybox sysctl -w kernel.random.write_wakeup_threshold=256
  /sbin/busybox sysctl -w kernel.sched_latency_ns=18000000
  /sbin/busybox sysctl -w kernel.sched_wakeup_granularity_ns=3000000
  /sbin/busybox sysctl -w kernel.sched_min_granularity_ns=1500000
  /sbin/busybox sysctl -w kernel.sem='500 512000 64 2048'
  /sbin/busybox sysctl -w kernel.shmmax=268435456
  /sbin/busybox sysctl -w kernel.threads-max=524288

  # net tweaks
  /sbin/busybox sysctl -w net.core.rmem_max=524288
  /sbin/busybox sysctl -w net.core.wmem_max=524288
  /sbin/busybox sysctl -w net.ipv4.tcp_rmem='6144 87380 524288'
  /sbin/busybox sysctl -w net.ipv4.tcp_tw_recycle=1
  /sbin/busybox sysctl -w net.ipv4.tcp_wmem='6144 87380 524288'

  # vm tweaks
  /sbin/busybox sysctl -w vm.dirty_background_ratio=70
  /sbin/busybox sysctl -w vm.dirty_expire_centisecs=250
  /sbin/busybox sysctl -w vm.dirty_ratio=90
  /sbin/busybox sysctl -w vm.dirty_writeback_centisecs=500
  /sbin/busybox sysctl -w vm.min_free_kbytes=4096
  /sbin/busybox sysctl -w vm.swappiness=60
  
  /sbin/busybox sysctl -w vm.vfs_cache_pressure=10
  /sbin/busybox sync
  /sbin/busybox sysctl -w vm.drop_caches=3

  echo $(date) Boeffla-kernel system tweaks applied >> $BOEFFLA_LOGFILE
  
  # Wait for 1 second to let the tweaks settle
  /sbin/busybox sleep 1
fi


# System tweaks: Hardcore speedmod
if /sbin/busybox [ "`/sbin/busybox grep systemtweaks=smod $BOEFFLA_CONFIG`" ] || [ -f /system/etc/init.d/*bksystemtweak_010-smod ]; then

  # vm tweaks
  echo "12288" > /proc/sys/vm/min_free_kbytes
  echo "1500" > /proc/sys/vm/dirty_writeback_centisecs
  echo "200" > /proc/sys/vm/dirty_expire_centisecs
  echo "0" > /proc/sys/vm/swappiness

  # TCP tweaks
  echo "2" > /proc/sys/net/ipv4/tcp_syn_retries
  echo "2" > /proc/sys/net/ipv4/tcp_synack_retries
  echo "10" > /proc/sys/net/ipv4/tcp_fin_timeout

  echo $(date) Speedmod system tweaks applied >> $BOEFFLA_LOGFILE

  # Wait for 1 second to let the tweaks settle
  /sbin/busybox sleep 1
fi
