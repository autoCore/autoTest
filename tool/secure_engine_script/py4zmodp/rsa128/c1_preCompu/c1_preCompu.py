# -*- coding: utf-8 -*-
# coding: utf-8
import Crypto

'''
TODO:
RSA-128
N = E827BC31A610EC69A866B34773FCEB59
E = 010001
D = 2263A0710A547F706F0FC1121DA22AC1
P = F90FB63008895B85
Q = EE9F732E06D0E6C5
DP = 852ABA6DEA528F05
DQ = D3FD17A83629F439
QP = 484C126B7D087C91
'''

### case1-Pre-Computation of R
# RSA-128
#TODO: rsa's N 
M=0xE827BC31A610EC69A866B34773FCEB59
ResultZ=pow(2,128*2)%M


''' 
output
'''

print ("*** python for ZMODP *** Pre-Computation of R(=2^(2n)) *** start ***")
print ("### Given M, compute Z = 2^(2n) mod M ###")
print ("")
print ("S1---input param start--")
print ("input data: RSA-128")
print ("")

#S1: input param
print ("M=0x")
print (" %x" %M)

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
print ("*** python for ZMODP *** Pre-Computation of R *** end ***")



