# -*- coding: utf-8 -*-
# coding: utf-8
import Crypto

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m
		
		
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

### case5-Modular Inverse
# RSA-512

#TODO: rsa's P 
M=0xFFB95724AA62BEE24B44DF501F8FDE1C15F627A6F0F08A96030F5CF6F1FAACFAE8DDCA62D9FD340302D880E78F83731C641D5B65C69DC06FA8D60FA73FFF7071

### TODO: X is random?
X=0x30CD115C5A23EC3967352E46E073EFAAF0FF527C8F3B625DBFDE317DCEEA873E9F8FDD1D5FC16D0CBB68A3CD1D17F1B37656BB43A2E3317DCEEA873E9F8FDD12

'''
[注意] 新python公式，与Y无关了。 而aquila的zmodp模块，还是与Y有关系的，注意要DWORD换顺序.!!!

Y=pow(2,1024*2)%M
原来计算出Y是这给:421c2b41b9f7e69cc41ae661af209b5f06dcc553959969bdcdc577a88d9d4867606fe0b87548edadb6e847d08d694f70129b3a4546fdc9b511a119e5b8935c0ea9394894720b055daa5589a03118c20e8ff4ecc5193d6b4b8e29c6cf9c68c00c0a3ffafea4d10e8a3f1ddeba0aaeefb1e03fc984c4c369e18f1920795a85702a
要转化为这个，设置在python中使用：#Y=0x5a85702a8f192079c4c369e1e03fc9840aaeefb13f1ddebaa4d10e8a0a3ffafe9c68c00c8e29c6cf193d6b4b8ff4ecc53118c20eaa5589a0720b055da9394894b8935c0e11a119e546fdc9b5129b3a458d694f70b6e847d07548edad606fe0b88d9d4867cdc577a8959969bd06dcc553af209b5fc41ae661b9f7e69c421c2b41
'''

Y=pow(2,512*2)%M

print ("")
print ("...doing...,....keep waiting...")
print ("")
 
ResultZ=modinv(X,M) 

''' 
output
'''

print ("*** python for ZMODP *** Modular Inverse *** start ***")
print ("### Given M, X and  r = 2^(2n) mod M. compute Z = X^(-1) mod M ###")
print ("")
print ("S1---input param start--")
print ("input data: RSA-512")
print ("")

#S1: input param
print ("M=0x")
print (" %x" %M)
print ("X=0x")
print (" %x" %X)
print ("(Y is pre-compu M result). Y=0x")
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
print ("*** python for ZMODP *** Modular Inverse *** end ***")



