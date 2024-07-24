@[TOC]
# 1. Simplified Command
```bash
sudo apt-get install libexpat1=2.4.7-1 zlib1g=1:1.2.11.dfsg-2ubuntu9
```


# 2. Detailed Command

## 2.1 apt-get install libexpat1=2.4.7-1 
```bash
sudo apt-get install libexpat1=2.4.7-1 
-----------------------------------------------
......
zlib1g=1:1.2.11.dfsg-2ubuntu9
ded, 0 to remove and 0 not upgraded.
Need to get 149 kB of archives.
After this operation, 1,024 B disk space will be freed.


-----------------------------------------------
Do you want to continue? [Y/n] Y
-----------------------------------------------
Get:1 http://archive.ubuntu.com/ubuntu jammy/main amd64 zlib1g amd64 1:1.2.11.dfsg-2ubuntu9 [58.2 kB]
Get:2 http://archive.ubuntu.com/ubuntu jammy/main amd64 libexpat1 amd64 2.4.7-1 [90.7 kB]
......
Fetched 149 kB in 1s (147 kB/s)
Processing triggers for libc-bin (2.35-0ubuntu3.7) ...

```

```bash
sudo apt-get install libexpat1-dev zlib1g-dev python3-lib2to3

---------------------------------------------
Reading package lists... Done
Building dependency tree... Done
......
After this operation, 1,571 kB of additional disk space will be used.

---------------------------------------------
Do you want to continue? [Y/n] Y
---------------------------------------------
Get:1 http://archive.ubuntu.com/ubuntu jammy/main amd64 libexpat1-dev amd64 2.4.7-1 [147 kB]
......
Setting up zlib1g-dev:amd64 (1:1.2.11.dfsg-2ubuntu9) ...
Processing triggers for man-db (2.10.2-1) ...

```

## 2.2 aptitude install python3-dev

```bash
sudo aptitude install python3-dev
------------------------------------------------
The following NEW packages will be installed:
  javascript-common{a} libjs-jquery{a} libjs-sphinxdoc{a} libjs-underscore{a} python3-dev{b}
......
     Keep the following packages at their current version:
1)     python3-dev [Not Installed]


------------------------------------------------
Accept this solution? [Y/n/q/?] n
------------------------------------------------
The following actions will resolve these dependencies:

      Install the following packages:
1)      libpython3-dev [3.10.4-0ubuntu2 (jammy)]
......
4)      python3.10-dev [3.10.4-3 (jammy)]

      Downgrade the following packages:
5)      libpython3-stdlib [3.10.6-1~22.04 (now) -> 3.10.4-0ubuntu2 (jammy)]
......
14)     python3.10-minimal [3.10.12-1~22.04.3 (now) -> 3.10.4-3 (jammy)]

------------------------------------------------
Accept this solution? [Y/n/q/?] y
------------------------------------------------
The following packages will be DOWNGRADED:
......
Need to get 13.5 MB of archives. After unpacking 23.4 MB will be used.

------------------------------------------------
Do you want to continue? [Y/n/?] y
------------------------------------------------
Get: 1 http://archive.ubuntu.com/ubuntu jammy/main amd64 libpython3.10 amd64 3.10.4-3 [1,951 kB]
Get: 2 http://archive.ubuntu.com/ubuntu jammy/main amd64 python3.10 amd64 3.10.4-3 
......
Processing triggers for man-db (2.10.2-1) ...
Processing triggers for mailcap (3.70+nmu1ubuntu1) ...

```