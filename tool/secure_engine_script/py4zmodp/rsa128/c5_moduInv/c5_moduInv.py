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

### case5-Modular Inverse
# RSA-128

#TODO: rsa's P 
M=0xF6F06C2E732FB976012EFF52C1E7415D

### TODO: X is random?
X=0x9F8FDD1D5FC16D0CBB68A3CD1D17F1B3

'''
[ע��] ��python��ʽ����Y�޹��ˡ� ��aquila��zmodpģ�飬������Y�й�ϵ�ģ�ע��ҪDWORD��˳��.!!!

Y=pow(2,1024*2)%M
ԭ�������Y�����:421c2b41b9f7e69cc41ae661af209b5f06dcc553959969bdcdc577a88d9d4867606fe0b87548edadb6e847d08d694f70129b3a4546fdc9b511a119e5b8935c0ea9394894720b055daa5589a03118c20e8ff4ecc5193d6b4b8e29c6cf9c68c00c0a3ffafea4d10e8a3f1ddeba0aaeefb1e03fc984c4c369e18f1920795a85702a
Ҫת��Ϊ�����������python��ʹ�ã�#Y=0x5a85702a8f192079c4c369e1e03fc9840aaeefb13f1ddebaa4d10e8a0a3ffafe9c68c00c8e29c6cf193d6b4b8ff4ecc53118c20eaa5589a0720b055da9394894b8935c0e11a119e546fdc9b5129b3a458d694f70b6e847d07548edad606fe0b88d9d4867cdc577a8959969bd06dcc553af209b5fc41ae661b9f7e69c421c2b41
'''

Y=pow(2,128*2)%M

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
print ("input data: RSA-128")
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



