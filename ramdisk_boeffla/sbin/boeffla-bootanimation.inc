# check whether custom boot animation is available to be played
if /sbin/busybox [ -f /data/local/bootanimation.zip ] || /sbin/busybox [ -f /system/media/bootanimation.zip ]; then
        /system/bin/bootanimation &
else
        /system/bin/samsungani &
fi
