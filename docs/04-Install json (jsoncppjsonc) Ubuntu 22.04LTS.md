@[TOC]

# 1. jsoncpp

```bash
sudo apt-get install libjsoncpp-dev
```

## 1.1 location
```
# 检查是否安装成功
ls /usr/include/jsoncpp/json/

```

## 1.2. header

```cpp
#include <jsoncpp/json/json.h>
```

## 1.3. Compile

```bash
g++ -ljsoncpp
```

# 2. jsonc

```bash
sudo aptitude install libjson-c-dev
---------------------------------------------------
The following NEW packages will be installed:
  libjson-c-dev{b}
0 packages upgraded, 1 newly installed, 0 to remove and 0 not upgraded.
Need to get 60.4 kB of archives. After unpacking 291 kB will be used.
The following packages have unmet dependencies:
 libjson-c-dev : Depends: libjson-c5 (= 0.15-2build4) but 0.15-3~ubuntu1.22.04.2 is installed
The following actions will resolve these dependencies:

     Keep the following packages at their current version:
1)     libjson-c-dev [Not Installed]


---------------------------------------------------
Accept this solution? [Y/n/q/?] n
---------------------------------------------------
The following actions will resolve these dependencies:

     Downgrade the following packages:
1)     libjson-c5 [0.15-3~ubuntu1.22.04.2 (now) -> 0.15-2build4 (jammy)]


---------------------------------------------------
Accept this solution? [Y/n/q/?] y
---------------------------------------------------
The following packages will be DOWNGRADED:
  libjson-c5
The following NEW packages will be installed:
  libjson-c-dev
0 packages upgraded, 1 newly installed, 1 downgraded, 0 to remove and 0 not upgraded.
Need to get 93.7 kB of archives. After unpacking 291 kB will be used.

---------------------------------------------------
Do you want to continue? [Y/n/?] y
---------------------------------------------------
Get: 1 http://archive.ubuntu.com/ubuntu jammy/main amd64 libjson-c5 amd64 0.15-2build4 [33.3 kB]
Setting up libjson-c-dev (0.15-2build4) ...
Processing triggers for libc-bin (2.35-0ubuntu3.7) ...
```

## 2.2 location

```bash
ls /usr/include/json-c/
```

## 2.2 header

```c
#include <json-c/json.h>
```

## 2.2 Compile

```bash
g++ -ljson-c
```