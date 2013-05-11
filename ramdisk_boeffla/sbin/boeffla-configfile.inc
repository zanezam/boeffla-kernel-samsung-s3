# Current version of config file
CONFVERSION="Config-version-001"

# check if current config file has correct version number and delete if not
if ! /sbin/busybox [ "`/sbin/busybox grep $CONFVERSION $BOEFFLA_CONFIG`" ]; then
	/sbin/busybox rm $BOEFFLA_CONFIG
fi


# check if config file exists and create a new one if not
if [ ! -f $BOEFFLA_CONFIG ] ; then

	echo "Boeffla-Kernel configuration" > $BOEFFLA_CONFIG
	echo $CONFVERSION >> $BOEFFLA_CONFIG
	echo "============================" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG

	# change file permissions to make file readable via /sdcard link as well
	chmod 666 $BOEFFLA_CONFIG

fi


# Now add all the required options that do not yet exists


# Governor and scheduler

if ! /sbin/busybox [ "`/sbin/busybox grep governor $BOEFFLA_CONFIG`" ]; then
	echo "governor=default (default/lulz/zzmoove/pbatt/pmod/p1c/p2c/psmod/zbatt/zopt/zperf)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep scheduler_int $BOEFFLA_CONFIG`" ]; then
	echo "scheduler_int=default (default/cfq/deadline/noop/sio/row/bfq)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep scheduler_ext $BOEFFLA_CONFIG`" ]; then
	echo "scheduler_ext=default (default/cfq/deadline/noop/sio/row/bfq)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# CPU max frequency and undervolting

if ! /sbin/busybox [ "`/sbin/busybox grep cpu_maxfreq $BOEFFLA_CONFIG`" ]; then
        echo "cpu_maxfreq=default (default/200...1600)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting $BOEFFLA_CONFIG`" ]; then
	echo "cpu_undervolting=off (off/25/50/75/100/light/medium/heavy)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# GPU Frequency and under/overvolting

if ! /sbin/busybox [ "`/sbin/busybox grep gpu_frequency $BOEFFLA_CONFIG`" ]; then
	echo "gpu_frequency=default (default/54/160/160and266/266and350/54to266/108to350/266to533/350to600/440to700)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting $BOEFFLA_CONFIG`" ]; then
	echo "gpu_undervolting=off (off/25/50/75/100/light/medium/heavy/o25/o50/o75/o100)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# LED settings, touch boost and sharpness fix

if ! /sbin/busybox [ "`/sbin/busybox grep led_fading $BOEFFLA_CONFIG`" ]; then
	echo "led_fading=off (blink/fade/blink-bright/fade-bright/blink-dark/fade-dark)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep led_speed $BOEFFLA_CONFIG`" ]; then
	echo "led_speed=default (default/2x/3x/4x/5x)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep touch_boost $BOEFFLA_CONFIG`" ]; then
	echo "touch_boost=on (on/off)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sharpness_fix $BOEFFLA_CONFIG`" ]; then
	echo "sharpness_fix=off (off/on)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Charging AC and USB

if ! /sbin/busybox [ "`/sbin/busybox grep charge_ac $BOEFFLA_CONFIG`" ]; then
	echo "charge_ac=1100 (100...1600)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep charge_usb $BOEFFLA_CONFIG`" ]; then
	echo "charge_usb=475 (0...1600)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Tweaks (system, ext4 and sdcard)

if ! /sbin/busybox [ "`/sbin/busybox grep systemtweaks $BOEFFLA_CONFIG`" ]; then
	echo "systemtweaks=off (off/on/smod)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep ext4tweaks $BOEFFLA_CONFIG`" ]; then
	echo "ext4tweaks=on (on/off)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sdcardtweaks_int $BOEFFLA_CONFIG`" ]; then
	echo "sdcardtweaks_int=on (on/off/128...4096)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sdcardtweaks_ext $BOEFFLA_CONFIG`" ]; then
	echo "sdcardtweaks_ext=on (on/off/128...4096)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Network support for CIFS and NFS

if ! /sbin/busybox [ "`/sbin/busybox grep network_cifs $BOEFFLA_CONFIG`" ]; then
        echo "network_cifs=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep network_nfs $BOEFFLA_CONFIG`" ]; then
        echo "network_nfs=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi


# Support for xbox controller

if ! /sbin/busybox [ "`/sbin/busybox grep xbox $BOEFFLA_CONFIG`" ]; then
        echo "xbox=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi


# exFat

if ! /sbin/busybox [ "`/sbin/busybox grep exfat $BOEFFLA_CONFIG`" ]; then
	echo "exfat=on (on/off)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Logging

if ! /sbin/busybox [ "`/sbin/busybox grep androidlogger $BOEFFLA_CONFIG`" ]; then
	echo "androidlogger=off (off/on)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep kernellogger $BOEFFLA_CONFIG`" ]; then
        echo "kernellogger=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi


# Auto root and configuration app (both options are only available via config file)

if ! /sbin/busybox [ "`/sbin/busybox grep autoroot $BOEFFLA_CONFIG`" ]; then
	echo "autoroot=off (off/on)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep boeffla_app $BOEFFLA_CONFIG`" ]; then
	echo "boeffla_app=on (on/off)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Boeffla-Sound

if ! /sbin/busybox [ "`/sbin/busybox grep sound_headphone_vol $BOEFFLA_CONFIG`" ]; then
        echo "sound_headphone_vol=default (default/20...63)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq=off (off/bass-extreme/bass-treble/treble/classic/pleasant/eargasm/custom)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_0100Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_0100Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_0300Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_0300Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_0875Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_0875Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_2400Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_2400Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_6900Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_6900Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_satprevent $BOEFFLA_CONFIG`" ]; then
        echo "sound_satprevent=on (on/off)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_speaker_vol $BOEFFLA_CONFIG`" ]; then
        echo "sound_speaker_vol=default (default/57...63)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_speaker_tuning $BOEFFLA_CONFIG`" ]; then
        echo "sound_speaker_tuning=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_privacy_mode $BOEFFLA_CONFIG`" ]; then
        echo "sound_privacy_mode=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi


if ! /sbin/busybox [ "`/sbin/busybox grep sound_dac_direct $BOEFFLA_CONFIG`" ]; then
        echo "sound_dac_direct=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_dac_oversampling $BOEFFLA_CONFIG`" ]; then
        echo "sound_dac_oversampling=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_fll_tuning $BOEFFLA_CONFIG`" ]; then
        echo "sound_fll_tuning=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_stereo_expansion $BOEFFLA_CONFIG`" ]; then
        echo "sound_stereo_expansion=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_mono_downmix $BOEFFLA_CONFIG`" ]; then
        echo "sound_mono_downmix=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_miclevel_general $BOEFFLA_CONFIG`" ]; then
        echo "sound_miclevel_general=default (default/0..31)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_miclevel_call $BOEFFLA_CONFIG`" ]; then
        echo "sound_miclevel_call=default (default/0..31)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi



# Clean up of changed options (where parameters were added)
# example: /sbin/busybox sed "s/(default\/lulz)/(default\/lulz\/zzmoove)/g" $BOEFFLA_CONFIG -i


# Finally remove old options that are not required anymore
# example: /sbin/busybox sed "/Config file version/d" $BOEFFLA_CONFIG -i
