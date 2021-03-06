# -*- coding: utf-8 -*-
# coding: utf-8
import Crypto

'''
TODO:RSA-512
N = 92A9F38233A022DF1F4A680986C959D19E3946C593DB5A4B8AF4824043559E93E70C5E11CA700A21769BB90463ECA751FC369435ABB742BF9D5748BB53D4E42B
E = 010001
D = 580F7F4C701EF8912BC28B511D030CD115C5A23EC3967352E46E073EFAAF0FF527C8F3B625DBFDE156C2261E195B9BE0BF1931824BA69503B834C702EE3DDF71
P = DB73F46380B0E9580CE7F480CD026F9A8DCD610ECB2C806622E741DFEC9889A7
Q = AB16BE7EC5E9EFF8E3317DCEEA873E9F8FDD1D5FC16D0CBBE38A6E9CB4BD59DD
DP = 52752A61ECEC0C71A23FD1D647B1DF9F7222B69269732A37B66BB08BE40998C7
DQ = 14516C28140AF733C08F751868A3CD1D17F1B37656BB43A2E09FE508F931EF85
QP = C7D2F489970D8BB270D4B59B41997DE7C5092D79A83BC2A0D5BF4AE48DCB7BA4
'''

### case1-Pre-Computation of R
# RSA-512
#TODO: rsa's N 
M=0x92A9F38233A022DF1F4A680986C959D19E3946C593DB5A4B8AF4824043559E93E70C5E11CA700A21769BB90463ECA751FC369435ABB742BF9D5748BB53D4E42B

### TODO: X is random?
X=0x30CD115C5A23EC3967352E46E073EFAAF0FF527C8F3B625DBFD00F30000000000000000000000000000000000000000000000000000000000000000000000000
### TODO: Y is random?
Y=0x7fcab2488a8d6cc11304d8c29f81d90362675121e670a41b408e8b5b984000000000000000000000000000000000000000000000000000000000000000000000
ResultZ=(((X*Y)/pow(2,512))%M)

''' 
output
'''

print ("*** python for ZMODP *** Montgomery Multiplication *** start ***")
print ("### Z = X * Y * 2^(-n) mod M ###")
print ("")
print ("S1---input param start--")
print ("input data: RSA-512")
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



