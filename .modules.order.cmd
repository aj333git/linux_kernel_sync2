cmd_/home/oem/linux_kernel_sync2/modules.order := {   echo /home/oem/linux_kernel_sync2/critical_section.ko; :; } | awk '!x[$$0]++' - > /home/oem/linux_kernel_sync2/modules.order
