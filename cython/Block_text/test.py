import pyUni10 as uni10
import numpy as np

a = uni10.pyMatrix("R", 2, 2)
c = uni10.pyMatrix("R", 2, 2)
#b = blk.pyBlock("C", 2, 2)
#c = np.array([complex(2.123, 3.123),complex(3.12,4.123),complex(2.90, 3.123),complex(3.12, 4.1290)])
d = np.array([2., 3.,11.,4.])
e = np.array([2., 3.,11.,4.])
#c = [2, 3, 4, 5]
#if c.dtype==np.dtype(complex):
#      print "haha"
#d = c.astype(np.float64, copy=True)

#print a.typeID()
a.setElem(d)
c.setElem(e)
#print a.getElem()
#d = a + c
print '================'
print a.elemNum()
print '================'
print c.elemNum()
print '================'

print '================'
print a.getElem()
print '================'
print c
print '================'

print a + c
#print c.getElem()

#b.setElem(c)

#print a * 2.0

#print b.getElem()
#print b
#print a
#print (a.typeID(), b.typeID())

#a.setElem(c)

