import numpy as np
from scipy.integrate import quad
from scipy.integrate import romberg 
import matplotlib.pyplot as plt
import matplotlib as rc
from matplotlib.collections import LineCollection
from matplotlib.colors import ListedColormap, BoundaryNorm
import seaborn as sns
sns.set(style="whitegrid")

if __name__ == "__main__":

	taus = 2500
	tauf = 0.1
	#for w in xrange(10000):
	#	w = np.log(w)
	#	storage = lambda t: w*np.sin(w*t)*np.exp(-t/taus)/(1+(t/tauf)**(0.5))
	#	Gp = quad(storage, 0, np.inf)
	#	print np.log(Gp)
	x = []
	ystrg = []
	yloss = []
	yross = []
	mstrg = []
	mloss = []
	mross = []
	lastYstrg = 0
	lastYloss = 0
	lastYross = 0
	lastX = 0
	for T in xrange(180):
		if(T < 1):
			continue
		w1 = np.exp(T*0.1) * 0.00001
		#w1 = np.pi*T/25
		#if np.log(w1) > 7.4:
		#	continue
		#w1 = np.log(2.*np.pi/T)
		#x.append(w1)
		#storage = lambda t: w1*np.sin(w1*t)*np.exp(-t/taus)
		#ross = lambda t: w1*np.exp(-t/taus)/(t/tauf)**(0.5)
		storage = lambda t: w1 * np.exp(-t/taus)/(1.+(t/tauf)**(0.5))#np.sin(w1*t)*
		loss = lambda t: w1 * np.exp(-t/taus)/(1.+(t/tauf)**(0.5))#np.cos(w1*t)*
		ross = lambda t: w1 * np.exp(-t/taus) #np.cos(w1*t)*
		Gpstrg = quad(storage, 0.000, np.inf,weight = 'sin', wvar = w1)#np.inf)
		Gploss = quad(loss, 0.000, np.inf, weight = 'cos', wvar = w1)#,weight = w1)#np.inf)
		Gpross = quad(ross, 0, np.inf, weight= 'cos',wvar = w1)#,weight = w1)#np.inf)
		#Gpstrg = romberg(storage, 0.000, 50)#np.inf)
		#Gploss = romberg(loss, 0.000, 50)#np.inf)
		#Gpstrg = romberg(storage, 0.000, 50)#np.inf)
		#if(np.log(Gp)[0] > -11):
		bufmstrg = (np.log(Gpstrg)[0] - lastYstrg)/(np.log(w1)-lastX)
		bufmloss = (np.log(Gploss)[0] - lastYloss)/(np.log(w1)-lastX)
		bufmross = (np.log(Gpross)[0] - lastYross)/(np.log(w1)-lastX)
		mstrg.append(bufmstrg);
		mloss.append(bufmloss);
		mross.append(bufmross);
		lastX = np.log(w1)
		lastYstrg = np.log(Gpstrg)[0]
		lastYloss = np.log(Gploss)[0]
		lastYross = np.log(Gpross)[0]
		x.append(lastX)
		ystrg.append(lastYstrg)
		yloss.append(lastYloss)
		yross.append(lastYross)

		print (np.log(Gpstrg[0]),np.log(Gploss[0]),np.log(Gpross[0]))
		#print (np.log(Gpstrg[0]),np.log(Gploss[0]))

	#label, dataSet = getInfo("./T5E8LGM")

	#x_label = (r'$\lambda$')
	#y_label = ""

	extraticks = [r"$\omega \tau_s = 1$", r"$\omega \tau_F = 1$"]
	cmap = ListedColormap(['r', 'g', 'b'])
	norm = BoundaryNorm([-8, np.log(taus), np.log(tauf), 4], cmap.N)
	fig1, ax1 = plt.subplots()
	plt.title(r"$log(G)-log(w)$")
	#plt.title('Transverse Ising')
	#plt.xlabel(x_label)
	#plt.ylabel(y_label)
	ax1.plot(x, ystrg, '-', label="$log G(t)^{\prime}$ -- storage")
	ax1.plot(x, yloss, '-', label="$log G(t)^{\prime \prime}$ -- loss")
	ax1.plot(x, yross, '-', label="$log G(t)^{\prime \prime}$ -- ross")
	plt.axvline(x=np.log(1./taus), linewidth=1, ls='--', color='red')
	plt.axvline(x=np.log(1./tauf), linewidth=1, ls='--', color='yellow')
	plt.legend(loc=4)
	plt.xticks(list(plt.xticks()[0])+[np.log(1./taus), np.log(1./tauf)],list(plt.xticks()[0])+[r"$\omega \tau_s = 1$", r"$\omega \tau_F = 1$"])
	plt.xlabel(r"$log(\omega)$")
	plt.ylabel(r"$log(G)$")
	#plt.ylim(0, 1.0)
	#plt.xticks(np.arange(0., 5., 0.5))
	fig2, ax2 = plt.subplots()
	plt.title(r"Slope of $log(G)-log(w)$")
	ax2.plot(x[1:], mstrg[1:], '-', label="$log G(t)^{\prime}$ -- storage") 
	ax2.plot(x[1:], mloss[1:], '-', label="$log G(t)^{\prime \prime}$ -- loss")
	#ax2.plot(x[1:], mross[1:], '-', label="$log G(t)^{\prime \prime}$ -- ross")
	plt.axvline(x=np.log(1./taus), linewidth=1, ls='--', color='red')
	plt.axvline(x=np.log(1./tauf), linewidth=1, ls='--', color='yellow')
	plt.legend(loc=1)
	plt.xticks(list(plt.xticks()[0])+[np.log(1./taus), np.log(1./tauf)],list(plt.xticks()[0])+[r"$\omega \tau_s = 1$", r"$\omega \tau_F = 1$"])
	plt.xlabel(r"$log(\omega)$")
	plt.ylabel(r"$M(\Delta log(G)/ \Delta log(\omega))$")
	plt.show()

