import pyBlock as blk
import numpy as np

a = blk.pyBlock("R", 2, 2)
c = blk.pyBlock("R", 2, 2)
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
print a + c
#b.setElem(c)

#print a * 2.0

#print b.getElem()
#print b
#print a
#print (a.typeID(), b.typeID())

#a.setElem(c)

