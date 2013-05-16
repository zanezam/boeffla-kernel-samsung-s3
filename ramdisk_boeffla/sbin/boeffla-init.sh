#!/sbin/busybox sh
#
# credits to various people

# define config file pathes, file variables and block devices
BOEFFLA_PATH="/data/media/boeffla-kernel"
BOEFFLA_CONFIG="$BOEFFLA_PATH/boeffla-kernel.conf"

BOEFFLA_DATA_PATH="/data/media/boeffla-kernel-data"
BOEFFLA_LOGFILE="$BOEFFLA_DATA_PATH/boeffla-kernel.log"

SYSTEM_DEVICE="/dev/block/mmcblk0p9"
CACHE_DEVICE="/dev/block/mmcblk0p8"
DATA_DEVICE="/dev/block/mmcblk0p12"

# check if Boeffla kernel path exists and if so, execute config file
if [ -d "$BOEFFLA_PATH" ] ; then

	# check and create or update the configuration file
	. /sbin/boeffla-configfile.inc

else
	BOEFFLA_CONFIG=""
fi

# If not yet exists, create a boeffla-kernel-data folder on sdcard 
# which is used for many purposes (set permissions and owners correctly)
if [ ! -d "$BOEFFLA_DATA_PATH" ] ; then
	/sbin/busybox mkdir $BOEFFLA_DATA_PATH
	/sbin/busybox chmod 775 $BOEFFLA_DATA_PATH
	/sbin/busybox chown 1023:1023 $BOEFFLA_DATA_PATH
fi

# maintain log file history
rm $BOEFFLA_LOGFILE.3
mv $BOEFFLA_LOGFILE.2 $BOEFFLA_LOGFILE.3
mv $BOEFFLA_LOGFILE.1 $BOEFFLA_LOGFILE.2
mv $BOEFFLA_LOGFILE $BOEFFLA_LOGFILE.1

# Initialize the log file (chmod to make it readable also via /sdcard link)
echo $(date) Boeffla-Kernel initialisation started > $BOEFFLA_LOGFILE
/sbin/busybox chmod 666 $BOEFFLA_LOGFILE
/sbin/busybox cat /proc/version >> $BOEFFLA_LOGFILE
echo "=========================" >> $BOEFFLA_LOGFILE

# Include version information about firmware in log file
/sbin/busybox grep ro.build.version /system/build.prop >> $BOEFFLA_LOGFILE
echo "=========================" >> $BOEFFLA_LOGFILE

# First thing: Custom boot animation support
. /sbin/boeffla-bootanimation.inc

# Now wait for the rom to finish booting up
# (by checking for any android process)
while ! /sbin/busybox pgrep com.android ; do
  /sbin/busybox sleep 1
done
echo $(date) Rom boot trigger detected, continuing after 8 more seconds... >> $BOEFFLA_LOGFILE
/sbin/busybox sleep 8

# Governor
. /sbin/boeffla-governor.inc

# IO Scheduler
. /sbin/boeffla-scheduler.inc

# CPU max frequency
. /sbin/boeffla-cpumaxfrequency.inc

# CPU undervolting support
. /sbin/boeffla-cpuundervolt.inc

# GPU frequency
. /sbin/boeffla-gpufrequency.inc

# GPU undervolting support
. /sbin/boeffla-gpuundervolt.inc

# LED settings
. /sbin/boeffla-led.inc

# Touch boost switch
. /sbin/boeffla-touchboost.inc

# MDNIE settings (sharpness fix)
. /sbin/boeffla-mdnie.inc

# AC and USB charging rate
. /sbin/boeffla-chargingrate.inc

# System tweaks
. /sbin/boeffla-systemtweaks.inc

# zRam support
. /sbin/boeffla-zram.inc

# Ext4 tweaks
. /sbin/boeffla-ext4.inc

# Sdcard buffer tweaks
. /sbin/boeffla-sdcard.inc

# Support for additional network protocols (CIFS, NFS)
. /sbin/boeffla-network.inc

# Support for xbox controller
. /sbin/boeffla-xbox.inc

# exFat support
. /sbin/boeffla-exfat.inc

# Android logger
. /sbin/boeffla-androidlogger.inc

# Kernel logger
. /sbin/boeffla-kernellogger.inc

# Turn off debugging for certain modules
. /sbin/boeffla-disabledebugging.inc

# Boeffla Sound
. /sbin/boeffla-sound.inc

# Auto root support
. /sbin/boeffla-autoroot.inc

# Configuration app support
. /sbin/boeffla-app.inc

# EFS backup
. /sbin/boeffla-efsbackup.inc

# init.d support
. /sbin/boeffla-initd.inc

# Finished
echo $(date) Boeffla-Kernel initialisation completed >> $BOEFFLA_LOGFILE
