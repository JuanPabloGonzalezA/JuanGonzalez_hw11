import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt("tray.txt")
x=datos[:,0]
v=datos[:,1]
t=datos[:,2]

#grafico 1
plt.plot(t,x)
plt.ylabel(r'$x$')
plt.xlabel(r'$t$')
plt.title(r'$x \mathrm{\ Vs\ } t$')
plt.savefig('pos.png')
plt.close()

#grtafico 2
plt.plot(t,v)
plt.ylabel(r'$v$')
plt.xlabel(r'$t$')
plt.title(r'$v \mathrm{\ Vs\ } t$')
plt.savefig('vel.png')
plt.close()


#grafico 3
plt.plot(x,v)
plt.ylabel(r'$v$')
plt.xlabel(r'$x$')
plt.title(r'$v \mathrm{\ Vs\ } x$')
plt.savefig('phase.png')
plt.close()
