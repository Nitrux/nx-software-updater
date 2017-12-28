#
# Regular cron jobs for the nx-software-updater package
#
0 4	* * *	root	[ -x /usr/bin/nx-software-updater_maintenance ] && /usr/bin/nx-software-updater_maintenance
