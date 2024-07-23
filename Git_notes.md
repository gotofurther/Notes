# ***Git***

*( 分布式版本控制系统 )*
***

### **Git**本地仓库操作

1. 全局配置

   ```git
   $git config --global user.name"用户名"
   $git config --global user.email"邮箱"
   ```

2. 创建仓库

    1. 通过命令创建空目录(如下)或在指定位置手动新建

   ```git
      touch repository
   ```
    2. Git仓库初始化(需在创建的仓库中打开Git Bash)

   ```git
      git init
   ```

*(必备的Linux指令)*

|  Linux指令   |           实现功能           |
|:----------:|:------------------------:|
|     cd     |           改变目录           |
|    cd..    |         回退到上一个目录         |
|    pwd     |        显示当前所在目录路径        |
|   ls(ll)   | 列出当前目录中的所有文件,ll列出的内容更为详细 |
|   touch    |         新建一个文件夹          |
|     rm     |          删除一个文件          |
|   mkdir    |       新建一个文件夹(目录)        |
|   rm -r    |         删除一个文件夹          |
| mv [a] [b] | 将a移动到b文件夹里，要求a,b需要在一个目录下 |
|   reset    |        重新初始化终端/清屏        |
|   clear    |            清屏            |
|  history   |          查看命令历史          |
|    help    |            帮助            |
|    exit    |            退出            |

**rm -rf / 切勿在Linux中尝试！删除电脑中全部文件！**

*(Git 常用指令)*

|       Git指令       |      实现功能       |
|:-----------------:|:---------------:|
|    git status     |     查看当前状态      |
|     git add A     |    把A添加到缓冲区     |
|     git add .     |  把当前目录文件添加到缓冲区  |
| git commit -m "B" | 提交至版本库，其中B是注释信息 |


### **Git**版本回退
1. 查看版本：确定需要回到的时间点
   ```git
   git log                   #查看版本
   git log--pretty=oneline   #查看版本，仅显示一行
   ```
2. 回退操作：
   ```git
   git reset--hard提交编号
   ```
   *(注意：回到过去之后，想要回到最新的版本，需要查看历史操作以获得最新的commit id)*
   ```git
   git reflog
   ```
### **Git**远程仓库操作
