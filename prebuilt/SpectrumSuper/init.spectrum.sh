#!/system/bin/sh
# SPECTRUM KERNEL MANAGER
# Profile initialization script by ibilux

SpectrumProfile=`getprop persist.spectrum.profile`

# If there is not a persist value, we need to set one
if [ -z "$SpectrumProfile" ]; then
    setprop persist.spectrum.profile 3
else
    # Apply profile
    setprop persist.spectrum.profile $SpectrumProfile
fi
