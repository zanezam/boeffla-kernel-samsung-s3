# change scheduler to deadline, noop, cfq or sio (if not set to default)

# Scheduler for internal sd memory

SCHEDULER=""

if /sbin/busybox [ "`/sbin/busybox grep scheduler_int=deadline $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="deadline"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_int=noop $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="noop"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_int=cfq $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="cfq"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_int=sio $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="sio"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_int=row $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="row"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_int=bfq $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="bfq"
fi

if [ ! -z $SCHEDULER ]; then
  echo "$SCHEDULER" > /sys/block/mmcblk0/queue/scheduler
  echo $(date) Internal sd memory scheduler set to $SCHEDULER >> $BOEFFLA_LOGFILE
fi


# Scheduler for external sd memory

SCHEDULER=""

if /sbin/busybox [ "`/sbin/busybox grep scheduler_ext=deadline $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="deadline"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_ext=noop $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="noop"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_ext=cfq $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="cfq"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_ext=sio $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="sio"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_ext=row $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="row"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler_ext=bfq $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="bfq"
fi

if [ ! -z $SCHEDULER ]; then
  echo "$SCHEDULER" > /sys/block/mmcblk1/queue/scheduler
  echo $(date) External sd memory scheduler set to $SCHEDULER >> $BOEFFLA_LOGFILE
fi
