### Linux下的c爬虫程序
#### 1.项目简介
此项目基于Linux平台，分为主控模块、下载模块、解析模块和持久化模块，其中用到了Linux多路复用技术（Epoll模型），socket，多线程、正则表达式、守护进程、Linux动态库等开发技术。
#### 2.项目安装
```
git clone https://github.com/starbt/linux_spider.git
cd linux_spider
make 
sudo make install
```
#### 3.项目运行
```
./spider [-d] (-d表示在后台运行)
```
