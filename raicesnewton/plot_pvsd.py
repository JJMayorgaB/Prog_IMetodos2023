import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

diametro, presion  = np.loadtxt("datos.txt", unpack=True)

fig, ax = plt.subplots()

ax.plot(diametro, presion, color='red', label=r"$\Delta P$ vs. $D$")

ax.set_xlabel(r'\textbf{Diámetro de la tuberia} \boldmath{$D$} \boldmath{$[m]$}', fontsize=16)
ax.set_ylabel(r'\textbf{Caída de presión} \boldmath{$\Delta P$} \boldmath{$[Pa]$}', fontsize=16)
ax.set_title(r'\textbf{Dependencia entre la caída de presión de una tuberia y su diámetro}', x=0.5, y=1, fontsize=18)

ax.legend(framealpha=1, shadow=True, fontsize=14, edgecolor="k",borderaxespad=1, borderpad=0.75)
#ax.set_xscale('log')
#ax.set_yscale('log')
ax.grid(True, which='minor', linestyle="-.", alpha=0.5)
ax.grid(True, linestyle="-", alpha=1)
ax.minorticks_on()
ax.tick_params(which="both", width="1.5")
ax.tick_params(which="minor", length=4, direction="in")
ax.tick_params(which="major", length=12, direction="inout")
ax.set_xlim(0, 0.031)
ax.set_ylim(0, 11500)
ax.set_xticks([0.000, 0.005, 0.010, 0.015, 0.020, 0.025, 0.030])
ax.set_xticklabels(["0", "0.005", "0.010", "0.015", "0.020", "0.025", "0.030"])
ax.spines['top'].set_linewidth(1.5)
ax.spines['bottom'].set_linewidth(1.5)
ax.spines['left'].set_linewidth(1.5)
ax.spines['right'].set_linewidth(1.5)

plt.show()

fig.savefig("fig_datos.pdf",bbox_inches='tight')