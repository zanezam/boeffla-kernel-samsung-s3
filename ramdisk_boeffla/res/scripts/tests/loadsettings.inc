SYSTEM_DEVICE="/dev/block/mmcblk0p9"

# Remount system device to rw
/sbin/busybox mount -o remount,rw -t ext4 $SYSTEM_DEVICE /system

# Delete all old settings
/sbin/busybox rm /system/etc/init.d/*_???bk*

# Loop through settings file and copy scripts
for file in `cat $SETTINGSFILE`;
do
	
	# strip path away
	file="` /sbin/busybox echo $file | /sbin/busybox sed 's/\/system\/etc\/init.d\///' `"

	# To allow migration across script versions, rename to current version number
	file="` /sbin/busybox echo $file | /sbin/busybox sed 's/_000bk/_001bk/' `"
	file="` /sbin/busybox echo $file | /sbin/busybox sed 's/_002bk/_001bk/' `"
	file="` /sbin/busybox echo $file | /sbin/busybox sed 's/_003bk/_001bk/' `"

	# Try a copy from both main and addons folder (one of them should succeed)
	/sbin/busybox cp /res/scripts/$file /system/etc/init.d/
	/sbin/busybox cp /res/scripts/addons/$file /system/etc/init.d/

done

# delete any empty script files
for file in /system/etc/init.d/* ; 
do
	if ! [ -s $file ]; then
		rm $file
	fi
done

# set permissions of scripts
/sbin/busybox chmod 755 /system/etc/init.d/*

# Remount system device back to rw
/sbin/busybox mount -o remount,ro -t ext4 $SYSTEM_DEVICE /system

# execute copied files to apply settings
for file in /system/etc/init.d/*_???bk* ; 
do
	/sbin/busybox sh "$file"
done
