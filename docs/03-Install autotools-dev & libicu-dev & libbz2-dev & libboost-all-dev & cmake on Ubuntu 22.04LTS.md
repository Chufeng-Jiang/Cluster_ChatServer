@[TOC]

# 1. Simplified Commands

```bash
sudo apt-get install autotools-dev

sudo apt-get install libicu-dev

sudo apt-get install libbz2-dev

sudo aptitude install libboost-all-dev
n
Y

sudo apt-get install cmake

```
## 1.1 Using aptitude to install  libboost-all-dev
```bash
sudo aptitude install libboost-all-dev
----------------------------------------
The following NEW packages will be installed:
  cpp-10{a} cpp-9{a} gcc-10{a} gcc-10-base{a} gcc-9{a} gcc-9-base{a} ibverbs-providers{a} libasan5{a} libboost-all-dev{b} libboost-atomic-dev{a} libboost-atomic1.74-dev{a}
  libboost-atomic1.74.0{a} libboost-chrono-dev{a} libboost-chrono1.74-dev{a} libboost-
0 packages upgraded, 111 newly installed, 0 to remove and 0 not upgraded.
Need to get 87.1 MB of archives. After unpacking 500 MB will be used.
The following packages have unmet dependencies:
 libboost-all-dev : Depends: libboost-mpi-dev but it is not installable
                    Depends: libboost-mpi-python-dev but it is not installable
The following actions will resolve these dependencies:

     Keep the following packages at their current version:
1)     libboost-all-dev [Not Installed]


----------------------------------------
Accept this solution? [Y/n/q/?] n
----------------------------------------
The following actions will resolve these dependencies:

      Install the following packages:
1)      autoconf [2.71-2 (jammy)]
2)      automake [1:1.16.5-1.3 (jammy)]
3)      gcc-12-base:i386 [12-20220319-1ubuntu1 (jammy)]
33)     mpi-default-dev [1.14 (jammy)]
34)     openmpi-bin [4.1.2-2ubuntu1 (jammy)]
35)     openmpi-common [4.1.2-2ubuntu1 (jammy)]

      Downgrade the following packages:
36)     gcc-12-base [12.3.0-1ubuntu1~22.04 (now) -> 12-20220319-1ubuntu1 (jammy)]
48)     libstdc++6 [12.3.0-1ubuntu1~22.04 (now) -> 12-20220319-1ubuntu1 (jammy)]
49)     libubsan1 [12.3.0-1ubuntu1~22.04 (now) -> 12-20220319-1ubuntu1 (jammy)]

      Leave the following dependencies unresolved:
50)     libopenmpi-dev recommends libcoarrays-openmpi-dev
51)     libc6:i386 recommends libnss-nis:i386
52)     libc6:i386 recommends libnss-nisplus:i386


----------------------------------------
Accept this solution? [Y/n/q/?] Y
----------------------------------------
The following packages will be DOWNGRADED:
  gcc-12-base libatomic1 libc-dev-bin libc6 libc6-dbg libc6-dev libcc1-0 libgcc-s1 libgomp1 libitm1 liblsan0 libquadmath0 libstdc++6 libubsan1
The following NEW packages will be installed:
  autoconf{a} automake{a} cpp-10{a} cpp-9{a} gcc-10{a} gcc-10-base{a} gcc-12-base:i386{a} gcc-9{a} gcc-9-base{a} gfortran-11{a} ibverbs-providers{a} libasan5{a} libboost-all-dev
  libboost-atomic-dev{a} libboost-atomic1.74-dev{a} libboost-atomic1.74.0{a} libboost-
```