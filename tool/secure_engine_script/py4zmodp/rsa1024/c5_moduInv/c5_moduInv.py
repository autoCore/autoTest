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
TODO:RSA-1024
N = E72EF44B4A54B63FE1F3C9C8F50DB509521EAC432B9A8CF93DE744A4337937E2232077A692CDCC02B83095E4B92F4AE018B130C81D03D8B6DB1989E626BA934497586D3E7755ABB0117B14956D5FDAE86F4BA0095BC0DE63A7761BC63FA1FFB8139385639233B2B7F00389944045A80166D9B2348C5090996CE5128D231E5017
E = 010001
D = D1DB22B191C8F2236D55E2CF43FBEC6188A505547829745CF01F9684C3A0FEE48D647498C5DC809BDB5D6743D802A12269E7B6D380DB3407513E8E9A587FB71BAB5A3213B367F8415A7C75B2F313BE8F5D3196C09FE454F942D9527D1A75E1583DCFB26F8F979E726BAD36E760ED79709F20DE8B82F4CEE3E0F37E53E1DDF3E1
P = FFB95724AA62BEE24B44DF501F8FDE1C15F627A6F0F08A96030F5CF6F1FAACFAE8DDCA62D9FD340302D880E78F83731C641D5B65C69DC06FA8D60FA73FFF7071
Q = E76ED5409F2908D89FA9126563AD9D85702410D617A35116F92AC1F76AEFCF9B9C2AE68623A98C76BC890457D0BFC092210FF5B12C424813A18A92472F748D07
DP = 7EE47121788AD73D632C21C39865C3491C7CB0E05DDE7E6641CE75CAF3F7F7ADE9AF64A5F8957421AA5FD45713179F1F0F6EA1D3B6E2C082A7BCD0B7A5421381
DQ = 55213CCA4F817DA289605CC6F4DA8925EB7128CC47D7A85D65FC276B4667BE1B445FB77A4225FCE83443C658330E45DCBAD2AF12A3F021A92EF3D508E058E403
QP = 819D3DB6953795F7629DB093F18550B4BFAA94A2F834CA3A9E87B4CDDD9216E3E90BB3DB06063A5232A5A84680FCBE512A5E0486903F6C70C5C9E5A8961B02EA
'''

### case5-Modular Inverse
# RSA-1024

#TODO: rsa's P 
M=0xF9D68C23F1725C79BCC257293B542C20176EA890A2143CD01C46A33302E1339DFA86ED3EC436FCDCEF16A5CCC7DE9D9AC451B009B51E35916801EC72415BF34033072352CA8B18C8EAE88F0C3C1B4D12CD39D321EB9F40A243EC23942202ED04739B81E1C94ACA9E3A58676E0E90C8C3B994E2FC1B545AC9216A51447E362311

### TODO: X is random?
X=0x819D3DB6953795F7629DB093F18550B4BFAA94A2F834CA3A9E87B4CDDD9216E3E90BB3DB06063A5232A5A84680FCBE512A5E0486903F6C70C5C9E5A8961B02EA55213CCA4F817DA289605CC6F4DA8925EB7128CC47D7A85D65FC276B4667BE1B445FB77A4225FCE83443C658330E45DCBAD2AF12A3F021A92EF3D508E058E403

#old-rsa1024
#Y=pow(2,1024*2)%M
#Y=0x5a85702a8f192079c4c369e1e03fc9840aaeefb13f1ddebaa4d10e8a0a3ffafe9c68c00c8e29c6cf193d6b4b8ff4ecc53118c20eaa5589a0720b055da9394894b8935c0e11a119e546fdc9b5129b3a458d694f70b6e847d07548edad606fe0b88d9d4867cdc577a8959969bd06dcc553af209b5fc41ae661b9f7e69c421c2b41

'''
[注意] 新python公式，与Y无关了。 而aquila的zmodp模块，还是与Y有关系的，注意要DWORD换顺序.!!!

Y=pow(2,1024*2)%M
原来计算出Y是这给:421c2b41b9f7e69cc41ae661af209b5f06dcc553959969bdcdc577a88d9d4867606fe0b87548edadb6e847d08d694f70129b3a4546fdc9b511a119e5b8935c0ea9394894720b055daa5589a03118c20e8ff4ecc5193d6b4b8e29c6cf9c68c00c0a3ffafea4d10e8a3f1ddeba0aaeefb1e03fc984c4c369e18f1920795a85702a
要转化为这个，设置在python中使用：#Y=0x5a85702a8f192079c4c369e1e03fc9840aaeefb13f1ddebaa4d10e8a0a3ffafe9c68c00c8e29c6cf193d6b4b8ff4ecc53118c20eaa5589a0720b055da9394894b8935c0e11a119e546fdc9b5129b3a458d694f70b6e847d07548edad606fe0b88d9d4867cdc577a8959969bd06dcc553af209b5fc41ae661b9f7e69c421c2b41
'''

Y=pow(2,1024*2)%M

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
print ("input data: RSA-1024")
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



