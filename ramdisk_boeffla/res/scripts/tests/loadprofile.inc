SYSTEM_DEVICE="/dev/block/mmcblk0p9"

# Remount system device to rw
/sbin/busybox mount -o remount,rw -t ext4 $SYSTEM_DEVICE /system

# Delete affected current settings
/sbin/busybox rm /system/etc/init.d/*bkgov*
/sbin/busybox rm /system/etc/init.d/*bksched*int*
/sbin/busybox rm /system/etc/init.d/*bksched*ext*
/sbin/busybox rm /system/etc/init.d/*bkcpufreq*
/sbin/busybox rm /system/etc/init.d/*bkcpuuv*
/sbin/busybox rm /system/etc/init.d/*bkgpufreq*
/sbin/busybox rm /system/etc/init.d/*bkgpuuv*

# Copy default scripts
/sbin/busybox cp /res/scripts/$GOVERNOR_DEFAULT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$SCHEDULERINT_DEFAULT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$SCHEDULEREXT_DEFAULT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$CPUFREQ_DEFAULT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$CPUUV_DEFAULT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$GPUFREQ_DEFAULT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$GPUUV_DEFAULT /system/etc/init.d/

# set permissions of scripts
/sbin/busybox chmod 755 /system/etc/init.d/*

# execute all boeffla kernel init.d files to apply settings
for file in /system/etc/init.d/*_???bk* ; 
do
	/sbin/busybox sh "$file"
done

# Delete default settings
/sbin/busybox rm /system/etc/init.d/*bkgov*
/sbin/busybox rm /system/etc/init.d/*bksched*int*
/sbin/busybox rm /system/etc/init.d/*bksched*ext*
/sbin/busybox rm /system/etc/init.d/*bkcpufreq*
/sbin/busybox rm /system/etc/init.d/*bkcpuuv*
/sbin/busybox rm /system/etc/init.d/*bkgpufreq*
/sbin/busybox rm /system/etc/init.d/*bkgpuuv*

# Copy profile scripts
/sbin/busybox cp /res/scripts/$GOVERNOR /system/etc/init.d/
/sbin/busybox cp /res/scripts/$SCHEDULERINT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$SCHEDULEREXT /system/etc/init.d/
/sbin/busybox cp /res/scripts/$CPUFREQ /system/etc/init.d/
/sbin/busybox cp /res/scripts/$CPUUV /system/etc/init.d/
/sbin/busybox cp /res/scripts/$GPUFREQ /system/etc/init.d/
/sbin/busybox cp /res/scripts/$GPUUV /system/etc/init.d/

# set permissions of scripts
/sbin/busybox chmod 755 /system/etc/init.d/*

# execute all boeffla kernel init.d files to apply settings
for file in /system/etc/init.d/*_???bk* ; 
do
	/sbin/busybox sh "$file"
done

# Remount system device back to rw
/sbin/busybox mount -o remount,ro -t ext4 $SYSTEM_DEVICE /system
