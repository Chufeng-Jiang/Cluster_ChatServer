@[TOC]
# 1. Update Sourceslist：

```cpp
deb http://archive.ubuntu.com/ubuntu jammy multiverse restricted universe main
deb-src http://archive.ubuntu.com/ubuntu jammy multiverse restricted universe main #Added by software-properties


deb-src http://mirrors.aliyun.com/ubuntu-ports/ jammy main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu-ports/ jammy-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ jammy-security main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu-ports/ jammy-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ jammy-updates main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu-ports/ jammy-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ jammy-proposed main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu-ports/ jammy-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ jammy-backports main restricted universe multiverse
~                                                                                                          
```

# 2. Commands - Simplify
```bash
sudo apt install aptitude

sudo aptitude install build-essential
 -- input: n --> y

sudo apt install build-essential
```

# 3. Commands - Detailed
## 3.1 Install aptitude
```bash
sudo apt install aptitude
---------------------------

sudo apt install aptitude
----------------------------
Reading package lists... Done
  apt-xapian-index aptitude-doc-en | aptitude-doc debtags tasksel libcwidget-dev debian-keyring git bzr 
  ...........
Processing triggers for libc-bin (2.35-0ubuntu3.7) ...

```
## 3.2 Install build-essential
```bash
sudo aptitude install build-essential
------------------------------
The following actions will resolve these dependencies:
     Keep the following packages at their current version:
1)     build-essential [Not Installed]

-------------------------------------------
Accept this solution? [Y/n/q/?] n <-Input n
-------------------------------------------
The following actions will resolve these dependencies:

     Install the following packages:
1)     g++ [4:11.2.0-1ubuntu1 (jammy)]
2)     g++-11 [11.2.0-19ubuntu1 (jammy)]
3)     libstdc++-11-dev [11.2.0-19ubuntu1 (jammy)]

     Downgrade the following packages:
4)     cpp-11 [11.4.0-1ubuntu1~22.04 (now) -> 11.2.0-19ubuntu1 (jammy)]
5)     gcc-11 [11.4.0-1ubuntu1~22.04 (now) -> 11.2.0-19ubuntu1 (jammy)]
6)     gcc-11-base [11.4.0-1ubuntu1~22.04 (now) -> 11.2.0-19ubuntu1 (jammy)]
7)     libasan6 [11.4.0-1ubuntu1~22.04 (now) -> 11.2.0-19ubuntu1 (jammy)]
8)     libgcc-11-dev [11.4.0-1ubuntu1~22.04 (now) -> 11.2.0-19ubuntu1 (jammy)]
9)     libtsan0 [11.4.0-1ubuntu1~22.04 (now) -> 11.2.0-19ubuntu1 (jammy)]


-------------------------------------------
Accept this solution? [Y/n/q/?] y <-Input Y
-------------------------------------------
The following packages will be DOWNGRADED:
  cpp-11 gcc-11 gcc-11-base libasan6 libgcc-11-dev libtsan0
The following NEW packages will be installed:
  build-essential g++{a} g++-11{a} libstdc++-11-dev{a}
0 packages upgraded, 4 newly installed, 6 downgraded, 0 to remove and 0 not upgraded.
Need to get 50.6 MB of archives. After unpacking 48.4 MB will be used.
Do you want to continue? [Y/n/?] y
Get: 1 http://archive.ubuntu.com/ubuntu jammy/main amd64 gcc-11 amd64 11.2.0-19ubuntu1 [20.1 MB]
....
Setting up build-essential (12.9ubuntu3) ...
Processing triggers for man-db (2.10.2-1) ...
Processing triggers for libc-bin (2.35-0ubuntu3.7) ...

```
## 3.2 Verification

```bash
sudo apt install build-essential
-------------------------------------------------
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
build-essential is already the newest version (12.9ubuntu3).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.

```


Thanks to：https://blog.csdn.net/weixin_50252424/article/details/128123065