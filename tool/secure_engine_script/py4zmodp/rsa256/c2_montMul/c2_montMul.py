# -*- coding: utf-8 -*-
# coding: utf-8
import Crypto

'''
TODO:RSA-256
N = D472519ADB53ABA61FF000C7D62AB872620FE43720ED056F3B60881CE5AEE629
E = 010001
D = 872093A151021E3AD3339FFB7BD0BE71F19FAECE979E6BBE6C8CDFC8091EB0D1
P = F6F06C2E732FB976012EFF52C1E7415D
Q = DC3DE5785B05B02B76199B15C8616F3D
DP = 7192B64ECECF7E5F15C045D20C388E49
DQ = 508D8AFA64404658FF0F0A7C03182FF9
QP = 06DBB5C467386C5A4C6B9817AFFE9FBD
'''

'''
ע�⣺20170918
1. X/Yֵ����̫��С��һ��λ������ȫΪ0. ����Z���������󼸸���Ϊ0����ʱ
Aquila_EVB��HW zmodp�ܼ�����ȷ�� ����,ZΪȫ�����ݣ���HW zmodp�������ͱ�python��������ƥ�䡣
2. M �ƺ�����P��Q���У�������NҲ���С�
��������HW����������!!!�� ��û��HW �ĵ�ָ�������ƣ�
'''

### case1-Pre-Computation of R
# RSA-256
#TODO: rsa's N 
M=0xD472519ADB53ABA61FF000C7D62AB872620FE43720ED056F3B60881CE5AEE629

### TODO: X is random?
X=0x3040578912354566767886860000000000000000000000000000000000000000

### TODO: Y is random?
Y=0x7778899320052323234234200000000000000000000000000000000000000000
ResultZ=(((X*Y)/pow(2,256))%M)

''' 
output
'''

print ("*** python for ZMODP *** Montgomery Multiplication *** start ***")
print ("### Z = X * Y * 2^(-n) mod M ###")
print ("")
print ("S1---input param start--")
print ("input data: RSA-256")
print ("")

#S1: input param
print ("M=0x")
print (" %x" %M)
print ("X=0x")
print (" %x" %X)
print ("Y=0x")
print (" %x" %Y)

print ("")
print ("---input param end--")
print ("")
print ("")
print ("S2......running......")
print ("        .............done")
print ("")
print ("")
print ("S3---output result start--")
print ("")

#S3: result 
print ("ResultZ=0x")
print (" %x" %ResultZ)

print ("")
print ("---output result end--")
print ("")
print ("*** python for ZMODP *** Montgomery Multiplication *** end ***")



