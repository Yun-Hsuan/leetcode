import random
import math
import numpy as np

#A pratice of Ising model in Object-oriented code.
class spin:
    def __init__(self,S=1.0):
        self.S=S
    def __repr__(self):
        return str(self.S)
    def flip(self):
        self.S=-self.S
#    def __str__(self):
#        return str(self.S)

class lattice:
    def __init__(self,L=4,J=-1.0,T=2.5):
        self.conf=[]
        self.L=L
        self.N=L*L
        self.T=T
        self.J=J
        self.forder=range(self.L*self.L)
        for i in range(L):
            temp=[]
            for j in range(L):
                temp.append(spin())
            self.conf.append(temp)
    def __str__(self):
        return str(self.conf)
    def spinH(self,i,j):
        ib=(i-1+self.L)%self.L
        it=(i+1+self.L)%self.L
        jb=(j-1+self.L)%self.L
        jt=(j+1+self.L)%self.L
        return (self.conf[i][j].S)*self.J*(self.conf[ib][j].S+self.conf[i][jb].S+self.conf[it][j].S+self.conf[it][j].S)
    def Ecal(self):
        self.E=0.0
        for i in range(self.L):
            for j in range(self.L):
                self.E+=self.spinH(i,j)
        self.E=self.E/2
    def spinUpdate(self,i,j):
        if(self.spinH(i,j)>0):
            self.conf[i][j].flip()
        elif(random.random() <math.exp(2.0*self.spinH(i,j)/self.T)):
            self.conf[i][j].flip()
    def Mcal(self):
        self.M=0.0
        for i in range(self.L):
            for j in range(self.L):
                self.M+=self.conf[i][j].S
    def view(self):
        for i in range(self.L):
            for j in range(self.L):
                if(self.conf[i][j].S>0):
                    print 1,
                else:
                    print 0,
            print '|'

    def MCstep(self,t):
        for j in range(t):
            random.shuffle(self.forder)
            for i in self.forder:
                self.spinUpdate(i%self.L,i/self.L)
                   # print random.random()

class Measurement:
    def __init__(self,lattice,BinS,Nst,Nbin):
        self.Ms=[]
        self.Es=[]
        self.M2s=[]
        self.E2s=[]
        self.M4s=[]
        self.BinNum=Nbin
        for k in range(Nbin):
            Mi =0.0
            Ei =0.0
            Mi2=0.0
            Ei2=0.0
            Mi4=0.0
            for i in range(BinS):
                lattice.MCstep(Nst)
                lattice.Ecal()
                lattice.Mcal()
                Mi +=abs(lattice.M)
                Ei +=lattice.E
                Mi2+=lattice.M*lattice.M
                Ei2+=lattice.E*lattice.E
                Mi2+=lattice.M*lattice.M

            self.Ms.append(Mi/BinS/lattice.N)
            self.Es.append(Ei/BinS/lattice.N)
            self.M2s.append(Mi2/BinS/lattice.N/lattice.N)
            self.E2s.append(Ei2/BinS/lattice.N/lattice.N)
            self.M4s.append(Mi4/BinS/lattice.N/lattice.N/lattice.N/lattice.N)
        self.Ms=np.array(self.Ms)
        self.Es=np.array(self.Es)
        self.M2s=lattice.N*np.array(self.M2s)
        self.E2s=lattice.N*np.array(self.E2s)
        self.Xs=(self.M2s-self.Ms**2)/(lattice.T)
        self.Cs=(self.E2s-self.Es**2)/((lattice.T)**2)
        self.M4s=np.array(self.M4s)
        self.M=self.Ms.mean()
        self.E=self.Es.mean()
        self.X=self.Xs.mean()
        self.C=self.Cs.mean()
        self.Merr=self.Ms.std()/np.sqrt(Nbin-1)
        self.Eerr=self.Es.std()/np.sqrt(Nbin-1)
        self.Xerr=self.Xs.std()/np.sqrt(Nbin-1)
        self.Cerr=self.Cs.std()/np.sqrt(Nbin-1)


a=lattice(16)
a.Ecal();
a.view()
print a.E
for T in range(320,250,-10)+range(250,150,-5)+range(150,100,-10)+range(100,50,-10):
    a.T=T/100.0
    a.MCstep(200)
    M1=Measurement(a,100,1,100)
    print a.T,M1.E,M1.M,M1.C
a.view()
