import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

t, xe, ve  = np.loadtxt("euler_solution.txt", unpack=True)
t, xh, vh  = np.loadtxt("heun_solution.txt", unpack=True)

fig, ax = plt.subplots()

ax.plot(xh, vh, color='red', marker='.',  linestyle='', label=r"$v(x)$ con el metodo de Heun")
ax.plot(xe, ve, color='blue', linestyle='--', label=r"$v(x)$ con el metodo de Euler")

ax.set_xlabel(r"\boldmath{$x$} \boldmath{$[m]$}", fontsize=16)
ax.set_ylabel(r'\boldmath{$v(x)$ \boldmath{$[m/s]$}', fontsize=16)
ax.set_title(r'\textbf{Soluciones númericas de la E.D.O.} \boldmath{$\ddot{x}=-kx$} \textbf{usando el metodo de Euler y el metodo de Heun}', x=0.5, y=1, fontsize=15)

ax.legend(framealpha=1, shadow=True, fontsize=14, edgecolor="k",borderaxespad=1, borderpad=0.75)
#ax.set_xscale('log')
#ax.set_yscale('log')
ax.grid(True, which='minor', linestyle="-.", alpha=0.5)
ax.grid(True, linestyle="-", alpha=1)
ax.minorticks_on()
ax.tick_params(which="both", width="1.5")
ax.tick_params(which="minor", length=4, direction="in")
ax.tick_params(which="major", length=12, direction="inout")
#ax.set_xlim(1, 800 )
#ax.set_ylim(0, 2.6)
#ax.set_xticks([0.000, 0.005, 0.010, 0.015, 0.020, 0.025, 0.030])
#ax.set_xticklabels(["0", "0.005", "0.010", "0.015", "0.020", "0.025", "0.030"])
ax.spines['top'].set_linewidth(1.5)
ax.spines['bottom'].set_linewidth(1.5)
ax.spines['left'].set_linewidth(1.5)
ax.spines['right'].set_linewidth(1.5)

plt.show()

fig.savefig("stats.pdf",bbox_inches='tight')