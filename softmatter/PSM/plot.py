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


if __name__ == '__main__':

    label, dataSet = getInfo("tmp2") #T, E, M

    #x_label = ('epoch')
    x_label = (r'Temperature')
    y_label = "M"

    dataSet[1] = np.array(dataSet[1],dtype = 'float64');
    dataSet[1] = dataSet[1] * (1./200.)
    fig, ax = plt.subplots()
    plt.title('2D Classical Ising')
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    lin1 = ax.plot(dataSet[0], dataSet[1], 'b-', linewidth=2.5,label="M")
    #plt.ylim(0, 600)
    #plt.xlim(2, 10)
    plt.legend(loc=1)
    #plt.xticks(np.arange(0., 5., 0.5))

    #ax2 = ax.twinx()
    #lin2 = ax2.plot(dataSet[0], dataSet[1], 'r--',label="Energy")
    #plt.legend(loc=1)
    #plt.ylabel('E')
    #plt.xlim(0, 2000)
    #plt.legend([line1,line2,line3,line4,line5,line6], ['2D-iTEBD',"2D-iTEBD + QR","Hasting","Hasting + QR","4PESS","Monte Carlo"])

    plt.show()
