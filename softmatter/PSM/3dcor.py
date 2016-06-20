import numpy as np
import matplotlib.pyplot as plt
from utilities import *
from paircorrelation import pairCorrelationFunction_3D

def getInfo(fileName):
    label = []
    tmp = []
    lineNum = 0
    with open(fileName) as fp:
	label = fp.readline()[:-1].split(" ")
	dataNum = len(label)
	dataSet = [[] for i in xrange(dataNum)]
	for line in fp:
	    line = line[:-1]
	    tmp = line.split(" ")
	    for j in xrange(dataNum):
		dataSet[j].append(tmp[j])

    return label, dataSet

filename = './PSM_NVT48.xyz'
labels, dataSet = getInfo(filename)

x = np.array(dataSet[1], dtype='float64')
y = np.array(dataSet[2], dtype='float64')
z = np.array(dataSet[3], dtype='float64')

# Particle setup
domain_size = 7.5
num_particles = 200

# Calculation setup
dr = 0.1

### Random arrangement of particles ###
#particle_radius = 0.1
rMax = domain_size / 4 
#x = np.random.uniform(low=0, high=domain_size, size=num_particles)
#y = np.random.uniform(low=0, high=domain_size, size=num_particles)
#z = np.random.uniform(low=0, high=domain_size, size=num_particles)

# Compute pair correlation
g_r, r, reference_indices = pairCorrelationFunction_3D(x, y, z, domain_size, rMax, dr)

g_r = g_r / 200.
#print g_r / 200.
#print r
# Visualize
plt.figure()
plt.plot(r, g_r, color='black')
plt.xlabel('r')
plt.ylabel('g(r)')
plt.xlim( (0, rMax) )
plt.ylim( (0, 1.05 * g_r.max()) )
plt.show()

