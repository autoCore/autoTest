
get_last_pc_xxx.cmm 可以通过 DAP 寄存器获取 core 的 PC 值，当系统死机后，我们可以通过该脚本 dump 出所有 core 的 PC 值，具体的方法如下：

1 执行 connect_a53.cmm （如果想获取 artemis 的 PC 值，则执行 connect_artemis.cmm）使得 T32 和 SoC 处于连接状态，如果 T32 已经和 SoC 处于连接状态，也需要执行该脚本

2 需要注意，如果此时系统没有挂死（例如只是处于死循环的状态，用 T32 可以 break 住），则需要在执行完步骤1的脚本后，执行命令 sys.attach

3 在执行完上面两个步骤后，执行脚本 get_last_pc_a53.cmm 会打印出 8 个 a53 core 的 PC 值，执行 get_last_pc_artemis.cmm 则打印出 2 个 artemis core 的 PC 值


例子：
  系统挂死，需要查看所有 core 的 PC 值，步骤如下：

  a. B:DO ./connect_a53.cmm
  b. B:DO ./get_last_pc_a53.cmm		//打印所有 a53 core 的 PC 值
  c. B:DO ./connect_artemis.cmm
  d. B:DO ./get_last_pc_a53.cmm         //打印所有 artemis core 的 PC 值


注意：
  打印出来的 PC 可能为 0 或者 空，这说明该 core 没有上电，所以从该 core 的 DAP 中无法读取 PC 的 value
