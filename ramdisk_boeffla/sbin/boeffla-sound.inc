# configure boeffla-sound

# initialisation
EQ_MODE=1

# check for option to disable equalizer saturation prevention
if /sbin/busybox [ "`/sbin/busybox grep sound_satprevent=off $BOEFFLA_CONFIG`" ]; then
	EQ_MODE=2

	echo $(date) Equalizer saturation prevention disabled >> $BOEFFLA_LOGFILE
fi


# headphone levels

# Initialize variable and read setting
LEVEL=""
LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_headphone_vol=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

# Only apply value if valid and not default
if [ ! "$LEVEL" = "default" ] && [ "${LEVEL:-0}" -ge 20 ] && [ "${LEVEL:-0}" -le 63 ] ; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo "$LEVEL $LEVEL" > /sys/class/misc/boeffla_sound/headphone_volume

	echo $(date) Headphone volume set to $LEVEL >> $BOEFFLA_LOGFILE
fi


# speaker levels

# Initialize variable and read setting
LEVEL=""
LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_speaker_vol=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

# Only apply value if valid and not default
if [ ! "$LEVEL" = "default" ] && [ "${LEVEL:-0}" -ge 57 ] && [ "${LEVEL:-0}" -le 63 ] ; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo "$LEVEL $LEVEL" > /sys/class/misc/boeffla_sound/speaker_volume

	echo $(date) Speaker volume set to $LEVEL >> $BOEFFLA_LOGFILE
fi


# Speaker tuning

if /sbin/busybox [ "`/sbin/busybox grep sound_speaker_tuning=on $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo 1 > /sys/class/misc/boeffla_sound/speaker_tuning

	echo $(date) Speaker tuning enabled >> $BOEFFLA_LOGFILE
fi


# equalizer presets

if /sbin/busybox [ "`/sbin/busybox grep sound_eq=bass-extreme $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo $EQ_MODE > /sys/class/misc/boeffla_sound/eq
	echo "12 8 3 -1 1" > /sys/class/misc/boeffla_sound/eq_gains
	echo "1 4027 1031 0 276" > /sys/class/misc/boeffla_sound/eq_bands
	echo "2 8076 61555 456 456" > /sys/class/misc/boeffla_sound/eq_bands
	echo "3 7256 62323 2644 1368" > /sys/class/misc/boeffla_sound/eq_bands
	echo "4 5774 63529 1965 4355" > /sys/class/misc/boeffla_sound/eq_bands
	echo "5 1380 1369 0 16384" > /sys/class/misc/boeffla_sound/eq_bands

	echo $(date) Equalizer preset bass-extreme applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep sound_eq=bass-treble $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo $EQ_MODE > /sys/class/misc/boeffla_sound/eq
	echo "10 7 0 2 5" > /sys/class/misc/boeffla_sound/eq_gains
	echo "1 4027 1031 0 276" > /sys/class/misc/boeffla_sound/eq_bands
	echo "2 8076 61555 456 456" > /sys/class/misc/boeffla_sound/eq_bands
	echo "3 7256 62323 2644 1368" > /sys/class/misc/boeffla_sound/eq_bands
	echo "4 5774 63529 1965 4355" > /sys/class/misc/boeffla_sound/eq_bands
	echo "5 1380 1369 0 16384" > /sys/class/misc/boeffla_sound/eq_bands

	echo $(date) Equalizer preset bass-treble applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep sound_eq=treble $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo $EQ_MODE > /sys/class/misc/boeffla_sound/eq
	echo "-5 1 0 4 3" > /sys/class/misc/boeffla_sound/eq_gains
	echo "1 4027 1031 0 276" > /sys/class/misc/boeffla_sound/eq_bands
	echo "2 8076 61555 456 456" > /sys/class/misc/boeffla_sound/eq_bands
	echo "3 7256 62323 2644 1368" > /sys/class/misc/boeffla_sound/eq_bands
	echo "4 5774 63529 1965 4355" > /sys/class/misc/boeffla_sound/eq_bands
	echo "5 1380 1369 0 16384" > /sys/class/misc/boeffla_sound/eq_bands

	echo $(date) Equalizer preset treble applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep sound_eq=classic $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo $EQ_MODE > /sys/class/misc/boeffla_sound/eq
	echo "0 0 0 -3 -5" > /sys/class/misc/boeffla_sound/eq_gains
	echo "1 4027 1031 0 276" > /sys/class/misc/boeffla_sound/eq_bands
	echo "2 8076 61555 456 456" > /sys/class/misc/boeffla_sound/eq_bands
	echo "3 7256 62323 2644 1368" > /sys/class/misc/boeffla_sound/eq_bands
	echo "4 5774 63529 1965 4355" > /sys/class/misc/boeffla_sound/eq_bands
	echo "5 1380 1369 0 16384" > /sys/class/misc/boeffla_sound/eq_bands

	echo $(date) Equalizer preset classic applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep sound_eq=pleasant $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo $EQ_MODE > /sys/class/misc/boeffla_sound/eq
	echo "4 3 2 2 3" > /sys/class/misc/boeffla_sound/eq_gains
	echo "1 4027 1031 0 276" > /sys/class/misc/boeffla_sound/eq_bands
	echo "2 8076 61555 456 456" > /sys/class/misc/boeffla_sound/eq_bands
	echo "3 7256 62323 2644 1368" > /sys/class/misc/boeffla_sound/eq_bands
	echo "4 5774 63529 1965 4355" > /sys/class/misc/boeffla_sound/eq_bands
	echo "5 1380 1369 0 16384" > /sys/class/misc/boeffla_sound/eq_bands

	echo $(date) Equalizer preset pleasant applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep sound_eq=eargasm $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo $EQ_MODE > /sys/class/misc/boeffla_sound/eq
	echo "12 8 4 2 3" > /sys/class/misc/boeffla_sound/eq_gains
	echo "1 4027 1031 0 276" > /sys/class/misc/boeffla_sound/eq_bands
	echo "2 8076 61555 456 456" > /sys/class/misc/boeffla_sound/eq_bands
	echo "3 7256 62323 2644 1368" > /sys/class/misc/boeffla_sound/eq_bands
	echo "4 5774 63529 1965 4355" > /sys/class/misc/boeffla_sound/eq_bands
	echo "5 1380 1369 0 16384" > /sys/class/misc/boeffla_sound/eq_bands

	echo $(date) Equalizer preset eargasm applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep sound_eq=custom $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo $EQ_MODE > /sys/class/misc/boeffla_sound/eq
	echo "1 4027 1031 0 276" > /sys/class/misc/boeffla_sound/eq_bands
	echo "2 8076 61555 456 456" > /sys/class/misc/boeffla_sound/eq_bands
	echo "3 7256 62323 2644 1368" > /sys/class/misc/boeffla_sound/eq_bands
	echo "4 5774 63529 1965 4355" > /sys/class/misc/boeffla_sound/eq_bands
	echo "5 1380 1369 0 16384" > /sys/class/misc/boeffla_sound/eq_bands

	# Initialize variable and read setting for band 1
	LEVEL=""
	LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_eq_custom_0100Hz=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

	# Only apply value if valid and not default
	if [ "${LEVEL:-0}" -ge -12 ] && [ "${LEVEL:-0}" -le 12 ] ; then
		echo "1 $LEVEL" > /sys/class/misc/boeffla_sound/eq_gains_alt
		echo $(date) Equalizer preset custom band1 $LEVEL applied >> $BOEFFLA_LOGFILE
	fi

	# Initialize variable and read setting for band 2
	LEVEL=""
	LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_eq_custom_0300Hz=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

	# Only apply value if valid and not default
	if [ "${LEVEL:-0}" -ge -12 ] && [ "${LEVEL:-0}" -le 12 ] ; then
		echo "2 $LEVEL" > /sys/class/misc/boeffla_sound/eq_gains_alt
		echo $(date) Equalizer preset custom band2 $LEVEL applied >> $BOEFFLA_LOGFILE
	fi

	# Initialize variable and read setting for band 3
	LEVEL=""
	LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_eq_custom_0875Hz=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

	# Only apply value if valid and not default
	if [ "${LEVEL:-0}" -ge -12 ] && [ "${LEVEL:-0}" -le 12 ] ; then
		echo "3 $LEVEL" > /sys/class/misc/boeffla_sound/eq_gains_alt
		echo $(date) Equalizer preset custom band3 $LEVEL applied >> $BOEFFLA_LOGFILE
	fi

	# Initialize variable and read setting for band 4
	LEVEL=""
	LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_eq_custom_2400Hz=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

	# Only apply value if valid and not default
	if [ "${LEVEL:-0}" -ge -12 ] && [ "${LEVEL:-0}" -le 12 ] ; then
		echo "4 $LEVEL" > /sys/class/misc/boeffla_sound/eq_gains_alt
		echo $(date) Equalizer preset custom band4 $LEVEL applied >> $BOEFFLA_LOGFILE
	fi

	# Initialize variable and read setting for band 5
	LEVEL=""
	LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_eq_custom_6900Hz=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

	# Only apply value if valid and not default
	if [ "${LEVEL:-0}" -ge -12 ] && [ "${LEVEL:-0}" -le 12 ] ; then
		echo "5 $LEVEL" > /sys/class/misc/boeffla_sound/eq_gains_alt
		echo $(date) Equalizer preset custom band5 $LEVEL applied >> $BOEFFLA_LOGFILE
	fi
fi



# DAC direct

if /sbin/busybox [ "`/sbin/busybox grep sound_dac_direct=on $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo 1 > /sys/class/misc/boeffla_sound/dac_direct

	echo $(date) DAC direct enabled >> $BOEFFLA_LOGFILE
fi


# DAC 128 bit oversampling

if /sbin/busybox [ "`/sbin/busybox grep sound_dac_oversampling=on $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo 1 > /sys/class/misc/boeffla_sound/dac_oversampling

	echo $(date) DAC 128 bit oversampling enabled >> $BOEFFLA_LOGFILE
fi


# FLL tuning

if /sbin/busybox [ "`/sbin/busybox grep sound_fll_tuning=on $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo 1 > /sys/class/misc/boeffla_sound/fll_tuning

	echo $(date) FLL tuning enabled >> $BOEFFLA_LOGFILE
fi


# Stereo expansion

if /sbin/busybox [ "`/sbin/busybox grep sound_stereo_expansion=on $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo 16 > /sys/class/misc/boeffla_sound/stereo_expansion

	echo $(date) Stereo expansion enabled >> $BOEFFLA_LOGFILE
fi


# Mono downmix

if /sbin/busybox [ "`/sbin/busybox grep sound_mono_downmix=on $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo 1 > /sys/class/misc/boeffla_sound/mono_downmix

	echo $(date) Mono downmix enabled >> $BOEFFLA_LOGFILE
fi


# Privacy mode

if /sbin/busybox [ "`/sbin/busybox grep sound_privacy_mode=on $BOEFFLA_CONFIG`" ]; then
	echo 1 > /sys/class/misc/boeffla_sound/boeffla_sound
	echo 1 > /sys/class/misc/boeffla_sound/privacy_mode

	echo $(date) Privacy mode enabled >> $BOEFFLA_LOGFILE
fi


# Mic level

# Initialize variable and read general mic level setting
LEVEL=""
LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_miclevel_general=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

# Only apply value if valid
if [ "${LEVEL:-999}" -ge 0 ] && [ "${LEVEL:-999}" -le 31 ] ; then
        echo $LEVEL > /sys/class/misc/boeffla_sound/mic_level_general
        echo $(date) Microphone level general set to $LEVEL >> $BOEFFLA_LOGFILE
fi

# Initialize variable and read call mic level setting
LEVEL=""
LEVEL=$(/sbin/busybox sed -n -e 's/.*sound_miclevel_call=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

# Only apply value if valid
if [ "${LEVEL:-999}" -ge 0 ] && [ "${LEVEL:-999}" -le 31 ] ; then
        echo $LEVEL > /sys/class/misc/boeffla_sound/mic_level_call
        echo $(date) Microphone level call set to $LEVEL >> $BOEFFLA_LOGFILE
fi
