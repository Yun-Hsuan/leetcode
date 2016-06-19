import numpy as np
#import matplotlib.lines as mlines
import matplotlib.pyplot as plt
import matplotlib as rc
import seaborn as sns 
sns.set_style('whitegrid',{"legend.frameon": True})

def getInfo(fileName):
    label = []
    tmp = []
    lineNum = 0
    with open(fileName) as fp:
	label = fp.readline()[:-1].split(",")
	dataNum = len(label)
	dataSet = [[] for i in xrange(dataNum)]
	for line in fp:
	    line = line[:-1]
	    tmp = line.split(",")
	    for j in xrange(dataNum):
		dataSet[j].append(tmp[j])

    return label, dataSet

def GEM(epsilon, x, n):
    return epsilon * np.exp(-(x**n));


if __name__ == '__main__':

    epsilon = 1.

    x0 = np.arange(0., 2.5, 0.001, dtype='float64')
    y0 = []
    x = np.arange(0., 2.5, 0.05, dtype='float64')

    for i in x0:
	if i <= 1.:
	    y0.append(1)
	else:
	    y0.append(0)

    y1 = GEM(epsilon, x, 2)
    y2 = GEM(epsilon, x, 4)
    y3 = GEM(epsilon, x, 10)

    #x_label = ('epoch')
    x_label = (r'$r / \sigma$')
    y_label = (r'$\Phi$')

    fig, ax = plt.subplots()
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    lin1 = ax.plot(x0, y0, '-', linewidth=2.,label="PSM")
    lin2 = ax.plot(x, y1, '-', linewidth=2.,label="GEM-2")
    lin3 = ax.plot(x, y2, '-', linewidth=2.,label="GEM-4")
    lin4 = ax.plot(x, y3, '-', linewidth=2.,label="GEM-10")
    plt.ylim(0., 1.001)
    #plt.xlim(2, 10)
    plt.legend(loc=1)
    #plt.xticks(np.arange(0., 5., 0.5))

    plt.show()
