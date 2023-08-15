# Zephyr的学习代码
## 环境
linux： zephyr

windows： vscode + remote 
## 编译
```shell
mkdir 00_helloworld/build && cd 00_hello_world/build
cmake -GNinja ..
ninja
```
## 烧录

```shell
ninja flash
```
直接烧录没问题，但是代码中使用```k_msleep()```时候会出现无法连接的情况，因此有以下代替方案

方法2
```shell
#窗口1
openocd -f openocd -f openocd.cfg=
#窗口2
telnet localhost 4444
program /home/hyc/zephyrproject/hyc/build/zephyr/zephyr.elf reset
```
