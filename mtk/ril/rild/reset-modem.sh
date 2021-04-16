#!/system/bin/sh
# Reset modem and service
# WIP to fix RIL by @ibilux

setprop gsm.ril.init 0
setprop ril.mux.report.case 2
setprop ctl.start muxreport-daemon
setprop ril.muxreport 0
