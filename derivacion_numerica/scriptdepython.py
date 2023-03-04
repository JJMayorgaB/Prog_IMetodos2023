import matplotlib.pyplot as plt
import numpy as np

h, forward, central, forward_richardson, central_richardson  = np.loadtxt("datos.txt", unpack=True)

fig, ax = plt.subplots()

ax.plot(h, forward, color='red', label='Diferencia porcentual con la derivada forward')
ax.plot(h, central, color='blue', label='Diferencia porcentual con la derivada central')
ax.plot(h, forward_richardson, color='green', label="Diferencia porcentual con la interpolación de Richardson para la derivada forward")
ax.plot(h, central_richardson, color='yellow', label="Diferencia porcentual con la interpolación de Richardson para la derivada central")

ax.set_xlabel('Diferencia relativa, h')
ax.set_ylabel('Diferencia porcentual')
ax.set_title('Diferencias porcentuales entre la derivada de sin(x) y distintas aproximaciones de esta en escala logaritmica')

ax.legend()
ax.set_xscale('log')
ax.set_yscale('log')

plt.show()

fig.savefig("fig_datos.pdf",bbox_inches='tight')





