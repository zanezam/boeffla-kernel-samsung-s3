# change governor to pegasusq, lulzactiveq or zzmoove with its respective defaults

# lulzactiveq governor

if /sbin/busybox [ "`/sbin/busybox grep governor=lulz $BOEFFLA_CONFIG`" ]; then

	echo "lulzactiveq" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

	echo $(date) Governor set to lulzactiveq >> $BOEFFLA_LOGFILE

fi


# pegasusq  profiles

if /sbin/busybox [ "`/sbin/busybox grep governor=p1c $BOEFFLA_CONFIG`" ]; then

	# set governor to pegasusq
	echo "pegasusq" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# cpu2 (500000/200000/100/100)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_1_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_0
	echo "3000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_1_1
	echo "3000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_0

	# cpu3  (500000/200000/200/200)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_0
	echo "4000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_1
	echo "4000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_0

	# cpu4  (500000/200000/300/300)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_4_0
	echo "5000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_1
	echo "5000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_4_0

	# 20
	echo "20" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_down_rate

	# 10
	echo "10" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_up_rate

	# 85
	echo "85" > /sys/devices/system/cpu/cpufreq/pegasusq/up_threshold

	# 37
	echo "37" > /sys/devices/system/cpu/cpufreq/pegasusq/freq_step

	echo $(date) Governor set to pegasusq - 1 core >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=p2c $BOEFFLA_CONFIG`" ]; then

	# set governor to pegasusq
	echo "pegasusq" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# cpu2 (500000/200000/100/100)
	echo "500000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_1_1
	echo "200000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_0
	echo "100" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_1_1
	echo "100" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_0

	# cpu3  (500000/200000/200/200)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_0
	echo "4000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_1
	echo "4000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_0

	# cpu4  (500000/200000/300/300)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_4_0
	echo "5000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_1
	echo "5000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_4_0

	# 20
	echo "20" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_down_rate

	# 10
	echo "10" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_up_rate

	# 85
	echo "85" > /sys/devices/system/cpu/cpufreq/pegasusq/up_threshold

	# 37
	echo "37" > /sys/devices/system/cpu/cpufreq/pegasusq/freq_step

	echo $(date) Governor set to pegasusq - 2 cores >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=psmod $BOEFFLA_CONFIG`" ]; then

	# set governor to pegasusq
	echo "pegasusq" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# cpu2 (500000/200000/100/100)
	echo "500000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_1_1
	echo "400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_0
	echo "100" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_1_1
	echo "100" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_0

	# cpu3  (500000/200000/200/200)
	echo "800000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_1
	echo "600000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_0
	echo "200" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_1
	echo "200" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_0

	# cpu4  (500000/200000/300/300)
	echo "800000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_1
	echo "600000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_4_0
	echo "300" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_1
	echo "300" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_4_0

	# 20
	echo "10" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_down_rate

	# 10
	echo "10" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_up_rate

	# 85
	echo "85" > /sys/devices/system/cpu/cpufreq/pegasusq/up_threshold

	# 37
	echo "37" > /sys/devices/system/cpu/cpufreq/pegasusq/freq_step

	echo $(date) Governor set to pegasusq - speedmod tweaks >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=pbatt $BOEFFLA_CONFIG`" ]; then

	# set governor to pegasusq
	echo "pegasusq" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# cpu2 (500000/200000/100/100)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_1_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_0
	echo "500" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_1_1
	echo "500" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_0

	# cpu3  (500000/200000/200/200)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_0
	echo "550" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_1
	echo "550" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_0

	# cpu4  (500000/200000/300/300)
	echo "1400000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_1
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_4_0
	echo "600" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_1
	echo "600" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_4_0

	# 20
	echo "10" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_down_rate

	# 10
	echo "5" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_up_rate

	# 85
	echo "95" > /sys/devices/system/cpu/cpufreq/pegasusq/up_threshold

	# 37
	echo "25" > /sys/devices/system/cpu/cpufreq/pegasusq/freq_step

	echo $(date) Governor set to pegasusq - Boeffla battery-save >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=pmod $BOEFFLA_CONFIG`" ]; then

	# set governor to pegasusq
	echo "pegasusq" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# cpu2 (500000/200000/100/100)
	echo "800000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_1_1
	echo "700000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_0
	echo "100" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_1_1
	echo "100" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_0

	# cpu3  (500000/200000/200/200)
	echo "1100000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_2_1
	echo "1000000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_0
	echo "300" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_2_1
	echo "300" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_0

	# cpu4  (500000/200000/300/300)
	echo "1300000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_3_1
	echo "1200000" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_freq_4_0
	echo "400" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_3_1
	echo "400" > /sys/devices/system/cpu/cpufreq/pegasusq/hotplug_rq_4_0

	# 20
	echo "10" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_down_rate

	# 10
	echo "10" > /sys/devices/system/cpu/cpufreq/pegasusq/cpu_up_rate

	# 85
	echo "85" > /sys/devices/system/cpu/cpufreq/pegasusq/up_threshold

	# 37
	echo "37" > /sys/devices/system/cpu/cpufreq/pegasusq/freq_step

	echo $(date) Governor set to pegasusq - Boeffla moderate >> $BOEFFLA_LOGFILE

fi


# zzmoove governor and profiles

if /sbin/busybox [ "`/sbin/busybox grep governor=zzmoove $BOEFFLA_CONFIG`" ]; then

	echo "zzmoove" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

	echo $(date) Governor set to zzmoove >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=zbatt $BOEFFLA_CONFIG`" ]; then

	# set governor to zzmoove
	echo "zzmoove" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# zzmoove governor settings optimized for battery:
	echo "120000" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_rate
	echo "1" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_down_factor
	echo "95" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold
	echo "40" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold
	echo "0" >/sys/devices/system/cpu/cpufreq/zzmoove/ignore_nice_load
	echo "10" >/sys/devices/system/cpu/cpufreq/zzmoove/freq_step
	echo "75" >/sys/devices/system/cpu/cpufreq/zzmoove/smooth_up

	# hotplug up threshold per core ("smoother" hotplugging)
	echo "50" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug1
	echo "70" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug2
	echo "98" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug3

	# hotplug down threshold per core ("smoother" hotplugging)
	echo "35" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug1
	echo "45" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug2
	echo "65" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug3

	# sampling rate at suspend (screen off)
	echo "2" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_rate_sleep_multiplier

	# up/down threshold at suspend (screen off)
	echo "55" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_sleep
	echo "98" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_sleep

	# smooth up scaling only at 100% load at suspend (screen off)
	echo "100" >/sys/devices/system/cpu/cpufreq/zzmoove/smooth_up_sleep

	# use only one core at suspend (screen off) previously set settings will be restored at awake (screen on)
	echo "1" >/sys/devices/system/cpu/cpufreq/zzmoove/hotplug_sleep

	echo $(date) Governor set to zzmoove - battery >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=zopt $BOEFFLA_CONFIG`" ]; then

	# set governor to zzmoove
	echo "zzmoove" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# zzmoove governor settings optimized (between battery and performance)
	echo "45000" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_rate
	echo "1" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_down_factor
	echo "67" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold
	echo "52" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold
	echo "0" >/sys/devices/system/cpu/cpufreq/zzmoove/ignore_nice_load
	echo "5" >/sys/devices/system/cpu/cpufreq/zzmoove/freq_step
	echo "75" >/sys/devices/system/cpu/cpufreq/zzmoove/smooth_up

	# hotplug up threshold per core ("smoother" hotplugging)
	echo "68" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug1
	echo "78" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug2
	echo "88" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug3

	# hotplug down threshold per core ("smoother" hotplugging)
	echo "45" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug1
	echo "55" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug2
	echo "65" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug3

	# sampling rate at suspend (screen off)
	echo "2" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_rate_sleep_multiplier

	# up/down threshold at suspend (screen off)
	echo "55" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_sleep
	echo "98" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_sleep

	# smooth up scaling only at 100% load at suspend (screen off)
	echo "100" >/sys/devices/system/cpu/cpufreq/zzmoove/smooth_up_sleep

	# use only one core at suspend (screen off) previously set settings will be restored at awake (screen on)
	echo "1" >/sys/devices/system/cpu/cpufreq/zzmoove/hotplug_sleep

	echo $(date) Governor set to zzmoove - optimal >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=zperf $BOEFFLA_CONFIG`" ]; then

	# set governor to zzmoove
	echo "zzmoove" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
	/sbin/busybox sleep 2

	# zzmoove governor settings optimized for performance:
	echo "40000" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_rate
	echo "1" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_down_factor
	echo "60" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold
	echo "20" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold
	echo "0" >/sys/devices/system/cpu/cpufreq/zzmoove/ignore_nice_load
	echo "25" >/sys/devices/system/cpu/cpufreq/zzmoove/freq_step
	echo "70" >/sys/devices/system/cpu/cpufreq/zzmoove/smooth_up

	# hotplug up threshold per core ("smoother" hotplugging)
	echo "65" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug1
	echo "75" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug2
	echo "85" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_hotplug3

	# hotplug down threshold per core ("smoother" hotplugging)
	echo "25" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug1
	echo "35" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug2
	echo "45" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_hotplug3

	# sampling rate at suspend (screen off)
	echo "2" >/sys/devices/system/cpu/cpufreq/zzmoove/sampling_rate_sleep_multiplier

	# up/down threshold at suspend (screen off)
	echo "55" >/sys/devices/system/cpu/cpufreq/zzmoove/down_threshold_sleep
	echo "98" >/sys/devices/system/cpu/cpufreq/zzmoove/up_threshold_sleep

	# smooth up scaling only at 100% load at suspend (screen off)
	echo "100" >/sys/devices/system/cpu/cpufreq/zzmoove/smooth_up_sleep

	# use only one core at suspend (screen off) previously set settings will be restored at awake (screen on)
	echo "1" >/sys/devices/system/cpu/cpufreq/zzmoove/hotplug_sleep

	echo $(date) Governor set to zzmoove - performance >> $BOEFFLA_LOGFILE

fi
