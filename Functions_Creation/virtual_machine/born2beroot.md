
                                            ~ Born2BeRoot ~


/*
                Project requirments : 

                        1) push : signature.txt 
                        2) Machine host name  {yrziqi42}
                        3) you will change the host name to the evaluator name and restart
                        1) how to vew the partitions os the VM
                        2) No graphikal interface
                        3) AppArmor for Debian must be running at startup too
                        4) Mandatory part : You must create at least 2 encrypted partitions using LVM
                        5) it must not be possible to connect using SSH as root
                        6) you will add a new ssh and connect new user in the coreection.
                        7) only port 4242
                        8) Actvait the FireWall UFW
                        9) sudo is active ?  sudo -V
                        10) add user to sudo grop
                        11) show the sudo subject requirments
                        12) /var/log/sudo/ exist ? is the file in it contain the hestory of sudo command ? do a command usig sudo and check if it is there (updating or not ?) ?
                        13) connect the real machine wiht the vrtual machine ssh
                        14) how to see all the port it should find only 4242 (22);
                        15) creat new user and connect it to th ssh , make sure that you can not use ssh with the root 
                        16) what is cron ? scrept every 1 min ? spot showing the scrept if we restart the VM he should not showen ?
*/

What is a server ?

        A server is a computer program that provide a service.

What is the first programme that exist in the computer befor the VMM (hypervisor) & OS (Operation System) ?

    * The first thing that exists in the computer is the BIOS
    * What is BIOS ? :
            It is a small program stored on the motherboard that:

                        * starts when you power on the computer

                        * checks the hardware

                        * lets you choose what to boot

                        * loads the installer for an OS or a hypervisor (VMM)

What is an Operation System ? 

   * Operation System : He is the manager of the computer that manage everythig in the computer --->
        1) the hardware  2) the files  3) the permissions  5) Runing the progrommes  4) the connection between everything . 


What is Hypervisor (Virtual Machine Monitor)?

    * Hypervisor (VMM) : It is the “boss” that controls all virtual machines hardware.
           * Types of Hypervisore :

                    there is two types of Hypervisor , the type 1 Hypervisor and the type 2 Hypervisor. The difference between them is the type 1 is installed in the hardware then the OS 
                    is in top of it. but the type 2 is the OS is installed in the hardware directly so he takes all the resources.




Why servers use a hypervisor first ?

        * Servers are very powerful machines ,If they install only one OS directly, then the OS will uses all the CPU , RAM , disk  ➡ Waste of resources for only one system (OS).



What is a Virtual Machine (VM)?

        * Virtual Machine (VM) = an operating system that runs inside a hypervisor (VMM).



What is NOT a VM?

        * If the OS is installed directly by BIOS onto the hardware.


How the Virtual machine work ? 

        the hypervisor creat a virtual hardware for the new OS the kernel of the OS think that the virtual hardware is real , but actualy the hardware gaving by the hypervisor is just virtual
        he take the size of the (RAM , CPU , STORG)  that you gave to hem and he gave it to the VM (new OS).


What is the Kernel ?

        The kernel is a program that is installed as part of the operating system.
        It is responsible for managing all hardware resources, handling system calls, and enforcing permissions.
        In other words, the kernel acts as the bridge between software applications and the computer's hardware. 

How to add a User : 

        sodu adduser (Name)

How to See all the Users : 

        cat /etc/passwd

change passwd : 

        sudo passwd (user Name)

What Sudo is ? 

        it stand for "soper user do" , Sudo is a command-line utility on Unix-like operating systems that allows a user to run programs with the security privileges of another user, 
        typically the superuser (root) .
        Other user ex : sudo -u www-data ls /var/www


        * sudoers file : is the one how desice ho will use the sudo key work, best practice to access to sudoers file is using : ( sudo visudo ).
        * how to access the root :   (  su -  User Name  )this command seach the between the uses and by default if you did not add the use Name it sweach you to the root.
        * see all the Users : cat /etc/passwd
        * add user  : sudo adduser (or useradd but whith no passwd or home dir) + Name of the user
        * delete user: sudo userdel + User Name
        * add group  : sudo groupadd + group Name.      
        * to see all the groups : cat /etc/group
        * add a user to a grop : sudo usermod -aG   if just -G will delete all the users and let just the new one so -aG is appent this use to the grop wiht the old users.
        * delete user from grop: sudo gpasswd -d User Name
        * delet grop : sudo groupdel GroupName
        * User number id : id -u

What is root ?

        * Root is : In Linux, "root" refers to the superuser account, which has unrestricted access to all commands, files, and system resources on a Unix-like operating system
        has a user ID (UID) of 0 or (id -u)
        * How he work : you have the permition to everythig.

What is Debian ?

        * to know the os in the pc : cat /etc/os-release
        1) more users if you face a problem you will fid the solution 2) Orejinla is build in Debian not 3) not complkated.  4) larg repo for packeges .

What is Rocky ? 

        1) made to use in companains 2) Orejenal build in read hat  3) complcated and not for the norml usg  4) not like the larg packeges of Debian .

What is the difference between Debian & Rocky ?

        One easy the other complcated  ,   big packeges   the other smal packeges  ,   big comunity   .

What is a package  ?

        A package = a compressed file that contain : 1) the program it self  2) its librarys 3) mata data .

What is APT ?

        APT = the tool that talks to the online “repository” where software is stored.

What is Aptitud ?

        Advace + graphikal interface + not build in.

What is AppArmor ?

       AppArmor is a security system in Linux that restricts what programs are allowed to do. If a program tries to do something outside its profile, AppArmor blocks it.
       AppArmor = security system that restricts what programs can do.
       * to check the AppArmor status :  sudo aa-status

AppArmor vs SELinux (Rocky Linux uses SELinux) ? 

        1) Easy , Hard    2) AppArmor Default in Debian  ,  SELinux not Default in Rocky 3) Good for beginners , Not Good for beginners.

What is SSH ? 

        * ssh statu ? systemctl status ssh
        * Secourd shell : It is a network protocol that lets you connect securely to another machine.
        * The two dvices need to be in the same port.
        * ssh responseble just about the commands , default is port 22.
        *“Does this username exist, and can they prove their identity?”  You must know the device's IP, the SSH port, AND you must be a valid user on that device, AND you must have permission 
        (password or a key).
        * to access by the key you need in the device you want to go in to have your public key in her : ~/.ssh/authorized_keys
        * So who checks the SSH user, password, and keys? 👉 SSH itself not the UFW .

Shell ?

        A shell is a translator between: The commands you write and the system instructions.

Protocol ?

        A protocol = a set of rules that computers follow to communicate.

Port ?

        Port = a virtual door for network traffic.

What is UFW ?

        Uncomplcated FireWall ) ) ) IUFW controls which ports are open or closed. ( ( ( evne if the user exist and he have valid key but if the UFW deyn the port the user will not connect to the port.
        * to see status : sudo ufw status
        * allow a port  : sudo ufw allow 22
        * deny  a port  : sudo ufw deny 23

How to change the SSH port from 22 → 4242 ?

        sudo vim /etc/ssh/sshd_config.


What is LVM ?

        Logicl Volum Manager is not like the standerd partioining , it is better it does not lemet you in the size of eache unit storedg.
        LVM (Logical Volume Manager) is a storage management system in Linux that provides flexible and advanced control over disk space. 
                        1) PV : Physical Volum , is the real desc hardware.
                        2) VG : Volum Grop , it is the all PV (Physical Volums) considered as one storedg unit.
                        3) LV : Logicl Volum , is the partioin created from the VG (Volum Grop)

