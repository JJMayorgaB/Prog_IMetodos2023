import matplotlib.pyplot as plt
import numpy as np

n, diferencia  = np.loadtxt("datos.txt", unpack=True)

fig, ax = plt.subplots()

ax.plot(n, diferencia, color='red', label='Diferencia relativa de la aproximación de Herón')

ax.set_xlabel('Iteración, n')
ax.set_ylabel('Diferencia relativa')
ax.set_title('Diferencia relativa de la raiz con la aproximación de Herón para x=3141.5926')

ax.legend()
ax.set_xscale('log')
ax.set_yscale('log')

plt.show()

fig.savefig("fig_datos.pdf",bbox_inches='tight')
