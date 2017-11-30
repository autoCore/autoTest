# -*- coding: utf-8 -*-
# coding: utf-8
import Crypto

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

### case1-Pre-Computation of R
# RSA-1024
#TODO: rsa's N 
M=0xE72EF44B4A54B63FE1F3C9C8F50DB509521EAC432B9A8CF93DE744A4337937E2232077A692CDCC02B83095E4B92F4AE018B130C81D03D8B6DB1989E626BA934497586D3E7755ABB0117B14956D5FDAE86F4BA0095BC0DE63A7761BC63FA1FFB8139385639233B2B7F00389944045A80166D9B2348C5090996CE5128D231E5017

### TODO: X is random?
X=0xF9D68C23F1725C79BCC257293B542C20176EA890A2143CD01C46A33302E1339DFA86ED3EC436FCDCEF16A5CCC7DE9D9AC451B009B51E35916801EC72415BF34033072352CA8B18C8EAE88F0C3C1B4D12CD39D321EB9F40A243EC23942202ED04739B81E1C94ACA9E3A58676E0E90C8C3B994E2FC1B545AC9216A51447E362311

EXP=0x10001					

Y=pow(2,1024*2)%M

print ("")
print ("...doing...,....keep waiting...")
print ("")

ResultZ=(pow(X, EXP)%M)

''' 
output
'''

print ("*** python for ZMODP *** Modular Exponentiation *** start ***")
print ("### Given M, X, r = 2^(2n) mod M and EXP. compute Z = X^(EXP) mod M ###")
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
print ("EXP=0x")
print (" %x" %EXP)

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
print ("*** python for ZMODP *** Modular Exponentiation *** end ***")



