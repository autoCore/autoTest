# -*- coding: utf-8 -*-
# coding: utf-8
import Crypto

'''
TODO:RSA-128
N = E827BC31A610EC69A866B34773FCEB59
E = 010001
D = 2263A0710A547F706F0FC1121DA22AC1
P = F90FB63008895B85
Q = EE9F732E06D0E6C5
DP = 852ABA6DEA528F05
DQ = D3FD17A83629F439
QP = 484C126B7D087C91
'''

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



### case1-Pre-Computation of R
# RSA-128
#TODO: rsa's N 
M=0xE827BC31A610EC69A866B34773FCEB59
#M=0xF6F06C2E732FB976012EFF52C1E7415D

'''
注意：
1. X/Y值不能太大，小于一半位宽，后面全为0. 这样Z算出来，最后几个数为0，此时
Aquila_EVB的HW zmodp能计算正确。 否则,Z为全满数据，则HW zmodp计算结果和本python计算结果不匹配。
2. M 似乎质素P、Q可行，非质素N也可行。
（可能是HW的输入限制!!!， 但没有HW 文档指出该限制）
'''
### TODO: X is random?
X=0x30405789123000000000000000000000

### TODO: Y is random?
Y=0x77788993200500000000000000000000
ResultZ=(((X*Y)/pow(2,128))%M)

''' 
output
'''

print ("*** python for ZMODP *** Montgomery Multiplication *** start ***")
print ("### Z = X * Y * 2^(-n) mod M ###")
print ("")
print ("S1---input param start--")
print ("input data: RSA-128")
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



