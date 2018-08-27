#!/system/bin/sh

if ( cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq | grep -qE '(2158000)' );then
    setprop ro.power_profile.override power_profile_prime
fi

