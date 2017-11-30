#!/usr/bin/python

inbuf="27c5494024cbd901fdc5432599c2addce724eb4e081281b27fea99a0e4a16a9a392916ad2947b9440bcd2ae484710f91bb38c7133f1c721cbb52161a94b158acadde3391a709ce87794430113125690ba566fc674af4199669a71db1300a85a462ca1d6a618d3af91f4db91c953e2cf6d51d42b3f39f1feea770273f926d27ab44e6d6dbbdb7cda5a4349a69892eb345513f667da509fc0a07fe537f8f40e6b4c19a67b964f3e33fcdd141d38b4cad2602b0e3efe7f92fcd08663ceaee61310fa0ead5caa4485f87698a67e3bfdb869b4619a96d449be52f9cad5eaf36ef4c0dd87f32734808764e6469b3ecd701ff99c1bbef9d8d58aff02903b8c0442875e7"
outbuf=""

if __name__ == '__main__':
  l = len(inbuf)
  while l > 8:
    if l % 32 == 0:
      outbuf += '\n'
    outbuf += inbuf[l-8:l]
    l -= 8
  if l > 0:
    outbuf += inbuf[0:l]
print ("*** python util *** Reverse hex string per DWORD *** start ***")
print ("")

print ("S1---input param start--")
print ("original input data=")
print (inbuf)
print ("")

print ("")
print ("S2......running......")
print ("        .............done")
print ("")

print ("")
print ("S3---output result start--")
print ("")
print outbuf
print ("")
print ("---output result end--")

