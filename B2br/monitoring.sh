#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:10:20 by wdegraf           #+#    #+#              #
#    Updated: 2024/01/10 12:32:22 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


a1=$(uname -a)
# shows the number of physical CPU cores.. 
# grep "physical id" /proc/cpuinfo  shows the physical Cores
# wc -l counts the number of lines 
a2=$(grep "physical id" /proc/cpuinfo | wc -l)
# shows the number of virtual CPU cores..
# grep "processor" /proc/cpuinfo shows the Virtual processors
a3=$(grep "processor" /proc/cpuinfo | wc -l)
# free shows the ram Parameter --help for more information --mega for MB
# awk is a programming language for text processing and data analysis
# awk '$1 == "Mem:"{print $2}' shows the used RAM
a4=$(free --mega | awk '$1 == "Mem:"{printf ("%dMb\n", $3)}')
b4=$(free --mega | awk '$1 == "Mem:" {printf ("%dMb\n", $2)}')
# {printf("%2.f%%\n", $3/$2*100) in awk shows the used RAM in % the 2.f is for 2 digits after the comma
# it uses .f becourse it is a float number so it is more accurate than .d
a5=$(free --mega | awk '$1 == "Mem:" {printf("%.f%%\n", $3/$2*100)}')
# df -h shows the disk filesystem space in human readable format we use -m for MB
# grep "/dev" (dev represents physical and virtual storage devices)
# grep -v "/boot" -v excludes the boot partition mountet in boot
# awk {memory_result += $3} Sums up all values in the third column of each line which will be space of each filesystem 
#END {printf ("%0.fGb\n", memory_result/1024)} is executed after the last line of the input is read and prints the sum of all values in MB
a6=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_result += $3} END {printf ("%0.fMb\n", memory_result)}')
b6=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_result += $2} END {printf ("%0.fGb\n", memory_result/1024)}')
# awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100} calculates the used disk space in %
a7=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("%d%%\n"), use/total*100}')
# vmstat gives information about processes, memory, paging, block IO, traps, disks and cpu activity idel is the used CPU time in %
# <(...): This is a process substitution. It treats the output of the command inside as if it were a file. This allows awk to read the output directly
# awk '{print 100 - $15}' reads the output of the command and prints the CPU idle time
# vmstat 1 4 | tail -1 runs vmstat and takes the last line of the output 
# xargs printf "%.1f%%\n" takes the output of the command and prints it with one digit after the comma and a % sign
#### a8=$(awk '{print 100 - $15}' <(vmstat 1 4 | tail -1) | xargs printf "%.1f%%\n")
# i changed the command to this because the other one was not working with sh .. even if it is not neaded becouse it should be bash anyway
a8=$(vmstat 1 4 | tail -1 | awk '{print 100 - $15}' | xargs printf "%.1f%%\n")
# who -b shows the last system boot time and date
# awk '$1 == "system" {print $3 " " $4}' reads the output of the command and prints only the date and time
a9=$(who -b | awk '$1 == "system" {print $3 " " $4}')
# lsblk lists information about all available or the specified block devices *lesb lik*
# grep "lvm" shows the lvm devices
# wc -l counts the number of lines
# if -gt 0 checks if the number of lines is greater than 0 
# then echo yes; else echo no; fi prints yes if the number of lines is greater than 0 else it prints no
# fi marks the end of the if else statement in shell structure
a10=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
# ss stands for socket statistics and shows information about the network connections -ta shows all TCP connections
# grep ESTAB shows only the established connections wc -l counts the number of lines
a11=$(ss -ta | grep ESTAB | wc -l)
# users shows the user names of users currently logged in to the current host wc -w counts the number of words
a12=$(users | wc -w)
# hostname -I shows the IP address of the current host
a13=$(hostname -I)
# ip link shows the link status of all network interfaces grep "link/ether" shows only the ethernet interfaces
# awk '{print $2}' prints the second column of the output which is the MAC address
a14=$(ip link | grep "link/ether" | awk '{print $2}')
# journalctl _Comm=sudo shows the sudo commands executed on the system
# grep COMMAND shows only the lines with the word COMMAND wc -l counts the number of lines
a15=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	#Architecture: $a1
	#CPU physical: $a2
	#CPU virtual: $a3
	#Memory Usage: $a4/$b4 ($a5 used)
	#Disk Usage: $a6/$b6 ($a7 used)
	#CPU load: $a8
	#Last boot: $a9
	#LVM use: $a10
	#Connexions TCP: $a11 ESTABLISHED
	#User log: $a12
	#Network: IP $a13 MAC ($a14)
	#Sudo: $a15 cmd"
	