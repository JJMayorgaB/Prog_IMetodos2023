import matplotlib.pyplot as plt
import numpy as np

#plt.rc('text', usetex=True)
#plt.rc('font', family='serif')

diametro, presion  = np.loadtxt("datos.txt", unpack=True)

fig, ax = plt.subplots()

ax.plot(diametro, presion, color='red', label=r"Caida de presión en funcion del diametro de una tuberia")

ax.set_xlabel(r'Diametro de la tuberia D [m]')
ax.set_ylabel(r'Caida de presión P [Pa]')
ax.set_title(r'Caida de presión en una tuberia en función de su diametro')

ax.legend()
#ax.set_xscale('log')
#ax.set_yscale('log')
ax.grid(True)
ax.spines['top'].set_linewidth(2)
ax.spines['bottom'].set_linewidth(2)
ax.spines['left'].set_linewidth(2)
ax.spines['right'].set_linewidth(2)

plt.show()

fig.savefig("fig_datos.pdf",bbox_inches='tight')