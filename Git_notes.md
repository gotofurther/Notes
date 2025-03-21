# ***Git***

*( 分布式版本控制系统 )*
<<<<<<< HEAD
***
=======
*Git 就像⼀本“时光机⽇记本每⼀段代码的改动，Git 都会帮你记录下来，像是在写⽇记;如果出现问题或者想查看之前的版本，Git 可以带你“穿越回过去”，找到任意时间点的代码状态*

------
>>>>>>> Notes

### **Git**本地仓库操作

1. 全局配置

   ```git
   $git config --global user.name"用户名"
   $git config --global user.email"邮箱"
   ```
<<<<<<< HEAD

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
=======
   >设置“署名”，每次提交都会标明是谁的贡献。
* SSH配置：安全认证和便捷连接 
   ```

   ```
   > SSH 允许在本地和远程仓库之间安全通信，并省去每次推送或拉取代码时输⼊密码的⿇烦。(SSH 就像“为你的钥匙加上指纹认证”，确保只有你能开⻔)

   
2. 创建仓库
   ```git
   git init
   ```
   > 在本地目录(某一级文件夹)下运行命令指示符，使用以上指令后在该目录下创建.git文件夹，使该目录创建为本地仓库

   >相当于新建一本“时光机日记本”，准备开始记录代码版本。
3. 添加文件到暂存区：
   ```git
   git add 文件名(也可以为.表示将该目录下全部文件都添加上去)
   ```
   >git add (工作区 --> 暂存区)

   >相当于把草稿整理好，放到提交的“草稿区”。
4. 提交到本地仓库
   ```git
   git commit -m"提交说明"
   ```
   >git commit (暂存区 --> 本地仓库)
   >相当于把草稿正式写进日记本，并附上说明
* 将本地仓库与远程仓库连接起来(第一次将代码提交到一个新仓库)
   ```git
   git remote add origin 仓库地址
   ```  
* 查看远程仓库详细信息
   ```git
   git remote -v
   ```
   >可以看到仓库名称，关联地址
5. 推送代码到远程仓库 
   ```git
   git push origin 分支名
   ```
   >把本地代码同步上传到远程仓库
   * 删除远程仓库分支名
   > git push origin --delete 分支名
* 克隆远程仓库 
   ```git
   git clone 仓库地址 
   ```
   >下载别人的代码到本地。
* 查看状态 
   ```git
   git status 
   ```
   >检查当前代码的变化情况。
* 查看提交历史 
   ```git
   git log 
   ```
   >查看代码的提交记录，回顾开发的“时间线”。
* 创建分支 
   ```git
   git branch 分支名 
   ```
   >为不同功能开发创建独立章节，不干扰主线内容。
   * 删除分支:
      * 由于分支合并后, 被合并的分支不会被被删除, 需要我们手动删除
      > git branch -d [分支名]
      * 若没有合并就删除分支, 则将小d变大D, 强制删除
      > git branch -D [分支名]
* 切换分支
   ```git
   git checkout 分支名 
   ```
   >从一个分支切换到另一个分支
   * 切换到已有的分支:
      > git checkout branch_name
   * 创建并切换到新的分支:
      > git checkout -b new_branch_name
      

# 第三部分：Git 常⽤命令及 SSH 配置
 SSH：安全认证和便捷连接 🔒
⽐喻：SSH 就像“为你的钥匙加上指纹认证”，确保只有你能开⻔。
SSH 允许在本地和远程仓库之间安全通信，并省去每次推送或拉取代码时输⼊密码的⿇烦。
 Git 常⽤命令速查表
Git、GitHub 和 Gitee 完整讲解：从基础到进阶功能-左岚
No. 2 / 4
功能 命令 比喻
合并分支 git merge 分支名 把不同章节的内容合并到主线。
拉取代码 git pull origin 分支名 从远程仓库拉取最新代码


* 附录：Linux指令
>>>>>>> Notes

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

### **Git**分支管理
1. 创建与合并分支:
   * 查看分支：git branch
   * 创建分支：git branch <name>
   * 切换分支：git checkout <name>或git switch <name>
   * 创建+切换分支：git checkout -b <name>或git switch -c <name>
   * 合并某分支到当前分支：git merge <name>
   * 删除分支：git branch -d <name> (-D强行删除)
   * 查看分支合并图：git log --graph
   * 使用git stash可以将当前内容“储藏”起来，然后去修复bug，修复后，再git stash pop，回到工作现场。
   * 在master分支上修复的bug，想要合并到当前dev分支，可以用git cherry-pick <commit>把bug提交的修改“复制”到当前分支，避免重复劳动。



### **Git**远程仓库操作
