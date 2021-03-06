# LINUX PROCESSES

*Syscalls* - system calls.

Are just like a especial function call that occors in the kernel.

Processes are syscall aimed at process management, such as:

- fork;
- exec;
- wait;
- waitpid;
- exit;
- brk;
- getpid;
- getpgrp;
- setsid;
- ptrace; 


## **PROCESS**:

	A process is a piece of running code in the computer that is executing some
	task. Every process has a PROCESS ID (PID) and a PARENT PROCESS ID (PPID).
	The only process that it's not created by another process is the INIT PROCESS,
	wich bears the PID nº 1.



## **INIT, FORK/EXEC**:

Lets look at this init process, using the 'ps' command, passing the flag '-f', for
full formating, and the argument '1':

```shell
┌──(kali㉿kali)-[~]
└─$ ps -f 1
UID          PID    PPID  C STIME TTY      STAT   TIME CMD
root           1       0  0 17:33 ?        Ss     0:01 /sbin/init splash
```

*There is a number of inits systems, the most common one is systemd
(/lib/systemd/systemd)

But if the parent PPID is 0, then what started the process?

The awnser is that the LINUX KERNEL started it!

In OS we basically can broken up into two pieces: USER SPACES and KERNEL SPACE.
Therefore, when we boot our machine, the LINUX KERNEL does a lot of different things
but once it finishes everything it does in KERNEL SPACE (RING 0) it only does one
thing in USER SPACE, wich is to call this process (/sbin/init)

After that, the INIT PROCESS is responsible for starting all the other processes that
the computer needs to run in USER SPACE.

For instance, what will happen if we run the 'ls' command?

```shell
┌──(kali㉿kali)-[~]
└─$ ls -l  
total 32
drwxr-xr-x 2 kali kali 4096 Nov 17 09:14 Desktop
drwxr-xr-x 2 kali kali 4096 Nov 17 09:14 Documents
drwxr-xr-x 2 kali kali 4096 Dec 18 17:58 Downloads
drwxr-xr-x 2 kali kali 4096 Nov 17 09:14 Music
drwxr-xr-x 2 kali kali 4096 Nov 17 09:14 Pictures
drwxr-xr-x 2 kali kali 4096 Nov 17 09:14 Public
drwxr-xr-x 2 kali kali 4096 Nov 17 09:14 Templates
drwxr-xr-x 2 kali kali 4096 Nov 17 09:14 Videos
```

	The current process wich is, in this case, a ZSH SHELL, it FORKED
	into 2 processes, and the COPY of itself was replaced by LS. So know
	what we have running is ZSH SHELL(PARENT) and LS(CHILD)	


This is what its called FORK/EXEC. It first forks, duplicating the process, and
than exec replaces that child process if another process.

So, what will happen if we run 'exec ls -l'?

```shell
┌──(kali㉿kali)-[~]
└─$ exec ls -l
```
	Since the current process /usr/bin/zsh will be replaced by 'ls', and
	than, when it exits it, the terminal will desapear. 

1. In the first case, zsh executes 'ls' and then, once ls is done, it goes back to zsh.
2. Whereas, in the second case, using exec, the process of 'ls' replaces 'zsh' and then
desapear.
	
	The first case ($ ls -l) has the same replace action by 'ls' process. The diffe-
	rence lies in the FORK. Since fork() created a duplicate of the process with a 
	different PID and 'ls' replaced it, and ls is done, /usr/bin/zsh is still running,
	since it was the parent process (EXEC is running on the FORK process).


## **PS, JOBS, FG and BG**:

If we want to manage process, we use the command 'ps'. 'ps' man says:
"ps - report a snapshot of the current processes."

A simple 'ps', without args nor flags, will show the PID, TTY, TIME and CMD:

```shell
┌──(kali㉿kali)-[~]
└─$ ps   
    PID TTY          TIME CMD
   1325 pts/1    00:00:00 zsh
   1341 pts/1    00:00:00 ps
```

Lets try another command, 'sleep'.

When we type 'sleep' followed by a integer representing the seconds, the process will
block and wait said seconds to bew finished.

```shell
┌──(kali㉿kali)-[~]
└─$ sleep 1                         
                                                                                            
┌──(kali㉿kali)-[~]
└─$ 
```

Hence, in the example above, when we ran 'sleep', it made a copy of the process 
'/usr/bin/zsh' with FORK and replaced it using EXEC wih 'sleep', resulting in a 
parent process '/usr/bin/zsh' and a child process 'sleep'.

And 'sleep', since it was executed by ZSH, inherited STDIN, STDOUT, STDERR.

Now, knowing this, we can execute 'sleep' passing '360' as an argument (or any large
number)

```shell
┌──(kali㉿kali)-[~]
└─$ sleep 360
```

Doing that, we can observe that the terminal is blocked. We can type any command and
it will appear on screen, but without any of its functionallity.

```shell
┌──(kali㉿kali)-[~]
└─$ sleep 360
ls -la
echo #SHELL
find .
```

All of this commands are being sent to the 'sleep' process, since it have inherited STDIN
and STDOUT, being the STANDARD INPUT the KEYBOARD and the STANDARD OUTPUT the SCREEN.

If we want to terminate the process, we type CTRL + C, wich sends a SIGN SYSCALL named 
SIGINT.

If we want to suspend the process, we execute the command CTRL + Z, and the process is stop-
ped and sent to the background, as the example bellow:

```shell
┌──(kali㉿kali)-[~]
└─$ sleep 360
^Z
zsh: suspended  sleep 360
                                                                                            
┌──(kali㉿kali)-[~]
└─$ jobs                                                                          148 ⨯ 1 ⚙
[1]  + suspended  sleep 360
                                                                                            
┌──(kali㉿kali)-[~]
└─$ ps -f                                                                               1 ⚙
UID          PID    PPID  C STIME TTY          TIME CMD
kali        2665    2662  2 16:24 pts/0    00:00:00 /usr/bin/zsh
kali        2683    2665  0 16:24 pts/0    00:00:00 sleep 360
kali        2693    2665  0 16:25 pts/0    00:00:00 ps -f
```

We can see that ZSH has to child process, 'sleep 360' and 'ps -f', both with the same
PPID of 2665. So, if we want to start the 'sleep 360' process back up, we can do two things:

1 - To start back in the FOREGROUND, since we only have one job, we can type the command
    'fg', without any argument:
```shell
┌──(kali㉿kali)-[~]
└─$ fg
sleep 360
```

    * The problem is that, with 'sleep' blocking our terminal, we can do anything until
      the 360 seconds has gone by. The solution is to start on the background!


2 - To starts on the BACKGROUND, we use the 'bg' command:

```shell
┌──(kali㉿kali)-[~]
└─$ bg
[1]+ sleep 360 &
```

If we want to start jobs DIRECTLY on the background we use the ampersand after the command.
Like this:

```shell
┌──(kali㉿kali)-[~]
└─$ sleep 360 &                                                                         1 ⚙
[2] 2745
                                                                                            
┌──(kali㉿kali)-[~]
└─$ sleep 360 &                                                                         2 ⚙
[3] 2751
```

The [2] and [3] are the job numbers, 2745 and 2751 are the PID: 

```shell
┌──(kali㉿kali)-[~]
└─$ jobs                                                                                3 ⚙
[1]  + suspended  sleep 360
[2]    running    sleep 360
[3]  - running    sleep 360
```

Now, if we want to bring JOB 3, for instance, to the FOREGROUND, we have to pass 
the arg '%3' to 'fg':

```shell
┌──(kali㉿kali)-[~]
└─$ fg %3                                                                               3 ⚙
[3]  - running    sleep 360
```
                                                                                            
## **THE KILL COMMAND**:

By now, we now a lot about how processes work in general, so lets understand hot
to kill them.

The way that 'kill' works is: 'kill <signal> <pid>'

There are different SIGNAL SYSCALLS in Linuxn and we can describe them passing the
-l flag to 'kill'.

```shell
┌──(root💀kali)-[/home/kali]
└─# kill -l
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
```

The ones we are interested in are: SIGTERM(15), SIGINT(2), SIGHUP(1) and SIGKILL(9).
If we don't pass the signal arg to 'kill', it assume SIGTERM(15), wich means it will
terminate the process. 

With the help of TMUX MULTIPLEXING, we can observe this processes in action.

```shell
┌──(kali㉿kali)-[~]                             |┌──(kali㉿kali)-[~]
└─$ jobs                                        │└─$ ps ax | grep sleep
[1]    running    sleep 1000                    │   5732 pts/3    SN     0:00 sleep 1000
[2]    running    sleep 1001                    │   5734 pts/3    SN     0:00 sleep 1001
[3]  - running    sleep 1002                    │   5736 pts/3    SN     0:00 sleep 1002
[4]  + running    sleep 1003                    │   5738 pts/3    SN     0:00 sleep 1003
                                                │   (...)
```
I created 4 processes using 'sleep', automatically sending them to the background with "&".
Now, we can see the 4 processes running in the first terminal, and, in the second terminal,
a simple 'ps' shows us each one of them with its respective PID.

Lets kill the third job (PID 5736), passing the SIGTERM(15)

```shell
┌──(kali㉿kali)-[~]                           │                                             └─$                                            │┌──(kali㉿kali)-[~]
[3]  - terminated  sleep 1002                  │└─$ kill -15 5736     
┌──(kali㉿kali)-[~]                           │                                             └─$ jobs                                       │┌──(kali㉿kali)-[~]
[1]    running    sleep 1000                   │└─$ 
[2]  - running    sleep 1001                   │
[4]  + running    sleep 1003                   │
```

We can see that a message has appear ([3] - terminated sleep 1002), wich means that the
shell still nows about the process, even if it's terminated (in BASH, it would show along
with the other jobs).

However, applications can processe SIGNALS SYSCALLS the way they want. For instance, an 
application can receive a SIGTERM or a SIGINT and choose to ignore it. That's why the 
SIGKILL(9) exists!

With SIGKILL(9), the KERNEL will simple take the process and remove it of the PROCESS
TABLE and the application cannot do anything.

1 - So, why don't we SIGKILL ('kill -9 <PID>') everything?

	Because SIGKILL is considered a DIRTY SHUTDOWN of an application. That means 
	that, when said application receives a SIGTERM, for instance, it have the oppor-
	tunity to process that and do whatever it has to do before being terminated, such
	as cleaning stuff, closing file handlers, etc. With SIGKILL(9) it's done! If the 
	application is in the middle of writing a file so sorry, maybe your file is now 
	corrupted...

2 - Ok, but why use it, then?
	
	We can see SIGKILL as a safe guard to threat misbehaving applications. As said
	above, other signals such as SIGTERM, SIGHUP or SIGINT, will give the chance to 
	the application to be terminated in a CLEAN MANNER. Therefore, we can use SIGKILL
	if aforesaid application is still refusing to terminate.

	KILLING AGRESSIVENESS:
	For instance, we can start with 'kill -15 PID', and then 'kill -2 PID', and then
	'kill -1 PID', and, if it's still not abbing to the kill signal, we can go to 
	'kill -9 PID' and that is the end of it!


But remeber, NOT ALL SIGNALS WILL TERMINATE THE PROCESS!

For instance, when we CTRL + Z a process what we1re doing is a SIGTSTP(20), and
when we run a 'fg' or a 'bg' to start it back up, we are running a SIGCONT(18).

SIGTSTOP:

```shell
┌──(kali㉿kali)-[~]
└─$ sleep 999 &                                                                             [1] 5812
                                                                                                              
┌──(kali㉿kali)-[~]
└─$ jobs                                                                                    [1]  + running    sleep 999
                                                                                                               
┌──(kali㉿kali)-[~]
└─$ kill -20 5812                                                                           [1]  + suspended  sleep 999                                                                                    

┌──(kali㉿kali)-[~]
└─$ jobs                                                                                    [1]  + suspended  sleep 999
```

SIGCONT:

```shell
┌──(kali㉿kali)-[~]
└─$ kill -18 5812                                                                                                                                                                      
┌──(kali㉿kali)-[~]
└─$ jobs                                                                                    [1]  + running    sleep 999
```