@[TOC]

# 1. Install

```bash
sudo apt update

systemctl status nginx
```

# 2. ufw

```bash
sudo ufw allow 'Nginx HTTP'
sudo ufw allow 'Nginx HTTPS'
```

# 3. location

```bash
whereis nginx
-------------------------------------------
nginx: 
/usr/sbin/nginx 
/usr/lib/nginx 
/etc/nginx 
/usr/share/nginx 
/usr/share/man/man8/nginx.8.gz
```

主配置文件：/etc/nginx/nginx.conf
站点配置文件目录：/etc/nginx/sites-available 和 /etc/nginx/sites-enabled
# 4. 
[https://blog.csdn.net/weixin_44798538/article/details/138499457](https://blog.csdn.net/weixin_44798538/article/details/138499457)